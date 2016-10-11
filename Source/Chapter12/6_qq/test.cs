using System;
class R
{
    static void Main()
    {
        bool? b;
        bool? c = true;
        b = null;
        Console.WriteLine(b ?? c);
        b = false;
        Console.WriteLine(b ?? c);
    }
}
