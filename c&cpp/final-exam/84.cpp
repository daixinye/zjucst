#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    // 输入阿拉伯数字
    cin>>n;
    map<int, string> _map;
    // 建立映射
    _map[1] = "One";
    _map[2] = "Two";
    _map[3] = "Three";
    _map[4] = "Four";
    _map[5] = "Five";
    _map[6] = "Six";
    _map[7] = "Seven";
    _map[8] = "Eight";
    _map[9] = "Nine";

    // 输出
    cout<<_map[n]<<endl;
    return 0;
}