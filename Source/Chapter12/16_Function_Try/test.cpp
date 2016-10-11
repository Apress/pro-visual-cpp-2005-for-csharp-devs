using namespace System;
ref class MyException : Exception
{
    public:
    MyException(String ^message) : Exception(message)
    {
    }
};
ref class Base
{
    public:
    Base(int i)
    {
        throw gcnew Exception("throwing in Base's constructor");
    }
};
ref class Derived : Base
{
    Derived(int i)
    try
    : Base(i)
    {
    }
    catch(Exception ^e)
    {
        Console::WriteLine("caught {0}", e);
        throw gcnew MyException("caught");
    }
public:
    static void Main()
    {
        try
        {
            Derived ^r = gcnew Derived(3);
        }
        catch(Exception ^e)
        {
            Console::WriteLine("caught {0}", e);
        }
    }
};
void main() {Derived::Main();}
