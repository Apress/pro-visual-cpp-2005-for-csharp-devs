using namespace System;
ref struct Base
{
    virtual String ^GetProp()
    {
        return "Base";
    }
};
ref struct Derived : Base
{
    property String ^ Prop
    {
        virtual String ^ get() = Base::GetProp
        {
            return "Derived";
        }
    }
};
void main()
{
    Derived ^d = gcnew Derived();
    Base ^b = d;
    Console::WriteLine(b->GetProp());
}
