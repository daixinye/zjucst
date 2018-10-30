#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
 
struct Test{
    int val;
    string name;
    Test(string n, int x) : name(n), val(x) { }
};
 
bool nonmem_cmp(const Test &t1, const Test &t2)
{
    if(t1.val > t2.val)
        return true;
    return false;
}
 
void print_res(Test t)
{
    cout << t.val << " ";
}
 
int main(int argc, char *argv[])
{
    list<Test> ivec;
    ivec.push_back(Test("t",6));
    ivec.push_back(Test("t", 4));
    ivec.push_back(Test("t",8));
    ivec.push_back(Test("t",2));
    ivec.push_back(Test("t",1));
 
    sort(ivec.begin(), ivec.end(), nonmem_cmp);
    for_each(ivec.begin(), ivec.end(), print_res);
    cout << endl;
 
    return 0;
}
