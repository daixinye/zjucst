#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    double x, y;

    cin>>x;

    y = x <= 15 ? 4 * x / 3 : 2.5 * x - 17.5;

    printf("%.2f\n", y);

    return 0;
}