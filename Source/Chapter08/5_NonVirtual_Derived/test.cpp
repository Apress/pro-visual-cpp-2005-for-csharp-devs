using namespace System;
ref struct Base
{
    void Method()
    {
        Console::WriteLine("Base::Method");
    }
};
ref struct Derived : Base
{
    void Method()
    {
        Console::WriteLine("Derived::Method");
    }
    void MethodBase()
    {
        Base::Method();
    }
};
void main()
{
    Derived ^d = gcnew Derived();
    Console::Write("from the Derived class: ");
    d->Method();
    Console::Write("from the Derived class: ");
    d->MethodBase();
    Base ^b = d;
    Console::Write("from the Base class: ");
    b->Method();
    Console::Write("from the Base class: ");
    d->Base::Method();
}
