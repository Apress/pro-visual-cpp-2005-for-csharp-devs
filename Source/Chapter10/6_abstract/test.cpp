using namespace System;
ref struct Base abstract
{
    property int Prop
    {
        virtual int get() abstract;
    }
};
ref struct Derived : Base
{
    property int Prop
    {
        virtual int get() override sealed
        {
            return 1;
        }
    }
};
void main() {}
