using namespace System;
void ExtendedEuclid(int a, int b, int %d, int %x, int %y)
{
    if (b==0)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        ExtendedEuclid(b,a%b, d, y, x);
        y-= (a/b)*x;
    }
}
value struct F13
{
    unsigned Value;
    initonly static unsigned P = 13;
    F13(unsigned Val)
    {
        Value = Val % P;
    }
    static F13 operator * (F13 arg1, F13 arg2)
    {
        return F13((arg1.Value * arg2.Value) % P);
    }
    static F13 operator + (F13 arg1, F13 arg2)
    {
        return F13((arg1.Value + arg2.Value) % P);
    }
    static F13 operator - (F13 arg1, F13 arg2)
    {
        return F13((arg1.Value - arg2.Value) % P);
    }
    static F13 operator - (F13 arg1)
    {
        return F13((P - arg1.Value) % P);
    }
    static F13 operator / (F13 arg1, F13 arg2)
    {
        int d, x, y;
        ExtendedEuclid(arg2.Value,P,d,x,y);
        return arg1*F13(x*d);
    }
    virtual String ^ ToString() override
    {
        Value = (Value+P) % P;
        String ^s = Value.ToString();
        return s;
    }
};
void main()
{
    F13 a(6), b(9), c(4), d(10);
    Console::WriteLine("{0} * {1} is {2}", a, b, a*b);
    Console::WriteLine("{0} / {1} is {2}", a, b, a/b);
    Console::WriteLine("{0} * {1} is {2}", c, d, c*d);
}
