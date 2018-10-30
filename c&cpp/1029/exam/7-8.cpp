#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<string> USED;
vector< vector<char> > NET;

void display(vector< vector<char> > net)
{
    for (int i = 0; i < net.size(); i++)
    {
        for (int j = 0; j < net[i].size(); j++)
        {
            cout << net[i][j] << " ";
        }
        cout << endl;
    }
}

bool isUsed(int x, int y)
{
    string find = to_string(x) + to_string(y);
    set<string>::iterator it;
    it = USED.find(find);
    return it != USED.end();
}

void setUsed(int x, int y)
{
    USED.insert(to_string(x) + to_string(y));
}

bool validXY(int x, int y)
{
    return x >= 0 && y >= 0 && y < NET.size() && x < NET[0].size();
}

bool check(string target, int i, int x, int y, int from_x, int from_y)
{
    if (isUsed(x, y))
    {
        return false;
    }
    
    char c = target[i];
    if (validXY(x,y) && c == NET[y][x])
    {
        if (i == target.length()-1)
        {
            return true;
        }
        setUsed(x, y);
        // 检查 上 (x, y+1)
        bool up = validXY(x, y + 1) && check(target, i + 1, x, y + 1, x, y);
        // 检查 下 (x, y-1)
        bool down = validXY(x, y - 1) && check(target, i + 1, x, y - 1, x, y);
        // 检查 左 (x, y-1)
        bool left = validXY(x - 1, y) && check(target, i + 1, x - 1, y, x, y);
        // 检查 右 (x+1, y)
        bool right = validXY(x + 1, y) && check(target, i + 1, x + 1, y, x, y);

        return up || down || left || right;
    }

    return false;
}

int main()
{
    int m, n;
    cin >> n >> m;

    for (int i = 1; i < m; i++)
    {
        vector<char> row;
        char temp;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            row.push_back(temp);
        }
        NET.push_back(row);
    }

    string target;
    cin >> target;

    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            USED.clear();
            if (check(target, 0, x, y, x, y))
            {
                cout << "Exist" << endl;
                return 0;
            }
        }
    }
    cout << "Not Exist" << endl;
    return 0;
}