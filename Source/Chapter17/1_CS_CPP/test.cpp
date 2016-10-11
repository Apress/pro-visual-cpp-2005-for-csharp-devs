#define USING using namespace
USING System;
#define NEW gcnew
#define CLASS ref class
#define STRUCT value class
#define PUBLIC public:

public STRUCT Struct
{
    PUBLIC int i;
};
public CLASS Test
{
    PUBLIC static void Main()
    {
        Struct ^ s = NEW Struct();
        s->i = 42;
        Console::WriteLine(s->i);
    }
};
void main()
{
    Test::Main();
}
