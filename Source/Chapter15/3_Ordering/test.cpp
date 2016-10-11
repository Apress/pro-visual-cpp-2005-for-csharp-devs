using namespace System;
template <typename T> String ^MyToString(T t)
{
    return t.ToString();
}
template <typename T> String ^MyToString(T ^t)
{
    return t->ToString();
}
template <> String ^MyToString(double d)
{
    return d.ToString("0.###e+00");
}
value struct V
{
    virtual String ^ToString() override
    {
        return "it's V";
    }
};
void main()
{
    V v;
    int i = 23;
    double d=47.3;
    Console::WriteLine(MyToString<int>(i));
    Console::WriteLine(MyToString<double>(d));
    Console::WriteLine(MyToString<V>(v));
}
