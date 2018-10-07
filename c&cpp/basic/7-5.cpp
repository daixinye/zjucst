#include <iostream>
#include <string>
using namespace std;
const int ROWS = 9;

int main(){
    string s[] = {
        "------------------------------------",
        "Province      Area(km2)   Pop.(10K)",
        "------------------------------------",
        "Anhui         139600.00   6461.00",
        "Beijing        16410.54   1180.70",
        "Chongqing      82400.00   3144.23",
        "Shanghai        6340.50   1360.26",
        "Zhejiang      101800.00   4894.00",
        "------------------------------------"
    };

    for(int i = 0; i < ROWS; i++){
        cout<<s[i]<<endl;
    }

    return 0;
}