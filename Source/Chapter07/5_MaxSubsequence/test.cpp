using namespace System;
void MaxSubSequence(...array<int>^Sequence)
{
    int MaxStart, MaxEnd, MaxSum, Sum, Start;
    for each (int j in Sequence)
    {
        Console::Write("{0} ", j);
    }
    MaxSum = Int32::MinValue;
    Start = 0;
    Sum = 0;
    for (int i=0; i<Sequence->Length; i++)
    {
// don't carry negative sums forward
        if (Sum<0)
        {
            Sum = 0;
            Start = i;
        }
        Sum += Sequence[i];
// is our new sum better?
        if (Sum > MaxSum)
        {
            MaxSum = Sum;
            MaxStart = Start;
            MaxEnd = i;
        }
    }
    Console::Write(" has subsequence: ");
    for (int j=MaxStart; j<= MaxEnd; j++)
    {
        Console::Write("{0} ", Sequence[j]);
    }
    Console::WriteLine();
}
int main()
{
    MaxSubSequence(1,1,-1,-4,5,-3,6,7,-17,3,5,-2,8);
    MaxSubSequence(1,1,-1,-4,5,2,6,7);
    MaxSubSequence(-5,1,-3,-4);
    MaxSubSequence(-5,-2,-3,-4);
    MaxSubSequence(-5,1,1,1,-1,-3,1,1);
    MaxSubSequence(-10,2,3,-2,0,5,-15);
}
