#include <iostream>
#include <deque>
using namespace std;
enum REQUEST
{
    READ, WRITE
};
struct Task;
deque<Task*> t;
struct Requestor
{
    void ReadDone(bool success)
    {
        cout << "Read Done notification" << endl;
    }
    void WriteDone(bool success)
    {
        cout << "Write Done notification" << endl;
    }
    void SetupRequests();
};
struct Task
{
    enum REQUEST request;
    Requestor *pCallBackInstance;
    void (Requestor::*Notify)(bool);
};
void Requestor::SetupRequests()
{
    Task *readTask = new Task();
    readTask->Notify = &Requestor::ReadDone;
    readTask->pCallBackInstance = this;
    readTask->request = READ;
    t.push_front(readTask);
    Task *writeTask = new Task();
    writeTask->Notify = &Requestor::WriteDone;
    writeTask->pCallBackInstance = this;
    writeTask->request = WRITE;
    t.push_front(writeTask);
}
int main()
{
    Requestor *r = new Requestor();
    r->SetupRequests();
    while (!t.empty())
    {
        Task *pTask = t.back();
        t.pop_back();
        switch (pTask->request)
        {
        case READ:
            cout << "reading " << endl;
            break;
        case WRITE:
            cout << "writing " << endl;
            break;
        }
        ((pTask->pCallBackInstance)->*pTask->Notify)(true);
        delete pTask;
    }
    delete r;
}
