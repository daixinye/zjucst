#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double THRESHOLD = 0.001;

double f(double a3, double a2, double a1, double a0, double x)
{
    return a3 * pow(x, 3) + a2 * pow(x, 2) + a1 * x + a0;
}

int main()
{
    double a3, a2, a1, a0;
    cin >> a3 >> a2 >> a1 >> a0;
    double a, b;
    cin >> a >> b;

    double mid;
    do
    {
        mid = (a + b) / 2;
        double f_r = f(a3, a2, a1, a0, mid);
        if (f_r == 0)
        {
            break;
        }
        if (f_r * f(a3, a2, a1, a0, a) > 0)
        {
            a = mid;
        }
        else
        {
            b = mid;
        }
    } while (abs(a - b) >= 0.001);
    printf("%.2f\n", mid);
    return 0;
}