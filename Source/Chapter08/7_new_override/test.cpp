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
    virtual void Method() new
    {
        Console::WriteLine("Derived::Method");
    }
};
ref struct Derived2 : Derived
{
    virtual void Method() override
    {
        Console::WriteLine("Derived2::Method");
    }
};
void main()
{
    Derived2 ^d2 = gcnew Derived2();
    d2->Method();
    Derived ^d = d2;
    d->Method();
    Base ^b = d;
    b->Method();
}
