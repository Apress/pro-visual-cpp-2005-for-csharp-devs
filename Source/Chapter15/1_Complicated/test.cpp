using namespace System;
template <typename T> void function(T t)
{
    Object ^o = t;
    Console::WriteLine(o->GetType());
};
template<> void function(int i)
{
    Console::WriteLine("template integer");
};
void function(int j)
{
    Console::WriteLine("not a template");
}
void main()
{
    String ^s="hello";
    function(s);
    function(3.0);
    function(1);
    function<int>(1);
}
