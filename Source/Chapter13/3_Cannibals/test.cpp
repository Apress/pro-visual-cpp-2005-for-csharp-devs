using namespace System;
ref struct Crossing
{
    int MaxA;
    int MaxC;
    int cross(int MaxA, int MaxC)
    {
        this->MaxA=MaxA;
        this->MaxC=MaxC;
        int iterations;
        for (iterations=1; ;iterations++)
        {
            if (crossover(MaxA, MaxC, iterations, -1))
            {
                break;
            }
        }
        return iterations;
    }
    bool crossover(int A, int C, int iterations, int dir)
    {
        if (iterations--<0)
        {
            return false;
        }
        if (A==0 && C==0)
        {
            return true;
        }
        if (A<0 || C<0)
        {
            return false;
        }
        if (A>0 && C>A)
        {
            return false;
        }
        int Ap = MaxA-A;
        int Cp = MaxC-C;
        if (Ap>0 && Cp>Ap)
        {
            return false;
        }
        return(
              crossover(A+dir,C,iterations,-dir) ||
              crossover(A,C+dir,iterations,-dir) ||
              crossover(A+dir,C+dir,iterations,-dir) ||
              crossover(A+dir+dir,C,iterations,-dir) ||
              crossover(A,C+dir+dir,iterations,-dir)
              );
    }
};
void main()
{
    Crossing ^c = gcnew Crossing();
    int Count = c->cross(3,3);
    Console::WriteLine("It takes at least {0} crossings", Count);
}
