class R
{
    static void Test(params int [] Arr)
    {
        foreach(int i in Arr)
        {
            System.Console.WriteLine(i);
        }
    }
    static void Main()
    {
        Test(1, 2, 3, 4.2f);
    }
}
