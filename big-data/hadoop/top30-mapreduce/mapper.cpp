#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

// 查询频率前30的搜索词
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
        cout<<it->first<<"\t"<<it->second<<endl;
        it++;
    }
    return 0;
}