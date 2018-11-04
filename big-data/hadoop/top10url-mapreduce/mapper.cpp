#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main()
{
    string key, value;
    string line;
    map<string, int> count_map;
    while (getline(cin, line))
    {
        string ts, uid, keyword, rank, ord, url, year, month, day, hour;
        istringstream iss(line);
        iss >> ts >> uid >> keyword >> rank >> ord >> url >> year >> month >> day >> hour;

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