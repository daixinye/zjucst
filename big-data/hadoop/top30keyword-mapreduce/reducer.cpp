#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    string key;
    int value;
    map<string, int> count;
    string line;

    while (getline(cin, line))
    {
        string keyword;
        string temp;
        vector<string> in;
        istringstream iss(line);

        while (getline(iss, temp, '\t'))
        {
            in.push_back(temp);
        }

        keyword = in[0];
        value = stoi(in[1]);

        if (count.find(keyword) != count.end())
        {
            count[keyword] = count[keyword] + value;
        }
        else
        {
            count[keyword] = value;
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