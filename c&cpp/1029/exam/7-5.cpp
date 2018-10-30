#include <iostream>
#include <map>
using namespace std;

int main()
{
    string s;
    map<char, int> char_map;
    cin>>s;

    for(int i = 0; i < s.size(); i++)
    {
        char_map[s[i]]++;
    }

    map<char, int>::iterator it = char_map.begin();

    int count = 0;
    bool add_one_flag = false;
    while(it != char_map.end()){
        count += (it->second /2)*2;
        if(it->second % 2 > 0){
            add_one_flag = true;
        }
        it++;
    }

    count = add_one_flag ? count+1: count;
    cout<<count<<endl;
    return 0;
}