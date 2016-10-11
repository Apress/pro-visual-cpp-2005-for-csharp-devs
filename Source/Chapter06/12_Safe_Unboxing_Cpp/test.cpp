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
        for each (Object ^o in a)
        {
            if (dynamic_cast<int^>(o) != nullptr)
            {
                int i1=(int)o;
                Console::WriteLine(i1);
            } else
            {
                double d1=(double)o;
                Console::WriteLine(d1);
            }
        }
    }
};
void main() { R::Main();}
