class R
{
    class R1
    {
    }
    struct V1
    {
    }
    V1 vA = new V1();
    R1 rA = new R1();
    V1 vB;
    R1 rB;
    static V1 vC = new V1();
    static R1 rC = new R1();
    R()
    {
        vB = new V1();
        rB = new R1();
    }
    static public void Main()
    {
        R r = new R();
    }
}
