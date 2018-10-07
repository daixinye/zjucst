#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

double func1(double x)
{
    return 3.0 - exp(2 * x + 1.0);
}

double func2(double x)
{
    return 2.0 * x - 1.0;
}

double func3(double x)
{
    return 2.0 * log10f(3.0 * x + 5.0) - 11.0;
}

int main()
{
    double x;
    cin >> x;
    double r;
    if (x <= -2)
    {
        r = func1(x);
    }
    if (-2 < x && x <= 3)
    {
        r = func2(x);
    }
    if(x > 3){
        r = func3(x);
    }
    printf("y=%lf", r);
    return 0;
}
