using namespace System;
ref struct Animal
{
    virtual String ^ Name()
    {
        return "Animal";
    }
    String ^Hello()
    {
        return "ugh";
    }
};
ref struct John : Animal
{
    virtual String ^ Name() override
    {
        return "John";
    }
    String ^Hello()
    {
        return "Hello";
    }
};
void main()
{
    John ^j = gcnew John();
    Console::WriteLine("{0} says {1}", j->Name(), j->Hello());
    Console::WriteLine("Oh no! He's an Animal! ");
    Animal ^a = j;
    Console::WriteLine("{0} says {1}", a->Name(), a->Hello());
}
