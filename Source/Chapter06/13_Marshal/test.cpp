ref class R
{
public:
    static bool Hello(wchar_t ch)
    {
        return true;
    }
};
void main()
{
    R::Hello(L'A'); 
}
