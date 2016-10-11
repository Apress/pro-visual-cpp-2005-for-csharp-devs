using namespace System;
ref struct R
{
    static void Main()
    {
        Nullable<bool> b = Nullable<bool>();
        if (!b.HasValue)
        {
            System::Console::WriteLine("null");
        }
        else
        {
            System::Console::WriteLine(b);
        }
    }
};
void main() {R::Main();}
