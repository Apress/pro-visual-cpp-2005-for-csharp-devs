ref struct R
{
    static void Main()
    {
        int i;
        int *ptr = &i;
        *ptr = 3;
        System::Console::WriteLine(i);
    }
};
void main() {R::Main();}
