using namespace System;
template <int P> String^ Radix()
{
    return " sqr("+P.ToString()+")";
}
template <> String^ Radix<-1>()
{
    return "i";
}
template <typename T, int N>
value struct Complex
{
    T re;
    T im;
    Complex(T _re, T _im)
    {
        re = _re;
        im = _im;
    }
    Complex(T _re)
    {
        re = _re;
        im = T(0);
    }
    static Complex operator* (Complex lhs, Complex rhs)
    {
        return Complex(lhs.re*rhs.re + (lhs.im*rhs.im*T(N)),
                       lhs.re*rhs.im + lhs.im*rhs.re);
    }
    static Complex operator/ (Complex lhs, Complex rhs)
    {
        T bottom = rhs.re*rhs.re - rhs.im*rhs.im*T(N);
        Complex product = Complex(lhs * ~rhs);
        return Complex(product.re/bottom, product.im/bottom);
    }
    static Complex operator+ (Complex lhs, Complex rhs)
    {
        return Complex(lhs.re+rhs.re, lhs.im+rhs.im);
    }
    static Complex operator- (Complex lhs, Complex rhs)
    {
        return Complex(lhs.re-rhs.re, lhs.im-rhs.im);
    }
    static Complex operator~ (Complex lhs)
    {
        return Complex(lhs.re, -lhs.im);
    }
    virtual String^ ToString() override
    {
        return re.ToString() + (!!im ? " + " + im.ToString() + Radix<N>() : "");
    }
};
template <int P>
value struct Modulo
{
    int Value;
    Modulo(int Val)
    {
        Value = Val % P;
    }
    static bool operator!(Modulo rhs)
    {
        return !rhs.Value;
    }
    static void ExtendedEuclid(int a, int b, int %d, int %x, int %y)
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
    static bool operator==(Modulo lhs, Modulo rhs)
    {
        return((rhs.Value-lhs.Value) % P == 0);
    }
    static bool operator!=(Modulo lhs, Modulo rhs)
    {
        return !(lhs == rhs);
    }
    static Modulo operator* (Modulo lhs, Modulo rhs)
    {
        return Modulo((lhs.Value * rhs.Value) % P);
    }
    static Modulo operator+ (Modulo lhs, Modulo rhs)
    {
        return Modulo((lhs.Value + rhs.Value) % P);
    }
    static Modulo operator- (Modulo lhs, Modulo rhs)
    {
        return Modulo((lhs.Value - rhs.Value) % P);
    }
    static Modulo operator- (Modulo lhs)
    {
        return Modulo((P - lhs.Value) % P);
    }
    static Modulo operator/ (Modulo lhs, Modulo rhs)
    {
        int d, x, y;
        ExtendedEuclid(rhs.Value,P,d,x,y);
        return lhs*Modulo(x*d);
    }
    virtual String ^ ToString() override
    {
        Value = (Value+P) % P;
        String ^s = Value.ToString();
        return s;
    }
};
template <typename T> ref struct Fibonacci
{
    static T half = T(1)/T(2);
    static Complex<T,5> phi = Complex<T,5>(half,half);
    static Complex<T,5> theta = Complex<T,5>(half,-half);
    static Complex<T,5> difference = phi-theta;
    template <int N>
    ref struct Result
    {
        static initonly Complex<T,5> phi_n = Result<N-1>::phi_n * phi;
        static initonly Complex<T,5> theta_n = Result<N-1>::theta_n * theta;
        static initonly Complex<T,5> Value = (phi_n-theta_n)/difference;
    };
    template <>
    ref struct Result<0>
    {
        static initonly Complex<T,5> phi_n = Complex<T,5>(T(1));
        static initonly Complex<T,5> theta_n = Complex<T,5>(T(1));
        static initonly Complex<T,5> Value = Complex<T,5>(T(0));
    };
    template <int N>
    static void Print()
    {
        Print<N-1>();
        Console::Write("{0,4} ", Result<N>::Value);
    }
    template <>
    static void Print<0>()
    {
    }
};
void main()
{
    Fibonacci<double>::Print<14>();
    Console::WriteLine();
    Fibonacci<Modulo<7>>::Print<14>();
    Console::WriteLine();
    Fibonacci<Modulo<13>>::Print<14>();
    Console::WriteLine();
}
