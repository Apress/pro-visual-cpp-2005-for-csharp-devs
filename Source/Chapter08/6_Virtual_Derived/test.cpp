using namespace System;
ref struct Base
{
    virtual void Method()
    {
        Console::WriteLine("Base::Method");
    }
};
ref struct Derived : Base
{
    virtual void Method() override
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
}
