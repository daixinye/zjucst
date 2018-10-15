#include <iostream>
#include <string>
using namespace std;

/* 请在这里填写答案 */
class Student
{
  protected:
    string num;
    string name;
    static int line;

  public:
    virtual void display() = 0;
    // 注意虚函数析构函数
    virtual ~Student(){

    };
};
int Student::line = 0;

class GroupA : public Student
{
  protected:
    int s1;
    int s2;

  public:
    GroupA(string num, string name, int s1, int s2)
    {
        this->num = num;
        this->name = name;
        this->s1 = s1;
        this->s2 = s2;

        line = s1 + s2 > line ? s1 + s2 : line;
    }
    void display()
    {
        if (s1 + s2 == line)
        {
            cout << num << " " << name << endl;
        }
        return;
    }
};

class GroupB : public Student
{
  protected:
    int s1;
    int s2;
    char gs;

  public:
    GroupB(string num, string name, int s1, int s2, char gs)
    {
        this->num = num;
        this->name = name;
        this->s1 = s1;
        this->s2 = s2;
        this->gs = gs;

        line = s1 + s2 > line ? s1 + s2 : line;
    }
    void display()
    {
        if (((s1 + s2) >= 0.7 * line && gs == 'A') || (s1 + s2 == line))
        {
            cout << num << " " << name << endl;
        }
        return;
    }
};

class GroupC : public Student
{
  protected:
    int s1;
    int s2;
    int s3;
    int s4;
    int s5;

  public:
    GroupC(string num, string name, int s1, int s2, int s3, int s4, int s5)
    {
        this->num = num;
        this->name = name;
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        this->s4 = s4;
        this->s5 = s5;

    }
    void display()
    {
        if ((s1 + s2 + s3 + s4 + s5) >= 2.25 * line)
        {
            cout << num << " " << name << endl;
        }
        return;
    }
};

int main()
{
    const int Size = 50;
    string num, name;
    int i, ty, s1, s2, s3, s4, s5;
    char gs;
    Student *pS[Size];
    int count = 0;
    for (i = 0; i < Size; i++)
    {
        cin >> ty;
        if (ty == 0)
            break;
        cin >> num >> name >> s1 >> s2;
        switch (ty)
        {
        case 1:
            pS[count++] = new GroupA(num, name, s1, s2);
            break;
        case 2:
            cin >> gs;
            pS[count++] = new GroupB(num, name, s1, s2, gs);
            break;
        case 3:
            cin >> s3 >> s4 >> s5;
            pS[count++] = new GroupC(num, name, s1, s2, s3, s4, s5);
            break;
        }
    }
    for (i = 0; i < count; i++)
    {
        pS[i]->display();
        delete pS[i];
    }
    return 0;
}