using namespace System;
ref struct R
{
    String ^m_Key;
    int m_Value;
    property int default[String ^]
    {
        int get(String^Key)
        {
            if (Key == m_Key)
            {
                return m_Value;
            }
            else
            {
                return -1;
            }
        }
        void set(String^Key, int Value)
        {
            m_Key = Key;
            m_Value = Value;
        }
    }
    R()
    {
        default["dog"]=3;
    }
    static void Main()
    {
        R ^ r = gcnew R();
        r["first"]=42;
        Console::WriteLine(r["first"]);
        Console::WriteLine(r["second"]);
    }
};
void main() { R::Main();}
