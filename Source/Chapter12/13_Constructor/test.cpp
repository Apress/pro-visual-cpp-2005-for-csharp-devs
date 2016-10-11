using namespace System;
ref class R
{
    initonly int i0;
    static initonly int i1=4;
    R()
    {
        i0=3;
    }
public:
    static void Main() {}
};
void main() {R::Main();}
