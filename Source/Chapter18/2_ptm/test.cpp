struct Class
{
    int i;
    void Function(int i) {}
};
void main()
{
    Class c;
    Class *pClass = &c;
    int Class:: *pInt = &Class::i;
    void (Class::*pFunction)(int) = &Class::Function;
    c.*pInt = 3;
    (c.*pFunction)(3);
    pClass->*pInt = 4;
    (pClass->*pFunction)(4);
}
