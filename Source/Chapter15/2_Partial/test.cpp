using namespace System;
template <typename T, typename W> ref struct R
{
    static R()
    {
        Console::WriteLine("T,W: "+__FUNCTION__);
    }
};
template <typename T, typename W> ref struct R<T^,W>
{
    static R()
    {
        Console::WriteLine("T^,W: "+__FUNCTION__);
    }
};
template <typename T, typename W> ref struct R<T*,W>
{
    static R()
    {
        Console::WriteLine("T*,W: "+__FUNCTION__);
    }
};
template <typename T> ref struct R<T,T>
{
    static R()
    {
        Console::WriteLine("T,T: "+__FUNCTION__);
    }
};
void main()
{
    R<int,double> Primary;
    R<R^,int> First;
    R<int,int> Second;
    R<char*,int> Third;
}
