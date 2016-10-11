using namespace System;
using namespace System::Threading;
ref struct Locker
{
    Object ^o;
    Locker(Object ^s)
    {
        o = s;
        Console::WriteLine("Lock acquired");
        Monitor::Enter(o);
    }
    ~Locker()
    {
        Console::WriteLine("Lock released");
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
            Console::WriteLine("throw exception");
            throw;
        }
    }
};
void main()
{
    try
    {
        Program::Main();
    }
    catch (Exception ^e)
    {
        Console::WriteLine("catch exception");
    }
}
