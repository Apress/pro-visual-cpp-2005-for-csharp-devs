using System;
class MyException : Exception
{
    public MyException(string message) : base(message)
    {
    }
}
class R
{
    static void Main()
    {
        try
        {
            throw new MyException("exception");
        }
        catch (MyException e)
        {
            Console.WriteLine("caught : {0}", e);
            return;
        }
        catch
        {
        }
        finally
        {
            Console.WriteLine("in the finally block");
        }
    }
}
