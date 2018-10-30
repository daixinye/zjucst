#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

bool compare(int a, int b)
{
    string A = to_string(a);
    string B = to_string(b);

    int la = A.length(), lb = B.length();

    int ia = 0, ib = 0;
    while (ia < la && ib < lb)
    {
        if (A[ia] < B[ib])
        {
            return false;
        }
        else if (A[ia] > B[ib])
        {
            return true;
        }
        ia++;
        ib++;
    }

    return stoi(A + B) > stoi(B + A);
}

void display(vector<int> &nums)
{
    vector<int>::iterator it = nums.begin();

    while (it != nums.end())
    {
        cout << *it;
        it++;
    }
    cout << endl;
}

int main()
{
    int n, m;
    while (cin >> n)
    {

        vector<int> nums;
        while (n--)
        {
            cin >> m;
            nums.push_back(m);
        }

        stable_sort(nums.begin(), nums.end(), compare);

        display(nums);
    }
}