#include <iostream>
#include <string>
using namespace std;

int main()
{
    string key, value;
    int count = 0;
    while (cin >> key)
    {
        cin >> value;
        count += stoi(value);
    }
    cout<<key<<"\t"<<count<<endl;
    return 0;
}