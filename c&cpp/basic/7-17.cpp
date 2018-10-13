#include <iostream>
using namespace std;

int main(){
    int N, D, U;
    cin>>N>>U>>D;

    int cur, t;

    while(1){
        cur = cur + U;
        t++;
        if(cur >= N){
            cout<<t<<endl;
            return 0;
        }else{
            cur = cur - D;
            t++;
        }
    }
}