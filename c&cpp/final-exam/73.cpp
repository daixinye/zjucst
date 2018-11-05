#include <iostream>
using namespace std;

int main()
{
    int m, n;
    int map[100][100];
    int value[100][100];
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[m][n];
        }
    }

    for (int i = 0; i < m; i++)
    {
        value[i][0] = map[i][0] == 0 ? 1 : 0;
    }

    for (int j = 0; j < n; j++)
    {
        value[0][j] = map[0][j] == 0 ? 1 : 0;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (map[i][j] == 0)
            {
                value[i][j] = value[i - 1][j] + value[i][j - 1];
            }
            else
            {
                value[i][j] = 0;
            }
        }
    }

    cout << value[m - 1][n - 1] << endl;

    return 0;
}