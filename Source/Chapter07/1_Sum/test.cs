class R
{
    static int Sum(params int [] Arr)
    {
        int r = 0;
        foreach(int i in Arr)
        {
            r+=i;
        }
        return r;
    }
    static void Main()
    {
        int[] Arr2 = {1,2,3,4,5};
        System.Console.WriteLine(Sum(Arr2));
        System.Console.WriteLine(Sum(1,2,3,4));
    }
}
