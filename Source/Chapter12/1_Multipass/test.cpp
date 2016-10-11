using namespace System;
void Hello()
{
    Console::WriteLine("::Hello");
}
ref class R
{
public:
    R()
    {
        Hello();
    }
    void Hello()
    {
        Console::WriteLine("R::Hello");
    }
};
void main()
{
    R ^r = gcnew R();
}
