#include <iostream>
using namespace std;
class CMyClassA
{
    int val;

  public:
    CMyClassA(int);
    void virtual print();
};
CMyClassA::CMyClassA(int arg)
{
    val = arg;
    printf("A:%d\n", val);
}
void CMyClassA::print()
{
    printf("%d\n", val);
    return;
}

/* 在这里填写代码 */
class CMyClassB : public CMyClassA
{
    int val;

  public:
    CMyClassB(int);
    void print();
};
CMyClassB::CMyClassB(int arg) : CMyClassA(15)
{
    val = arg;
    printf("B:%d\n", val);
}
void CMyClassB::print()
{
    printf("%d\n", val);
    return;
}

int main(int argc, char **argv)
{
    CMyClassA a(3), *ptr; // A:3
    CMyClassB b(5);       // B:5
    ptr = &a;
    ptr->print(); // 3
    a = b;
    a.print(); // 15
    ptr = &b;
    ptr->print(); // 5
    return 0;
}