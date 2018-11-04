#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    string key, value;
    string line;
    map<string, int> count_map;
    while (getline(cin, line))
    {
        string url;
        string temp;
        vector<string> in;
        istringstream iss(line);

        while (getline(iss, temp, '\t'))
        {
            in.push_back(temp);
        }

        url = in[5];

        if (count_map.find(url) != count_map.end())
        {
            count_map[url]++;
        }
        else
        {
            count_map[url] = 1;
        }
    }

    map<string, int>::iterator it = count_map.begin();
    while (it != count_map.end())
    {
        // 过滤小于10次的
        if (it->second > 10)
        {
            cout << it->first << "\t" << it->second << endl;
        }
        it++;
    }
    return 0;
}