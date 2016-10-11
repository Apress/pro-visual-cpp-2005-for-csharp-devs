using System;
class Base
{
    public void f(int i)
    {
        Console.WriteLine("Base.f()");
    }
}
class Derived : Base
{
    public void f(char c)
    {
        Console.WriteLine("Derived.f()");
    }
    static void Main()
    {
        Derived d = new Derived();
        d.f(3);
    }
}
