using System;
class R
{
    static void Main()
    {
        int[,] Rect = new int[3,4];
        for (int i=0; i<3; i++)
        {
            for (int j=0;j<4;j++)
            {
                Rect[i,j]=i+j;
            }
        }
        int [][] Jagged = new int[3][];
        for (int i=0; i<3; i++)
        {
            Jagged[i] = new int[i+1];
            for (int j=0; j<i+1; j++)
            {
                Jagged[i][j]=i+j;
            }
        }
    }
}
