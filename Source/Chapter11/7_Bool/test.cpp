using namespace System;
ref class R
{
private:
    int value;
    R(int V)
    {
        value = V;
    }
public:
    static operator bool(R^ r)
    {
        return r->value != 0;
    }
    void Test(String^ name)
    {
        if (this)
        {
            Console::WriteLine("{0} is true", name);
        }
        else
        {
            Console::WriteLine("{0} is false", name);
        }
    }
    static void Main()
    {
        R ^r3 = gcnew R(3);
        r3->Test("r3");
        R ^r0 = gcnew R(0);
        r0->Test("r0");
    }
};
void main()
{
    R::Main();
}
