using namespace System;
interface class Sleeps
{
    void GoToSleep();
};
interface class Eats
{
    void Feed();
};
ref struct Animal abstract: Eats, Sleeps
{
    virtual void GoToSleep()
    {
        Console::WriteLine("{0} is Sleeping", ToString());
    }
    virtual void Feed()
    {
        Console::WriteLine("{0} is Eating", ToString());
    }
};
ref struct Cat : Animal
{
    virtual void GoToSleep() override
    {
        Console::WriteLine("{0} is Catnapping", ToString());
    }
};
ref struct Dog : Animal
{
};
void main()
{
    Cat ^c = gcnew Cat();
    Dog ^d = gcnew Dog();
    c->Feed();
    c->GoToSleep();
    d->Feed();
    d->GoToSleep();
}

