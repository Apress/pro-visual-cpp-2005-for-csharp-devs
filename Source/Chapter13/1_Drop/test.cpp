using namespace System;
ref struct Drops
{
    array<int>^floordata;
    Drops()
    {
        floordata = gcnew array<int>(300);
        floordata[1] = 1;
    }
    int Drop(int floors)
    {
        if (floordata[floors])
        {
            return floordata[floors];
        }
        int best = Int32::MaxValue;
        if (floors == 1)
        {
            best = 1;
        }
        else
        {
            int i;
            for (i=1;i<floors/2+1;i++)
            {
                int drops = Drop(floors-i) + 1;
                int thisone = (drops>i) ? drops : i;
                best = thisone<best ? thisone : best;
            }
        }
        floordata[floors]=best;
        return best;
    }
};
void main()
{
    Drops ^d = gcnew Drops();
    Console::WriteLine("For {0} floors, the minimum is {1}", 100, d->Drop(100));
}
