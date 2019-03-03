#include <iostream>
using namespace std;

// https://www.nowcoder.com/practice/440f16e490a0404786865e99c6ad91c9?tpId=37&tqId=21238&tPage=1&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking

int main()
{
  int n;
  cin >> n;
  int count = 0;

  while (n)
  {
    bool isOne = ((n & 1) == 1);
    count += isOne ? 1 : 0;
    n = n >> 1;
  }
  cout << count << endl;
  return 0;
}
