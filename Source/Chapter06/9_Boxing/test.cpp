using namespace System;
value struct V
{
};
ref struct R
{
    static void Main()
    {
        V v;
        Object ^o = v;
        Console::WriteLine(o);
        v = (V) o;
        Console::WriteLine(v);
    }
};
int main()
{
    R::Main();
}
