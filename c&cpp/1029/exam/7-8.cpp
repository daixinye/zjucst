#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool check(vector<vector<char> > &net, string word, vector<vector<bool> > visited, int i, int j, int index)
    {
        if (index == word.length())
        {
            return true;
        }

        if (i < 0 || j < 0 || j >= net.size() || i >= net[0].size())
        {
            return false;
        }

        if (visited[j][i])
        {
            return false;
        }

        if (word[index] != net[j][i])
        {
            return false;
        }

        visited[j][i] = true;

        bool result = check(net, word, visited, i - 1, j, index + 1) ||
                      check(net, word, visited, i + 1, j, index + 1) ||
                      check(net, word, visited, i, j - 1, index + 1) ||
                      check(net, word, visited, i, j + 1, index + 1);

        visited[j][i] = false;

        return result;
    }

int main()
{
    vector<vector<char> > net;

    int m, n;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        vector<char> row;
        char temp;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            row.push_back(temp);
        }
        net.push_back(row);
    }

    vector<vector<bool> > visited(net.size(), vector<bool>(net[0].size()));
    string word;
    cin >> word;

    for (int y = 0; y < net.size(); y++)
    {
        for (int x = 0; x < net[0].size(); x++)
        {
            if (check(net, word, visited, x, y, 0))
            {
                cout << "Exist" << endl;
                return 0;
            }
        }
    }
    cout << "Not exist" << endl;
    return 0;
}