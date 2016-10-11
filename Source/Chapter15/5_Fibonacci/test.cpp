using namespace System;
template <int N>
struct Fibonacci
{
    enum
    {
        Value = Fibonacci<N-1>::Value + Fibonacci<N-2>::Value
    };
};
template <>
struct Fibonacci<0>
{
    enum
    {
        Value = 0
    };
};
template <>
struct Fibonacci<1>
{
    enum
    {
        Value = 1
    };
};
void main()
{
    Console::WriteLine(Fibonacci<7>::Value);
}
