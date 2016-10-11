#include <deque>
#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <process.h>
using namespace std;
namespace CarWashBusiness
{
    CRITICAL_SECTION IOcs;
    class Lock
    {
        CRITICAL_SECTION *pCS_;
    public:
        Lock(CRITICAL_SECTION *pCS) : pCS_(pCS)
        {
            EnterCriticalSection( pCS_ );
        }
        ~Lock()
        {
            LeaveCriticalSection( pCS_ );
        }
    };
    struct Car
    {
        string Name_;
        Car(string Name) : Name_(Name)
        {
        }
    };
    struct Process
    {
        bool open;
        CRITICAL_SECTION cs;
        deque<Car*> Queue;
        HANDLE hThread;
        unsigned int nThreadId;
        static unsigned int WINAPI Proc( void *param )
        {
            return((Process *)param) -> Run();
        }
        virtual unsigned int Run() = 0;
        Process() : open(false)
        {
            InitializeCriticalSection(&cs);
        }
        void Open()
        {
            open=true;
        }
        void Close()
        {
            open=false;
        }
        size_t Count()
        {
            Lock l(&cs);
            return Queue.size();
        }
        void AddQueue(Car *pCar)
        {
            Lock l(&cs);
            Queue.push_back(pCar);
        }
        Car *GetNext()
        {
            Lock l(&cs);
            if (Queue.empty())
            {
                return NULL;
            }
            Car *pCar = Queue.front();
            Queue.pop_front();
            return pCar;
        }
        void Done(Car *pCar)
        {
            if (pNextProcess)
            {
                pNextProcess->AddQueue(pCar);
            }
        }
        Process *pNextProcess;
        virtual void DoStage()
        {
            while (!open)
            {
                ;
            }
            for (;open;)
            {
                Car *pCar = GetNext();
                if (!pCar)
                {
                    Sleep(30);
                    continue;
                }
                Doit(pCar);
                Done(pCar);
            }
        }
        virtual void Doit(Car *pCar) = 0;
    };
    struct Vacuum : Process
    {
        virtual unsigned int Run()
        {
            {
                Lock io(&IOcs);
                cout << "vacuum running" << endl;
            }
            DoStage();
            return 1;
        }
        virtual void Doit(Car *pCar)
        {
            Lock io(&IOcs);
            cout << "vacuuming " << pCar->Name_ << endl;
            Sleep(1000);
            cout << "vacuuming done " << pCar->Name_ << endl;
        }
    };
    struct Wash : Process
    {
        virtual unsigned int Run()
        {
            {
                Lock io(&IOcs);
                cout << "wash running" << endl;
            }
            DoStage();
            return 1;
        }
        virtual void Doit(Car *pCar)
        {
            Lock io(&IOcs);
            cout << "washing: " << pCar->Name_ << endl;
            Sleep(1200);
            cout << "washing done: " << pCar->Name_ << endl;
        }
    };
    struct Done : Process
    {
        virtual unsigned int Run()
        {
            return 1;
        }
        virtual void Doit(Car *pCar)
        {
        }
    };
    struct CarWash
    {
        size_t Countin;
        bool open;
        string Name_;
        Vacuum v;
        Wash w;
        Done d;
        CarWash(string Name) : Name_(Name), open(false)
        {
            Countin = 0;
            {
                Lock io(&IOcs);
                cout << Name_ << " Car Wash" << endl;
            }
            v.pNextProcess = &w;
            w.pNextProcess = &d;
            d.pNextProcess = NULL;
        }
        void Open()
        {
            open = true;
            v.Open();
            w.Open();
            v.hThread=(HANDLE)_beginthreadex
                      (NULL,0,Process::Proc,&v,0,&v.nThreadId);
            w.hThread=(HANDLE)_beginthreadex
                      (NULL,0,Process::Proc,&w,0,&w.nThreadId);
        }
        void Close()
        {
            open = false;
            size_t Count;
            do
            {
                Sleep(30);
                Count = d.Count();
            }
            while (d.Count() != Countin);
            v.Close();
            w.Close();
            WaitForSingleObject(v.hThread, INFINITE);
            WaitForSingleObject(w.hThread, INFINITE);
        }
        ~CarWash()
        {
        }
        void Clean(Car *pCar)
        {
            {
                Lock io(&IOcs);
                cout << "Cleaning: " << pCar->Name_ << endl;
            }
            Countin++;
            v.AddQueue(pCar);
        }
    };
}
using namespace CarWashBusiness;
int main()
{
    InitializeCriticalSection(&IOcs);
    Car Volvo("Volvo");
    Car VW("VW");
    Car Audi("Audi");
    CarWash PicoAndSep("Pico and Sepulveda");
    PicoAndSep.Open();
    PicoAndSep.Clean(&Volvo);
    PicoAndSep.Clean(&VW);
    PicoAndSep.Clean(&Audi);
    PicoAndSep.Close();
    return 0;
}
