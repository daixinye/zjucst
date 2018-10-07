#include <iostream>
#include <stdio.h>
using namespace std;

double fact(int n);

int main()
{
    int m,n;
    cin>>m;
    cin>>n;

    cout<<"result = "<<fact(n)/(fact(m)*fact(n-m))<<endl;

    return 0;
}

double fact(int n)
{
    double r = 1;
    while (n)
    {
        r *= n;
        n--;
    }
    return r;
}
