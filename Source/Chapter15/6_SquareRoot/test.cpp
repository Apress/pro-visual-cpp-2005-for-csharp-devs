using namespace System;
template <int N, int low=1, int high=N>
struct Root
{
    enum
    {
        Value = Root<N, ((low+high)/2), N/((low+high)/2)>::Value
    };
};
template <int N, int R>
struct Root<N,R,R>
{
    enum
    {
        Value = R
    };
};
void main()
{
    Console::WriteLine(Root<196>::Value);
}
