#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Node
{
  public:
    Node *next;
    int value;
    Node(int v) : value(v), next(NULL)
    {
    }
};

class NodeList
{
  public:
    Node *root;
    NodeList()
    {
        root = new Node(0);
    }
    void insert(int value)
    {
        Node *it = root;
        if (it->next == NULL)
        {
            it->next = new Node(value);
        }
        else
        {
            while (it->next != NULL && it->next->value < value)
            {
                it = it->next;
            }
            Node *node = new Node(value);
            node->next = it->next;
            it->next = node;
        }
    }
    void remove(int value)
    {
        Node *it = root;
        while (it->next != NULL)
        {
            if (it->next->value == value)
            {
                Node *tmp = it->next;
                it->next = it->next->next;
                delete tmp;
                break;
            }
            it = it->next;
        }
    }
    void display()
    {
        Node *it = root;
        if (it->next != NULL)
        {
            while (it->next != NULL)
            {
                it = it->next;
                cout << it->value << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "The list is empty" << endl;
        }
    }
};

int main()
{
    NodeList *list = new NodeList();
    string line, num;
    getline(cin, line);
    stringstream input(line);
    while (getline(input, num, ','))
    {
        list->insert(stoi(num));
    }
    list->display();

    int target;
    cout << "请输入一个要求删除的整数" << endl;
    while (cin >> target)
    {
        list->remove(target);
        list->display();
        cout << "请输入一个要求删除的整数" << endl;
    }
    return 0;
}