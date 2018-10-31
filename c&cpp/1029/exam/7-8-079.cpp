#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
    

  public:
    bool exist(vector<vector<char> > &board, string word)
    {
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size()));
        
        for (int y = 0; y < board.size(); y++)
        {
            for (int x = 0; x < board[0].size(); x++)
            {
                if (check(board, word, visited, x, y, 0))
                {
                    cout << "Exist" << endl;
                    return 0;
                }
            }
        }
        cout << "Not exist" << endl;
        return 0;
    }
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
};