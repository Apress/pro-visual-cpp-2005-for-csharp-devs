class R
{
    static void Main()
    {
        int i;
        unsafe
        {
            int *ptr = &i;
            *ptr = 3;
        }
        System.Console.WriteLine(i);
    }
}
