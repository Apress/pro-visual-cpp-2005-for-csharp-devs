using System;
class R
{
    public delegate void SayHello(string Message);
    SayHello dSayHello;
    public static void Main()
    {
        int Count = 0;
        R r = new R();
        r.dSayHello += delegate(string Message)
        {
            Console.WriteLine("{0} : {1} ", ++Count, Message);
        };
        r.dSayHello("call");
        r.dSayHello("call");
    }
}
