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
    static Complex operator / (Complex a, Complex b)
    {
        return a / (b.re*b.re+b.im*b.im) * ~b;
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
    private:
    static Complex operator / (Complex a, double f)
    {
        return Complex(a.re/f, a.im/f);
    }
};
void main()
{
    Complex a(-5,10), b(3,4);
    Console::WriteLine("({0}) / ({1}) = {2}",a,b,a/b);
}
