using namespace System;
ref struct R
{
    virtual property String^ P
    {
        String^ get()
        {
            return "Property P";
        }
    }
};
ref struct R1 : R
{
};
generic <typename T>
where T : R
void Function(T t)
{
    Console::WriteLine(T::typeid);
    Console::WriteLine(t->P);
}
int main()
{
    R1 ^r = gcnew R1();
    Function(r);
}
