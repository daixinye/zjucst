#include <iostream>
#include <string>
using namespace std;
#define C 5

class Animal
{
  public:
    string name;
    Animal(string name) : name(name) {}
    virtual bool eat(Animal &) = 0;
    virtual int getType() = 0;
};

class Cage
{
    Animal *a1, *a2;
    void setAnimal1(Animal &);
    void setAnimal2(Animal &);

  public:
    Cage();
    bool arrange(Animal &);
    bool remove(string &);
    Animal *getRoommate(Animal &);
};

bool Cage::arrange(Animal &a)
{
    if (a1 == NULL && a2 == NULL)
    {
        setAnimal1(a);
        return true;
    }
    if (a1 == NULL && a2 != NULL && !a2->eat(a) && !a.eat(*a2))
    {
        setAnimal1(a);
        return true;
    }
    if (a1 != NULL && !a1->eat(a) && !a.eat(*a1) && a2 == NULL)
    {
        setAnimal2(a);
        return true;
    }
    return false;
}

/* 请在这里填写答案 */

//Cage 实现
Cage::Cage() : a1(NULL), a2(NULL)
{
}
void Cage::setAnimal1(Animal &a)
{
    a1 = &a;
}
void Cage::setAnimal2(Animal &a)
{
    a2 = &a;
}
bool Cage::remove(string &name)
{

    if (a1 != NULL && a1->name == name)
    {
        a1 = NULL;
        return true;
    }
    if (a2 != NULL && a2->name == name)
    {
        a2 = NULL;
        return true;
    }
    return false;
}
Animal *Cage::getRoommate(Animal &animal)
{
    if (&animal == a1)
    {
        return a2;
    }
    if (&animal == a2)
    {
        return a1;
    }
    return NULL;
}

// 普通函数 remove
void remove(Cage *cage, string &name)
{
    for (int i = 0; i < C; i++)
    {
        if (cage[i].remove(name))
        {
            cout << "cage:" << i << endl;
            cout << name << " removed!" << endl;
            return;
        }
    }
    cout << name << " NOT found!" << endl;
    return;
}

// Tiger 类
class Tiger : public Animal
{
  public:
    int type;
    // 构造方法
    Tiger(string name) : Animal(name), type(3)
    {
    }
    // 基类虚函数实现
    bool eat(Animal &a)
    {
        return type > a.getType() ? true : false;
    }
    int getType()
    {
        return type;
    }
};
// Wolf 类
class Wolf : public Animal
{
  public:
    int type;
    Wolf(string name) : Animal(name), type(2)
    {
    }
    bool eat(Animal &a)
    {
        return type > a.getType() ? true : false;
    }
    int getType()
    {
        return type;
    }
};
// Sheep 类
class Sheep : public Animal
{
  public:
    int type;
    Sheep(string name) : Animal(name), type(1)
    {
    }
    bool eat(Animal &a)
    {
        return type > a.getType() ? true : false;
    }
    int getType()
    {
        return type;
    }
};

bool arrange(Cage *cage, Animal &a)
{
    int i;
    Animal *p;
    for (i = 0; i < C; i++)
    {
        if (!cage[i].arrange(a))
            continue;
        cout << "cage:" << i << endl;
        p = cage[i].getRoommate(a);
        if (p != NULL)
            cout << "roommate:" << p->name << endl;
        return true;
    }
    return false;
}

int main()
{
    Cage cage[C];
    Wolf *pW;
    Tiger *pT;
    Sheep *pS;
    string name;
    bool state = true;
    int type;

    while (cin >> type)
    {
        cin >> name;
        switch (type)
        {
        case 1:
            pT = new Tiger(name);
            state = arrange(cage, *pT);
            break;
        case 2:
            pS = new Sheep(name);
            state = arrange(cage, *pS);
            break;
        case 3:
            pW = new Wolf(name);
            state = arrange(cage, *pW);
            break;
        case 4:
            remove(cage, name);
            break;
        }
        if (!state)
            break;
    }
    return 0;
}