using namespace System;
ref class MyException : Exception
{
public:
    MyException(String ^message) : Exception(message)
    {
    }
};
class R
{
public:
    static void Main()
    {
        try
        {
            throw gcnew MyException("exception");
        }
        catch (MyException ^e)
        {
            Console::WriteLine("caught : {0}", e);
            return;
        }
        catch (...)
        {
        }
        finally
        {
            Console::WriteLine("in the finally block");
        }
    }
};
void main() {R::Main();}
