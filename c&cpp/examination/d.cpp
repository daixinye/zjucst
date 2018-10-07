#include <iostream>
#include <string>
using namespace std;

/* 请在这里填写答案 */
class Animal {
    public:
        void speak(){
            cout<<"animal language!"<<endl;
        }
};

class Cat : public Animal {
    private:
        string m_strName;
    public:
        Cat(string s){
           this->m_strName = s; 
        };
        void print_name(){
            cout<<"cat name: "<<this->m_strName<<endl;
        }
};

int main()
{
    Cat cat("Persian"); //定义派生类对象
    cat.print_name();	//派生类对象使用本类成员函数
    cat.speak();	//派生类对象使用基类成员函数
    return 0;
}