#include <iostream>
#include <map>
using namespace std;

int main()
{
    string key;
    int value;
    map<string, int> count;

    while (cin >> key >> value)
    {
        if (count.find(key) != count.end())
        {
            count[key] = count[key] + value;
        }
        else
        {
            count[key] = value;
        }
    }

    map<string, int>::iterator it = count.begin();
    while (it != count.end())
    {
        cout << it->first << "\t" << it->second << endl;
        it++;
    }

    return 0;
}