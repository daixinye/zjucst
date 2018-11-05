#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{

    string s, p;
    cin >> s >> p;

    regex reg(p);
    smatch r;

    if (regex_match(s, r, reg) == 1)
    {
        cout << "ok" << endl;
    }
    else
    {
        cout << "sorry" << endl;
    }
    return 0;
}