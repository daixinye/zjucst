#include <iostream>
using namespace std;

template <typename T>
void max(T a, T b, T &c)
{
    c = a + b;
}

int main()
{
    double a = 1, b = 2, c = 0;
    max(a, b, c);
    cout << c << endl;
    return 0;
}