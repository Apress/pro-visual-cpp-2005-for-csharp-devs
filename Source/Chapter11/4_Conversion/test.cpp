using namespace System;
void main()
{
    int i0 = int::MaxValue;
    int i;
    float f;
    double d;
    f = i0;
    i = f;
    Console::WriteLine("int {0}, to float {1}, back to int {2}", i0, f, i);
    d = i0;
    i = d;
    Console::WriteLine("int {0}, to double {1}, back to int {2}", i0, d, i);
}
