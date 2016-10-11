ref class R
{
    ref class R1
    {
    };
    value class V1
    {
    };
    V1 vA;
    R1 ^rA;
    V1 vB;
    R1 ^rB;
    static V1 vC = V1();
    static R1 ^rC = gcnew R1();
    R()
    {
        vA = V1();
        rA = gcnew R1();
        vB = V1();
        rB = gcnew R1();
    }
public:
    static void Main()
    {
        R ^r = gcnew R();
    }
};
void main()
{
    R::Main();
}
