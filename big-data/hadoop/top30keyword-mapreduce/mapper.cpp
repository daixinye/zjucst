#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

// 查询频率前30的搜索词
int main()
{
    string key, value;
    string line;
    map<string, int> count_map;
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

        keyword = in[2];

        if (count_map.find(keyword) != count_map.end())
        {
            count_map[keyword]++;
        }
        else
        {
            count_map[keyword] = 1;
        }
    }

    map<string, int>::iterator it = count_map.begin();
    while (it != count_map.end())
    {
        cout << it->first << "\t" << it->second << endl;
        it++;
    }
    return 0;
}