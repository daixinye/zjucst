#include <iostream>
using namespace std;
class IndexError
{
};
template <typename T>
class ARRAY
{
    size_t m_size;
    T *m_ptr;

  public:
    ARRAY(size_t size) : m_size(size)
    {
        m_ptr = new T[size];
        memset(m_ptr, 0, size * sizeof(int));
    }
    ~ARRAY()
    {
        delete[] m_ptr;
    }
    T &at(int index);
};

template <typename T>

T &ARRAY<T>::at(int index)
{
    if (index < 0 ||
        index > m_size - 1)
    {

        throw IndexError();
    }
    return m_ptr[index];
}

int main()
{
    ARRAY<int> a(50);
    int i;
    cin >> i;

    try
    {
        for (int j = 0; j < i; j++)
            a.at(i) = j;
    }
    catch (IndexError e)
    {
        return 0;
    }
    return 0;
}