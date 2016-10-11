using namespace System;
ref struct Base
{
    public:
    void f(int i)
    {
        Console::WriteLine("Base.f()");
    }
};
ref struct Derived : Base
{
    void f(wchar_t c)
    {
        Console::WriteLine("Derived.f()");
    }
    static void Main()
    {
        Derived ^d = gcnew Derived();
        d->f(3);
    }
};
void main() { Derived::Main();}
