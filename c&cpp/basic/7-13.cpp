#include <iostream>
using namespace std;

int main(){
    double open, high, low, close;
    cin>>open>>high>>low>>close;

    if(open > close){
        cout<<"BW-Solid";
    }else if(open < close){
        cout<<"R-Hollow";
    }else {
        cout<<"R-Cross";
    }

    int flag = 0;

    if (low < close && low < open){
        flag = flag | 1;
    }
    if (high > close && high > open){
        flag = flag | 2;
    }

    if ((flag & 3) == 1){
        cout<<" with Lower Shadow";    
    }
    if((flag & 3) == 2){
        cout<<" with Upper Shadow";
    }
    if((flag & 3) == 3){
        cout<<" with Lower Shadow and Upper Shadow";
    }
    cout<<endl;

    return 0;
}