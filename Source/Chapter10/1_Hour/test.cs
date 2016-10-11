using System;
class Clock
{
    public int Hour
    {
        get
        {
            if (hour == 0)
            {
                return 12;
            } 
            else
            {
                return hour;
            }
        }
        set
        {
            hour = value % 12;
        }
    }
    private int hour;
    public static void Main()
    {
        DateTime t = DateTime.Now;
        Clock c = new Clock();
        c.Hour = t.Hour;
        Console.WriteLine("The little hand is on the {0}", c.Hour);
        c.Hour = 12;
        Console.WriteLine("at midnight it will be {0} o'clock", c.Hour);
    }
}
