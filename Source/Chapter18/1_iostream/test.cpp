#include <iostream>
using namespace std;
namespace R
{
    ostream& endl ( ostream& os )
    {
        ::operator<<(os, " <END> ");
        ::endl(os);
        return os;
    }
    ostream& operator<< (ostream& os, const char* str )
    {
        ::operator<<(os, " -> ");
        ::operator<<(os, str);
        ::operator<<(os, " <- ");
        return os;
    }
    static int Test()
    {
        cout << "Hello" << endl;
        return 0;
    }
};
int main()
{
    R::Test();
}
