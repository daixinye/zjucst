#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    bool zeroFlag = true;
    int d;

    while(n){
        d = n % 10;
        n = n / 10;
        if( d > 0 ){
            zeroFlag = false;
        }

        if(!zeroFlag){
            printf("%d", d);
        }
    }
    printf("\n");

    return 0;
}