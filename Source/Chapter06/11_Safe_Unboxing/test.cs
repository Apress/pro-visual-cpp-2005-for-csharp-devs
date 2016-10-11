using System;
using System.Collections;
class R
{
    public static void Main()
    {
        ArrayList a = new ArrayList();
        int i = 3;
        double d = 4.0;
        a.Add(i);
        a.Add(d);
        foreach(Object o in a)
        {
            if (o is int)
            {
                int i1 = (int)o;
                Console.WriteLine(i1);
            } else
            {
                double d1 = (double)o;
                Console.WriteLine(d1);
            }
        }
    }
}
