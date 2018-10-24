#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class Array
{
  private:
    int size;
    int cur;
    T *data;

  public:
    Array(int s) : size(s)
    {
        data = new T[s];
        cur = 0;
    }
    ~Array()
    {
        delete[] data;
    }
    void display()
    {
        for (int i = 0; i < size - 1; i++)
        {
            cout << data[i] << " ";
        }
        cout << data[size - 1] << endl;
    }
    void sort()
    {
        T temp;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i; j < size - 1; j++)
            {
                if (data[i] > data[j + 1])
                {
                    temp = data[i];
                    data[i] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
    int find(T target)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == target)
            {
                return i;
            }
        }
        return -1;
    }
    void push(T t)
    {
        data[cur++] = t;
    }
};

template <class T>
void printInfo(int n, T target, Array<T> *a)
{
    cout << "arr" << n + 1 << ":" << endl;
    cout << "原序列:";
    a->display();

    cout << "在"
         << "arr" << n + 1 << "中的位置:";
    cout << a->find(target) << endl;

    a->sort();
    cout << "排序后:";
    a->display();
}

int main()
{
    int lines = 0;
    string line, tmp;

    while (getline(cin, line))
    {
        if (line.length() == 0)
        {
            continue;
        }
        // 输入数组
        stringstream inputCount(line);
        int size = 0;
        while (getline(inputCount, tmp, ','))
        {
            size++;
        }
        stringstream inputPush(line);

        if (line.find('.') != string::npos)
        {
            // 是浮点数
            Array<float> *a = new Array<float>(size);
            float target;
            cin >> target;

            while (getline(inputPush, tmp, ','))
            {
                a->push(stof(tmp));
            }

            printInfo(lines, target, a);
        }
        else
        {
            // 是整数
            Array<int> *a = new Array<int>(size);
            int target;
            cin >> target;
            while (getline(inputPush, tmp, ','))
            {
                a->push(stoi(tmp));
            }

            printInfo(lines, target, a);
        }

        lines++;
    }
    return 0;
}