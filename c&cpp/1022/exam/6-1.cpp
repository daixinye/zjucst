#include <iostream>
using namespace std;

/* 请在这里填写答案 */
template <class T>
class MyArray
{
  private:
    int size;
    T *data;

  public:
    MyArray(int s) : size(s)
    {
        data = new T[s];
        for (int i = 0; i < size; i++)
        {
            cin >> data[i];
        }
    }
    ~MyArray();
    bool check();
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
    };
    void display()
    {
        for (int i = 0; i < size - 1; i++)
        {
            cout << data[i] << " ";
        }
        cout << data[size - 1] << endl;
    };
};

template <class T>
MyArray<T>::~MyArray() { delete[] data; }

template <class T>
bool MyArray<T>::check()
{
    int i;
    for (i = 0; i < size - 1; i++)
        if (data[i] > data[i + 1])
        {
            cout << "ERROR!" << endl;
            return false;
        }
    return true;
}
int main()
{
    MyArray<int> *pI;
    MyArray<float> *pF;
    MyArray<char> *pC;
    int ty, size;
    cin >> ty;
    while (ty > 0)
    {
        cin >> size;
        switch (ty)
        {
        case 1:
            pI = new MyArray<int>(size);
            pI->sort();
            pI->check();
            pI->display();
            delete pI;
            break;
        case 2:
            pF = new MyArray<float>(size);
            pF->sort();
            pF->check();
            pF->display();
            delete pF;
            break;
        case 3:
            pC = new MyArray<char>(size);
            pC->sort();
            pC->check();
            pC->display();
            delete pC;
            break;
        }
        cin >> ty;
    }
    return 0;
}
