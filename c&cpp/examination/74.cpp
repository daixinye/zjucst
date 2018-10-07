#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class MyQueue
{
  private:
  public:
    vector<int> q;
    void push(int x);
    int pop();
    int size();
};

void MyQueue::push(int x)
{
    this->q.push_back(x);
}

int MyQueue::size()
{
    return this->q.size();
}

int MyQueue::pop()
{
    if (this->q.empty())
    {
        cout << "Invalid" << endl;
    }
    else
    {
        cout << this->q.front() <<endl;
        this->q.erase(this->q.begin()+0);
    }
    return 0;
}

int main()
{
    MyQueue mq;

    int n;
    cin >> n;

    while (n--)
    {
        int a, b;
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            mq.push(b);
        }

        if (a == 2)
        {
            mq.pop();
        }

        if(a==3){
            cout<<mq.size()<<endl;
        }
    }

    return 0;
}
