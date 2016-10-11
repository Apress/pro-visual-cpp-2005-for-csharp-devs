#using <System.dll>
#include <msclr\lock.h>
using namespace msclr;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;
namespace CarWash
{
    ref class Car
    {
    private:
        String ^CarName;
    public:
        virtual String ^ ToString() override
        {
            return CarName;
        }
        Car(String ^s)
        {
            CarName = s;
        }
    };
    ref class Program
    {
        static Queue<Car^> ^washQueue = gcnew Queue<Car^>();
        static Queue<Car^> ^vacuumQueue = gcnew Queue<Car^>();
        static Thread ^washThread =
        gcnew Thread(gcnew ThreadStart(wash));
        static Thread ^vacuumThread =
        gcnew Thread(gcnew ThreadStart(vacuum));
        static void wash()
        {
            for (; true; Thread::Sleep(10))
            {
                Car ^c;
                {
                    lock l(washQueue);
                    if (washQueue->Count == 0)
                    {
                        continue;
                    }
                    c = washQueue->Dequeue();
                }
                if (c == nullptr)
                {
                    break;
                }
                Console::WriteLine("-Starting wash of {0}", c);
                Thread::Sleep(1300);
                Console::WriteLine("-Completing wash of {0}", c);
            }
        }
        static void vacuum()
        {
            for (;true;Thread::Sleep(10))
            {
                Car ^c;
                {
                    lock l(vacuumQueue);
                    if (vacuumQueue->Count == 0)
                    {
                        continue;
                    }
                    c = vacuumQueue->Dequeue();
                }
                if (c != nullptr)
                {
                    Console::WriteLine("+Starting vacuum of {0}", c);
                    Thread::Sleep(1000);
                    Console::WriteLine(
                                      "+Completing vacuum of {0}", c);
                }
                {
                    lock l(washQueue);
                    washQueue->Enqueue(c);
                    CHAPTER 14 Å° GENERICS 245
                }
                if (c == nullptr)
                {
                    break;
                }
            }
        }
    public:
        static void Main(...array<String^> ^ args)
        {
            vacuumThread->Start();
            washThread->Start();
            {
                lock l(vacuumQueue);
                vacuumQueue->Enqueue(gcnew Car("Volvo"));
                vacuumQueue->Enqueue(gcnew Car("VW"));
                vacuumQueue->Enqueue(gcnew Car("Jeep"));
                vacuumQueue->Enqueue(nullptr);
            }
            while (vacuumThread->IsAlive || washThread->IsAlive)
            {
                Thread::Sleep(10);
            }
        }
    };
}
void main()
{
    CarWash::Program::Main();
}
