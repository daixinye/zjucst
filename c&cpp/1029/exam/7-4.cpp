#include <iostream>
#include <string>
#include <list>
using namespace std;

inline void insertToList(list<string> &l, string target)
{
    list<string>::iterator it = l.begin();

    while (it != l.end())
    {
        if (it->length() > target.length())
        {
            break;
        }
        it++;
    }

    l.insert(it, target);
}

inline void displayList(list<string> &l)
{
    list<string>::iterator it = l.begin();
    while (it != l.end())
    {
        cout << *it << endl;
        it++;
    }
}

int main()
{
    int lines;

    while (cin >> lines)
    {
        list<string> line_list;
        string line;

        while (lines)
        {
            getline(cin, line);
            if (line.length() == 0)
            {
                continue;
            }
            if (line.compare("stop") == 0)
            {
                break;
            }
            insertToList(line_list, line);
            lines--;
        }

        displayList(line_list);
    }
    return 0;
}