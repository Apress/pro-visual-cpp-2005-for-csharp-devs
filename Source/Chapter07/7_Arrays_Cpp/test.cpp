using namespace System;
ref struct R
{
    static void Main()
    {
        array<int, 2> ^Rect = gcnew array<int, 2>(3,4);
        for (int i=0; i<3; i++)
        {
            for (int j=0;j<4;j++)
            {
                Rect[i,j]=i+j;
            }
        }
        array<array<int>^> ^Jagged = gcnew array<array<int>^>(3);
        for (int i=0; i<3; i++)
        {
            Jagged[i] = gcnew array<int>(i+1);
            for (int j=0; j<i+1; j++)
            {
                Jagged[i][j]=i+j;
            }
        }
    }
};
void main() {R::Main();}
