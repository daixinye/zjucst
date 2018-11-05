#include <iostream>
using namespace std;

class Father
{
    int f;
};
class Son : public Father
{
    int s;
};

void func(Father s){

}

void func2(Son s){

}

int main()
{
    Father f;
    Son s;
    func(s);
    func2(f);
    return 0;
}