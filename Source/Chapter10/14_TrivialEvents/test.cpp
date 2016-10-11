using namespace System;
public delegate void Handler(String^);
ref struct Base
{
    virtual void News(String^s)
    {
        Console::WriteLine("{0} : {1}",ToString(),s);
    }
};
ref struct Class1 : Base
{
};
ref struct Class2 : Base
{
};
ref struct Class3 : Base
{
};
ref struct Holder
{
    void Deliver(String ^s)
    {
        News(s);
    }
    event Handler ^News;
};
void main()
{
    Holder ^h = gcnew Holder();
    h->News += gcnew Handler(gcnew(Class1),&Class1::News);
    h->Deliver("News has arrived!");
}
