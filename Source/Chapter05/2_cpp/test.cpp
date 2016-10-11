private value class S
{
};
private ref class R
{
public:
    static void Main()
    {
        R ^r = gcnew R();
        S s = S();
    }
};
void main() { R::Main();}
