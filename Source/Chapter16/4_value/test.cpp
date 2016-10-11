using namespace System;
generic <typename T>
where T : value class
void Swap(T % a, T % b)
{
    Console::WriteLine("Swapping...");
    T temp = a;
    a = b;
    b = temp;
}
int main()
{
    int i=3, j=4;
    Console::WriteLine("i = {0}, j={1}", i, j);
    Swap<int>(i,j);
    Console::WriteLine("i = {0}, j={1}", i, j);
}
