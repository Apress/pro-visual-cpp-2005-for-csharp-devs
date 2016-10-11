using namespace System;
public delegate void Handler(String^);
ref struct Class1
{
    static void News(String^s)
    {
        Console::WriteLine("Class1 : {0}",s);
    }
};
ref struct Class2
{
    static void News(String^s)
    {
        Console::WriteLine("Class2 : {0}",s);
    }
};
ref struct Class3
{
    static void News(String^s)
    {
        Console::WriteLine("Class3 : {0}",s);
    }
};
void main()
{
    Handler ^dNews1 = gcnew Handler(Class1::News);
    Handler ^dNews2 = gcnew Handler(Class2::News);
    Handler ^dNews3 = gcnew Handler(Class3::News);
    Handler ^dNews;
    dNews = dNews1 + dNews2 + dNews3;
    dNews("News has arrived!");
    dNews -= (dNews2+dNews3);
    dNews("We lost subscribers");
    dNews += dNews3;
    dNews("A subscriber has returned");
}
