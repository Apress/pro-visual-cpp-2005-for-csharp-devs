using namespace System;
using namespace System::Threading;
ref struct Locker
{
    Object ^o;
    Locker(Object ^s)
    {
        o = s;
        Monitor::Enter(o);
    }
    ~Locker()
    {
        Monitor::Exit(o);
    }
};
ref class Program
{
public:
    static void Main()
    {
        String ^s = "hello";
        {
            Locker lk(s);
//inside the lock
        }
    }
};
