#include <iostream>
using namespace std;

int main()
{
    int A;
    cin >> A;
    const int LEN = A + 4;
    bool whitespace = false;

    for (int i = A; i < LEN; i++)
    {
        whitespace = false;
        for (int j = A; j < LEN; j++)
        {
            for (int h = A; h < LEN; h++)
            {
                if (i != j && i != h && j != h)
                {
                    if (whitespace)
                    {
                        cout << " ";
                    }
                    cout << i << j << h;
                    whitespace = true;
                }
            }
        }
        cout << endl;
    }
    return 0;
}