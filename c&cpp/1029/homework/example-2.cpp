#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename T>
void showLink(const list<T> &mLink);

template <typename T>
T getArea(list<T> &myLink);

#define INTERVAL 50 //间隔50米
#define PRECISION 8 //小数位数

//自定义类型作为节点
class Node
{
  public:
    double Area; //记录该速度链表的所求出的时间面积，单位未定
    int Num;     //序列号
    list<double> Link;
    Node(const int num)
    {
        double data = -1;
        Num = num;
        cout << "H" << Num << "测量速度:";
        while (data != 0)
        {
            cin >> data;
            if (data != 0)
                Link.push_back(data);
        }
        Area = getArea(Link);
    }
    double getArea(list<double> &myLink)
    {
        double Area;
        list<double>::iterator p = myLink.begin();
        Area = double(1 / (*myLink.begin())) - double(1 / (*(--myLink.end()))); //--myLink.end()才是最后一个节点
        for (p++; p != myLink.end(); p++)
        {
            Area += (1 / (*p)) * 2;
        }
        return Area * INTERVAL / 2; //间隔50米
    }
    void showLink(/*const list<double> &myLink*/)
    {
        if (Link.empty())
        {
            cout << "List is empty" << endl;
        }
        else
        {
            ostream_iterator<double> output(cout, " ");
            copy(Link.begin(), Link.end(), output);
        }
    }
    const bool operator<(const Node &other)
    {
        if (Area < other.Area)
            return true;
        else
            return false;
    }
};

int main()
{
    std::list<Node> LinkList; //注意这里的写法
    std::list<Node>::iterator it;

    int Number = -1, i = 0;
    cout << "请输入路径条数：";
    cin >> Number;
    while (++i <= Number)
    {
        Node node(i);
        LinkList.push_back(node);
    }
    LinkList.sort(); //节点为自定义时，要同时重载<运算符，才能使用sort()
    for (it = LinkList.begin(); it != LinkList.end(); it++)
    {
        cout << "H" << it->Num << "耗时为";
        cout.setf(ios::fixed);
        cout << setprecision(PRECISION) << it->Area << " s,\t测量速度为："; //it->Area 就是 访问节点Node中的Area变量
        cout.unsetf(ios::fixed);
        it->showLink(); //访问自定义类型的节点中的成员函数
        cout << endl;
    }
    return 0;
}
