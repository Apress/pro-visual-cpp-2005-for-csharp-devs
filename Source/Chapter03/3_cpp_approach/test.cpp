private ref class Hello
{
private:
    int i;
    Hello(int number)
    {
        i=number;
    }
public:
    static void Main()
    {
        Hello ^h = gcnew Hello(1);
        Hello ^j = gcnew Hello(2);
        j = h;
        System::Console::WriteLine(j->i);
        h->i = 3;
        System::Console::WriteLine(j->i);
    }
};
void main()
{
    Hello::Main();
}
