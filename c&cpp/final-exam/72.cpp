#include <iostream>
#include <map>
using namespace std;

class MyMap
{
    map<string, int> _map;

  public:
    void insert(string key, int value)
    {
        _map[key] = value;
    }
    int sum(string pre)
    {
        map<string, int>::iterator it = _map.begin();
        int count = 0;

        while (it != _map.end())
        {
            if((it->first).find(pre) == 0){
                count+= it->second;
            }
            it++;
        }
        return count;
    }
};

int main()
{
    MyMap my;
    int n;
    cin >> n;
    string action, key, pre;
    int value;
    while (n--)
    {
        cin >> action;
        if (action == "insert")
        {
            cin >> key >> value;
            my.insert(key, value);
        }
        if(action == "sum"){
            cin>>pre;
            cout<<my.sum(pre)<<endl;
        }
    }
    return 0;
}