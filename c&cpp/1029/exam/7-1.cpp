#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

string replace(string s, string target, string substring)
{
    int len = target.length();
    size_t found = s.find(target);
    while (found != string::npos)
    {
        s.replace(found, len, substring);
        found = s.find(target, found + 1);
    }
    return s;
}

int main()
{
    vector<string> content;
    vector<string>::iterator it;
    string line;
    string target, substring;

    while (getline(cin, line))
    {
        if (line.compare("end") == 0)
        {
            cin >> target;
            cin >> substring;
            break;
        }
        content.push_back(line);
    }

    it = content.begin();
    while (it != content.end())
    {
        *it = replace(*it, target, substring);
        cout << *it << endl;
        it++;
    }
    return 0;
}