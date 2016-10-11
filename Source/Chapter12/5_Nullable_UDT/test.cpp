using namespace System;
value struct V
{
};
ref struct R
{
    static void Main()
    {
        Nullable<V> b = Nullable<V>();
        if (!b.HasValue)
        {
            System::Console::WriteLine("null");
        }
    }
};
void main() {R::Main();}
