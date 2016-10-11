using namespace System;
generic <typename T>
void Function()
{
    Console::WriteLine(T::typeid);
}
ref struct R
{
};
generic <typename T> ref struct GenericType
{
};
generic <typename T> ref struct Outer
{
    generic <typename V, typename W> ref struct Inner
    {
    };
};
int main()
{
    Function<int>();
    Function<R^>();
    Function<GenericType<int>^>();
    Function<Outer<int>::Inner<R^, short> ^>();
}
