using namespace System;
ref struct Base
{
    property int Prop
    {
        virtual int get()
        {
            return 1;
        }
    }
    void Test()
    {
        Console::WriteLine(Prop);
    }
};
ref struct Derived : Base
{
    int value;
    property int Prop
    {
        virtual int get() override
        {
            return 3;
        }
    }
};
void main()
{
    Derived ^d = gcnew Derived();
    Base ^b = gcnew Base();
    b->Test();
    Console::WriteLine(d->Prop);
    d->Test();
}
