#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int h, m, s, add;
        scanf("%d:%d:%d", &h, &m, &s);
        cin >> add;

        s = s + add;
        m += s / 60;
        h += m / 60;

        s = s % 60;
        m = m % 60;
        h = h % 24;
        printf("time: %d:%d:%d\n", h, m, s);
    }
    return 0;
}