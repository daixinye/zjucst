#include <iostream>
#include <cstdio>
using namespace std;

double item(int n)
{
    // 计算分母
    double denominator = 1;
    for (double i = 1; i < 2 * (n + 1); i = i + 2)
    {
        denominator = denominator * i;
    }

    // 计算分子
    double numerator = 1;
    for (double j = 1; j < n + 1; j++)
    {
        numerator = numerator * j;
    }

    return numerator / denominator;
}
int main()
{
    double threshold;
    cin >> threshold;

    double pi = 1;
    int n = 1;
    double cur = item(n);

    while (cur > threshold)
    {
        pi = pi + cur;

        n++;
        cur = item(n);
    }

    pi = pi + cur;

    printf("%.6f\n", 2 * pi);

    return 0;
}