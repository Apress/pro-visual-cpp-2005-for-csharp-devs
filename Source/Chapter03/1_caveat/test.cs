class Hello
{
    int i;
    Hello(int number)
    {
        i=number;
    }
    static void Main()
    {
        Hello h = new Hello(1);
        Hello j = new Hello(2);
        j = h;
        System.Console.WriteLine(j.i);
        h.i = 3;
        System.Console.WriteLine(j.i);
    }
}
