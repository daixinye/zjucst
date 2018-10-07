#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);

    int a = n / 16;
    int b = n % 16;

    printf("%d\n", a*10+b);

    return 0;
}