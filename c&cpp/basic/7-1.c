#include <stdio.h>
#include <math.h>

int main(){
    double cm;
    int foot, inch;

    scanf("%lf", &cm);

    inch = floor(cm / 100 / 0.3048 * 12);
    foot = inch / 12;
    inch = inch % 12;

    printf("%d %d\n", foot, inch);

    return 0;
}