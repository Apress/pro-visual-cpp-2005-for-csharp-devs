value struct V
{
    V(int i)
    {
    }
};
ref struct R
{
    static public void Main()
    {
        V v1;
        V v2(1);
        V v3 = V(2);
    }
};

