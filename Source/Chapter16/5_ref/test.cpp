using namespace System;
interface class I
{
    virtual property int P;
};
ref struct R : I
{
    virtual property int P;
};
value struct V : I
{
    virtual property int P;
};
generic <typename T>
where T : I
void ChangePropertyData(T t)
{
    t->P = 2;
}
int main()
{
    R ^ r = gcnew R();
    Console::WriteLine("changing R...");
    ChangePropertyData(r);
    Console::WriteLine("r->P == {0}", r->P);
    V v = V();
    Console::WriteLine("changing V...");
    ChangePropertyData(v);
    Console::WriteLine("v.P == {0}", v.P);
}
