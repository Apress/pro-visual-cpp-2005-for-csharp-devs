using namespace System;
ref struct Base
{
    property String^ Prop
    {
        virtual String^ get()
        {
            return "Base";
        }
    }
};
ref struct Derived : Base
{
    virtual String ^ GetProp() = Base::Prop::get
    {
        return "Derived";
    }
};
void main()
{
    Derived ^d = gcnew Derived();
    Base ^b = d;
    Console::WriteLine(b->Prop);
}
