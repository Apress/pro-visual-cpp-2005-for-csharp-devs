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
void main()
{
    Handler ^dNews1 = gcnew Handler(gcnew(Class1),&Class1::News);
    Handler ^dNews2 = gcnew Handler(gcnew(Class2),&Class2::News);
    Handler ^dNews3 = gcnew Handler(gcnew(Class3),&Class3::News);
    Handler ^dNews;
    dNews = dNews1 + dNews2 + dNews3;
    dNews("News has arrived!");
    dNews -= (dNews2+dNews3);
    dNews("We lost subscribers");
    dNews += dNews3;
    dNews("A subscriber has returned");
}
