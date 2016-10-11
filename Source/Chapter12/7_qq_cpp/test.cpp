using namespace System;
ref struct R
{
    static void Main()
    {
        Nullable<bool> b;
        Nullable<bool> c = Nullable<bool>(true);
        b = Nullable<bool>();
        Console::WriteLine(Nullable<bool>( b.HasValue ? b : c ));
        b = Nullable<bool>(false);
        Console::WriteLine(Nullable<bool>( b.HasValue ? b : c ));
    }
};
void main() {R::Main();}
