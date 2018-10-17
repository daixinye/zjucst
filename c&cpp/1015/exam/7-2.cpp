#include <iostream>
#include <string>
using namespace std;

class Pet
{
  protected:
    string name; // 姓名
    int length;  // 身高
    int weight;  // 体重
    int current; // 当前日期
  public:
    Pet(string n, int l, int w, int c) : name(n), length(l), weight(w), current(c)
    {
    }
    // 输出目标日期的身高和体重
    virtual void display(int day) = 0;
};

class Cat : public Pet
{
  public:
    Cat(string n, int l, int w, int c) : Pet(n, l, w, c)
    {
    }
    void display(int day)
    {
        cout << name << " " << length + (day - current) * 1 << " " << weight + (day - current) * 2 << endl;
    }
};

class Dog : public Pet
{
  public:
    Dog(string n, int l, int w, int c) : Pet(n, l, w, c)
    {
    }
    void display(int day)
    {
        cout << name << " " << length + (day - current) * 2 << " " << weight + (day - current) * 1 << endl;
    }
};

int main()
{
    Pet *pt[10];
    int count = 0;
    int n;
    while (cin >> n)
    {
        if (n > 10)
        {
            break;
        }
        else
        {
            string name;
            int length;
            int weight;
            int cur;
            cin >> name >> length >> weight >> cur;

            if (n == 1)
            {
                pt[count] = new Cat(name, length, weight, cur);
            }
            if (n == 2)
            {
                pt[count] = new Dog(name, length, weight, cur);
            }
            count++;
        }
    }

    for (int i = 0; i < count; i++)
    {
        pt[i]->display(n);
    }
    return 0;
}