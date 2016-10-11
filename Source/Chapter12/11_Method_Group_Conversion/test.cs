using System;
class R
{
    public delegate void SayHello(string Message);
    SayHello dSayHello;
    int Count = 0;
    public void DisplayMessage(string Message)
    {
        Console.WriteLine("{0} : {1} ", ++Count, Message);
    }
    public static void Main()
    {
        R r = new R();
// r.dSayHello = new SayHello(r.DisplayMessage);
        r.dSayHello = r.DisplayMessage;
        r.dSayHello("call");
        r.dSayHello("call");
    }
}
