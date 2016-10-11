using namespace System;
ref struct MyObject
{
    int Value;
    MyObject(int Value)
    {
        this->Value = Value;
    }
    virtual String ^ToString() override
    {
        return Value.ToString();
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
    for (int i=1; i<myObjectArray->Length; i++)
    {
        for (int j=0; j<i; j++)
        {
            if (myObjectArray[i]->Value < myObjectArray[j]->Value)
            {
                MyObject ^tempObject;
                tempObject = myObjectArray[i];
                myObjectArray[i]=myObjectArray[j];
                myObjectArray[j]=tempObject;
            }
        }
    }
    foreach (MyObject^ o in myObjectArray)
    {
        Console::Write(o);
    }
    Console::WriteLine();
}
