#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b)
{
    return a < b;
}

void display(vector<int> &v){
    for(int i = 0 ;i < v.size()-1; i++){
        cout<<v[i]<<" ";
    }

    cout<<v[v.size()-1]<<endl;
}

int main()
{
    int n, m;
    while (cin >> n)
    {
        vector<int> balls;
        while (n--)
        {
            cin >> m;
            balls.push_back(m);
        }
        sort(balls.begin(), balls.end(), compare);
        display(balls);
    }
}