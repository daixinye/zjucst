#include <iostream>
#include <string>
using namespace std;

class Pet
{
  public:
    // speak 虚函数
    virtual string speak() const { return "pet!"; }
};
class Dog : public Pet
{
  public:
    string speak() const { return "dog!"; }
    void test(){
        cout<<"test"<<endl;
    }
};
int main()
{
    Dog ralph;
    Pet *p1 = &ralph;
    // 别名
    Pet &p2 = ralph;
    Pet p3;
    // p1 是基类指针，指向Dog对象实例
    cout << p1->speak() << endl;
    // p2 是派生类指针
    cout << p2.speak() << endl;
    cout << p3.speak() << endl;
    return 0;
}