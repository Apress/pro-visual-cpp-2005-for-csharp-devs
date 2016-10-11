using namespace System;
using namespace System::Threading;
ref class Program
{
public:
    static void Main()
    {
        String ^s = "hello";
        Monitor::Enter(s);
        try
        {
//inside the lock
        }
        finally
        {
            Monitor::Exit(s);
        }
    }
};
