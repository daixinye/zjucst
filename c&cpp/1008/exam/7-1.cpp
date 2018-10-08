#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
    public:
        int department;
        string name;
        int height;
        int weight;
        Student(int d, string n, int h, int w){
            department = d;
            name = n;
            height = h;
            weight = w;
        }
        void print(){
            printf("%06d", department);
            cout<<" "<<name<<" "<<height<<" "<<weight<<endl;
        }
};

int main(){
    int N;
    cin>>N;
    map<int, int> stu_map;
    Student *stu_list[N+1];

    string n;
    int d, h,w;
    for(int i = 1; i <= N; i++){
        cin>>d;
        cin>>n;
        cin>>h;
        cin>>w;

        stu_list[i] = new Student(d, n, h, w);

        if(!stu_map[d]){
            stu_map[d] = i;
        }
        else{
            int c = stu_map[d];
            stu_map[d] = stu_list[c]->height > h ? c : i;
        }
    }

    map<int,int>::iterator it;
    vector<int> s_v;
    it = stu_map.begin();
    while(it != stu_map.end()){
        s_v.push_back(it->first);
        it ++;
    }

    sort(s_v.begin(), s_v.end());

    for(int j = 0; j < s_v.size(); j++){
        stu_list[stu_map[s_v[j]]]->print();
    }

    return 0;
}