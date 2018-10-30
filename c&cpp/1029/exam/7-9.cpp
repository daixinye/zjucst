#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num;
    vector<int> list;
    while (n--)
    {
        cin >> num;
        list.push_back(num);
    }

    int count = 1;
    for (int i = 0; i < list.size() - 1; i++)
    {
        int first = list[i];
        int second = list[i + 1];
        int diff = second - first;
        int temp_count = 1;
        if (diff > 0)
        {
            temp_count = 2;
            int j = i + 2;

            while (j < list.size() && list[j] == (first + (j - i) * diff))
            {
                temp_count++;
                j++;
            }
        }
        count = temp_count > count ? temp_count : count;
    }
    cout << count << endl;
    return 0;
}