using namespace System;
interface class I
{
};
ref struct R : I
{
};
value struct V : I
{
};
generic <typename T>
where T : I
ref struct G
{
    generic <typename V>
    ref struct N
    {
        G<T>^g;
    };
};
int main()
{
    G<I^> ^ i;
    G<R^> ^ r;
    G<V> ^ v;
}
