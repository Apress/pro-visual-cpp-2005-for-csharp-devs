using namespace System;
ref struct R
{
    delegate void SayHello(String^ Message);
    SayHello ^dSayHello;
    int Count;
    R() : Count(0) {}
    void DisplayMessage(String^ Message)
    {
        Console::WriteLine("{0} : {1} ", ++Count, Message);
    }
    static void Main()
    {
        R^ r = gcnew R();
        r->dSayHello = gcnew SayHello(r, &R::DisplayMessage);
        r->dSayHello("call");
        r->dSayHello("call");
    }
};
void main() {R::Main();}
