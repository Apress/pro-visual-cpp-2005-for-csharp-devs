using System;
class Base
{
    public int i;
}
class Derived : Base
{
    public new int i;
    public void Access()
    {
        base.i = 3;
        i=4;
        Console.WriteLine("Base i = {0}, Derived i = {1}",base.i, i);
    }
    public static void Main()
    {
        Derived d = new Derived();
        d.Access();
    }
}

