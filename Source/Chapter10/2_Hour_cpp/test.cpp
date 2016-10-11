using namespace System;
private ref class Clock
{
public:
    property int Hour
    {
        int get()
        {
            if (hour == 0)
            {
                return 12;
            } else
            {
                return hour;
            }
        }
        void set(int value)
        {
            hour = value % 12;
        }
    }
private:
    int hour;
public:
    static void Main()
    {
        DateTime t = DateTime::Now;
        Clock ^c = gcnew Clock();
        c->Hour = t.Hour;
        Console::WriteLine("The little hand is on the {0}", c->Hour);
        c->Hour = 12;
        Console::WriteLine("at midnight it will be {0} o'clock", c->Hour);
    }
};
void main() { Clock::Main();}
