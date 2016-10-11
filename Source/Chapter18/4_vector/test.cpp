#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    vector<string> VString;
    VString.push_back("String 1");
    VString.push_back("String 4");
    VString.push_back("String 3");
    VString.push_back("String 2");
    cout << endl << "In order:" << endl;
    for (unsigned int i=0; i < VString.size(); i++)
    {
        cout << VString[i] << endl;
    }
    cout << endl << "Sorted:" << endl;
    sort(VString.begin(),VString.end());
    vector<string>::iterator iter;
    for (iter = VString.begin(); iter != VString.end(); ++iter)
    {
        cout << *iter << endl;
    }
    cout << endl << "Reversed:" << endl;
    vector<string>::reverse_iterator revIter;
    for (revIter=VString.rbegin(); revIter!=VString.rend(); ++revIter)
    {
        cout << *revIter << endl;
    }
    return 0;
}
