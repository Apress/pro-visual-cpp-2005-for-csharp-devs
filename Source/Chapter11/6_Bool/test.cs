using System;
class R
{
    int value;
    R(int V)
    {
        value = V;
    }
    public static bool operator true (R r)
    {
        return r.value!=0;
    }
    public static bool operator false ( R r)
    {
        return r.value==0;
    }
    public void Test(String name)
    {
        if (this)
        {
            Console.WriteLine("{0} is true", name);
        } else
        {
            Console.WriteLine("{0} is false", name);
        }
    }
    public static void Main()
    {
        R r3 = new R(3);
        r3.Test("r3");
        R r0 = new R(0);
        r0.Test("r0");
    }
}
