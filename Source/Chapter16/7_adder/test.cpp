using namespace System;
generic <typename T>
where T : value class
T Add(T a, T b)
{
    if (T::typeid == int::typeid)
    {
        int a0 = safe_cast<int>(a);
        int b0 = safe_cast<int>(b);
        return safe_cast<T>(a0+b0);
    }
    if (T::typeid == double::typeid)
    {
        double a0 = safe_cast<double>(a);
        double b0 = safe_cast<double>(b);
        return safe_cast<T>(a0+b0);
    }
    String ^s = String::Format("{0} is not a valid type for addition", T::typeid);
    throw gcnew Exception(s);
}
int main()
{
    try
    {
        Console::WriteLine("{0}+{1}={2}", 3, 4, Add(3,4));
        Console::WriteLine("{0}+{1}={2}", 3.1, 4.2, Add(3.1,4.2));
        Console::WriteLine("{0}+{1}={2}", 3.1, 4.2, Add(3.1f,4.2f));
    }
    catch (Exception ^e)
    {
        Console::WriteLine("Exception: {0}", e);
    }
}
