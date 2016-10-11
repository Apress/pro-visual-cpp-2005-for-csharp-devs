using namespace System::Runtime::InteropServices;
ref class R
{
    [returnvalue: MarshalAs(UnmanagedType::Bool)]short Hello(wchar_t ch)
    {
        return(short)true;
    }
public:
    static void LoadMe() {}
};
void main()
{
    R::LoadMe();
}
