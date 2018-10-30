#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void display(int set, vector<string> &section){
    int size = section.size();
    deque<string> temp;

    for(int i = size - 1;i >=0; i--){
        if(i%2 != 0){
            temp.push_back(section[i]);
        }else{
            temp.push_front(section[i]);
        }
    }

    cout<<"SET "<<set<<endl;
    deque<string>::iterator it = temp.begin();
    while(it != temp.end()){
        cout<<*it<<endl;
        it++;
    }
}

int main()
{
    int n;
    vector< vector<string> > sets;

    while (cin >> n)
    {
        if(n==0){
            break;
        }

        vector<string> section;
        string name;
        while (n--)
        {
            cin>>name;
            section.push_back(name);
        }
        sets.push_back(section);
    }

    vector< vector<string> >::iterator it;
    it = sets.begin();
    int set_count = 1;
    while(it != sets.end()){
        display(set_count, *it);
        it++;
        set_count++;
    }
    return 0;
}