#include <iostream>
using namespace std;

class Test
{
  private:
    int a;

  public:
    static void get()
    {
        cout << this->a << endl;
    };
};

int main()
{
    return 0;
}