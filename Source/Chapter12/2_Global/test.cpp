using namespace System;
ref struct Outer
{
    ref struct Inner
    {
        Inner()
        {
            Console::WriteLine(__FUNCSIG__);
        }
        ref struct Outer
        {
            ref struct Inner
            {
                Inner()
                {
                    Console::WriteLine(__FUNCSIG__);
                }
                public:
                static void Test()
                {
                    Outer::Inner ^m0 = gcnew Outer::Inner();
                    ::Outer::Inner ^m1 = gcnew ::Outer::Inner();
                }
            };
        };
    };
};
void main()
{
    Outer::Inner::Outer::Inner::Test();
}
