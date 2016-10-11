using namespace System;
using namespace System::Collections;
ref struct R
{
    static void Main()
    {
        ArrayList^ a = gcnew ArrayList();
        int i=3;
        double d=4.0;
        a->Add(i);
        a->Add(d);
        for each (int j in a)
        {
            Console::WriteLine(j);
        }
    }
};
void main() { R::Main();}
