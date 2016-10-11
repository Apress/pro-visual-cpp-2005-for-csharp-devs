using namespace System;
ref struct Crossing
{
    array<unsigned>^ times;
    unsigned int Mask;
    int cross(...array<unsigned>^ times)
    {
        this->times = times;
        Mask = (1u<<times->Length)-1;
        return start(Mask);
    }
    int end(unsigned there)
    {
        if (there==0)
        {
            return 0;
        }
        unsigned here = Mask^there;
        unsigned best = 0xffff;
        for (int i=0;i<times->Length; i++)
        {
            if (here & (1<<i))
            {
                unsigned thistrip;
                thistrip = times[i] + start(there^(1<<i));
                if (thistrip<best)
                {
                    best = thistrip;
                }
            }
        }
        return best;
    }
    int start(unsigned here)
    {
        if (here==0)
        {
            return 0;
        }
        unsigned best = 0xffff;
        for (int i=0;i<times->Length; i++)
        {
            if (here & (1<<i))
            {
                unsigned thistrip;
                for (int j=i+1;j<times->Length; j++)
                {
                    if (here & (1<<j))
                    {
                        thistrip =
                        (times[i]>times[j]? times[i] : times[j])
                        + end(here^((1<<i)|(1<<j)));
                        if (thistrip<best)
                        {
                            best = thistrip;
                        }
                    }
                }
            }
        }
        return best;
    }
};
void main()
{
    Crossing ^c = gcnew Crossing();
    int time = c->cross(1,2,5,10);
    Console::WriteLine("It takes at least {0} minutes", time);
}
