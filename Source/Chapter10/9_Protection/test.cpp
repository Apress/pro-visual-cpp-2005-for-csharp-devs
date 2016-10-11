using namespace System;
ref struct R
{
    private:
    static property DateTime Time
    {
        public:
        DateTime get()
        {
            return DateTime::Now;
        }
    }
};
void main()
{
    Console::WriteLine(R::Time);
}
