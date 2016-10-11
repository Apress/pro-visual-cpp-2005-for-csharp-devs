using namespace System;
generic <typename T>
where T : gcnew()
void Function()
{
    T t = gcnew T();
}
ref class R
{
};
int main()
{
    Function<R^>();
}
