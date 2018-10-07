#include <iostream>
using namespace std;

// 两个int
int Maxl(int a, int b){
    return a > b ? a : b;
}

// 三个int
int Maxl(int a, int b, int c){
    int max = a > b ? a : b;
    max = max > c ? max : c;
    return max;
}

// 两个double
double Maxl(double a, double b){
    return a > b ? a : b;
}

// 三个double
double Maxl(double a, double b, double c){
    double max = a > b ? a : b;
    max = max > c ? max : c;
    return max; 
}

int main(){
    cout<<Maxl(1,2)<<endl;
    cout<<Maxl(1,2,3)<<endl;
    cout<<Maxl(1.0,2.0)<<endl;
    cout<<Maxl(1.0,2.0,3.0)<<endl;
    return 0;
}