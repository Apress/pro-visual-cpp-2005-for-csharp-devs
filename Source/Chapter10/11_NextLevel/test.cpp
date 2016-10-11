using namespace System;
public delegate bool DelCompare(Object^, Object^);
interface class ICompare
{
    virtual DelCompare ^getCompareDelegate();
};
ref struct MyObject : ICompare
{
    int Value;
    static DelCompare ^dCompare = gcnew DelCompare(Compare);
    MyObject(int Value)
    {
        this->Value = Value;
    }
    static bool Compare(Object ^o1, Object ^o2)
    {
        MyObject ^m1 = (MyObject^) o1;
        MyObject ^m2 = (MyObject^) o2;
        return(m1->Value < m2->Value);
    }
    virtual String ^ToString() override
    {
        return Value.ToString();
    }
    virtual DelCompare ^getCompareDelegate()
    {
        return dCompare;
    }
};
public delegate void DelAlgorithm(DelCompare ^dCompare, array<Object^> ^a);
ref struct Sorter abstract sealed
{
    static DelAlgorithm ^dAlgorithm = gcnew DelAlgorithm(Bubble);
    static void Bubble(DelCompare ^dCompare, array<Object^> ^a)
    {
        for (int i=1; i<a->Length; i++)
        {
            for (int j=0; j<i; j++)
            {
                if (dCompare(a[i], a[j]))
                {
                    Object ^tempObject;
                    tempObject = a[i];
                    a[i]=a[j];
                    a[j]=tempObject;
                }
            }
        }
    }
    static void Sort(array<Object^> ^a)
    {
        ICompare ^ic = (ICompare^)a[0];
        dAlgorithm(ic->getCompareDelegate(), a);
    }
};
void main()
{
    array<MyObject^> ^myObjectArray = gcnew array<MyObject^>
    {
        gcnew MyObject(5),
        gcnew MyObject(3),
        gcnew MyObject(1),
        gcnew MyObject(4),
        gcnew MyObject(2),
    };
    Sorter::Sort(myObjectArray);
    for (int i=0; i< myObjectArray->Length; i++)
    {
        Console::Write(myObjectArray[i]);
    }
    Console::WriteLine();
}
