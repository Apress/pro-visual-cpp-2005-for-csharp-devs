template <int p, int i=p-1> struct is_prime
{
    enum
    {
        value = (p%i) && is_prime<p,i-1>::value
    };
};
template<int p> struct is_prime<p,1>
{
    enum
    {
        value=1
    };
};
template<> struct is_prime<2>
{
    enum
    {
        value=1
    };
};
template <int p> ref struct Prime_print
{
    Prime_print<p-1> a;
    static void *ptr = (int)is_prime<p>::value;
};
template<> ref struct Prime_print<1>
{
};
void main()
{
    Prime_print<9> d;
}
