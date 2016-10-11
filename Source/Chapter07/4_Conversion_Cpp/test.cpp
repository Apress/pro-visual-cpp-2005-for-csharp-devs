void Test(... array<int> ^Arr)
{
    for each (int i in Arr)
    {
        System::Console::WriteLine(i);
    }
}
void main()
{
    Test(1,2, 3, 4.2f);
}


