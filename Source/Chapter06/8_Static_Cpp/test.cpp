using namespace System;
ref struct R
{
    static R()
    {
        Console::WriteLine("Static Constructor");
    }
    R()
    {
        Console::WriteLine("Constructor");
    }
};
int main()
{
    R ^r;
    Console::WriteLine("in main()");
    r = gcnew R();
}
