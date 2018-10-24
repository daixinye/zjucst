#include <iostream>
#include <string>
using namespace std;

/* 请在这里填写答案 */
template <class T>
void sort(T *a, int size)
{
    for (int h = 0; h < size; h++)
    {
        cin >> a[h];
    }
    T temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i; j < size - 1; j++)
        {
            if (a[i] > a[j + 1])
            {
                temp = a[i];
                a[i] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
};

template <class T>
void display(T *a, int size)
{
    for (int i = 0; i < size - 1; i++)
        cout << a[i] << ' ';
    cout << a[size - 1] << endl;
}
int main()
{
    const int SIZE = 10;
    int a[SIZE];
    char b[SIZE];
    double c[SIZE];
    string d[SIZE];
    int ty, size;
    cin >> ty;
    while (ty > 0)
    {
        cin >> size;
        switch (ty)
        {
        case 1:
            sort(a, size);
            display(a, size);
            break;
        case 2:
            sort(b, size);
            display(b, size);
            break;
        case 3:
            sort(c, size);
            display(c, size);
            break;
        case 4:
            sort(d, size);
            display(d, size);
            break;
        }
        cin >> ty;
    }
    return 0;
}
