using namespace System;
ref struct Test
{
    generic<typename T> delegate void Del(T item);
    static void Notify(int i)
    {
        Console::WriteLine("notified...");
    }
};
void main()
{
    Test::Del<int> ^m1 = gcnew Test::Del<int>(Test::Notify);
    m1(3);
}
