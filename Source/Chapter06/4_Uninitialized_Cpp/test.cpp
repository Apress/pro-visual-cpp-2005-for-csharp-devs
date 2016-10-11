private value class V
{
public:
    int i;
};
private ref class R
{
public:
    static void Main()
    {
        V v;
        System::Console::WriteLine(v.i);
    }
};
void main() { R::Main(); }

