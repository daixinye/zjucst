#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int A, B;
    cin>>A>>B;

    int sum = 0;
    for(int i = A; i <= B; i++ ) {
        sum = sum + i;
        printf("%5d", i);

        if( (i + 1 - A) % 5 == 0 ){
            printf("\n");
        }
    }
    // 循环结束再输出一次换行
    if( (B+1-A) % 5 != 0){
        printf("\n");
    }

    // 输出sum
    printf("Sum = %d\n", sum);
    return 0;
}