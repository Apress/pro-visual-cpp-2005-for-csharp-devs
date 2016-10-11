using namespace System;
template <typename T> String ^MyToString(T ^t)
{
    return t->MyFunction();
}
ref struct R
{
    String ^ MyFunction()
    {
        return "Hello";
    }
};
void main()
{
    R ^r = gcnew R();
    Console::WriteLine(MyToString(r));
}
