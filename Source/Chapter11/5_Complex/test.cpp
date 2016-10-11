using namespace System;
value struct Complex
{
    double re;
    double im;
    Complex(double re, double im)
    {
        this->re = re;
        this->im = im;
    }
    static Complex operator + (Complex a, Complex b)
    {
        return Complex(a.re+b.re, a.im+b.im);
    }
    static Complex operator - (Complex a, Complex b)
    {
        return Complex(a.re-b.re, a.im-b.im);
    }
    static Complex operator ~ (Complex a)
    {
        return Complex(a.re, - a.im);
    }
    static Complex operator * (Complex a, Complex b)
    {
        return Complex(a.re*b.re - a.im*b.im, a.re*b.im + a.im*b.re);
    }
    virtual String ^ ToString() override
    {
        String ^s = re.ToString();
        if (im != 0)
        {
            return s += " + " + im.ToString() + "i";
        }
        return s;
    }
    static Complex operator / (Complex a, Complex b)
    {
        return a / ((double)b * (double)b) * ~b;
    }
    static operator Complex(double re)
    {
        return Complex(re,0);
    }
    static explicit operator double(Complex c)
    {
        return Math::Sqrt(c.re*c.re + c.im * c.im);
    }
    static Complex operator / (Complex a, double f)
    {
        return Complex(a.re/f, a.im/f);
    }
};
void main()
{
    Complex a(-5,10), b(3,4);
    double c(3.5);
    Console::WriteLine("({0}) / ({1}) = {2}",a,b,a/b);
    Console::WriteLine("({0}) * ({1}) = {2}",a,c,a*c);
    Console::WriteLine("({0}) / ({1}) = {2}",c,a,c/a);
}
