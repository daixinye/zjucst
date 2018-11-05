#include <iostream>
using namespace std;

typedef int Object;
class Iterator;
class Aggregate;
class ConcreteIterator;

class Aggregate
{
  public:
    virtual ~Aggregate();
    virtual Iterator *create_iterator() = 0;
    virtual Object get_item(int idx) = 0;
    virtual int get_size() = 0;

  protected:
    Aggregate();
};
class ConcreteAggregate : public Aggregate
{
  public:
    enum
    {
        SIZE = 5
    };
    ConcreteAggregate()
    {
        for (int i = 0; i < SIZE; i++)
        {
            m_objs[i] = i;
        }
    };
    ~ConcreteAggregate();
    Iterator *create_iterator()
    {
        return new ConcreteIterator(this, 0);
    };
    Object get_item(int idx)
    {
        if (idx < this->get_size())
        {
            return m_objs[idx];
        }
        return -1;
    };
    int get_size()
    {
        return SIZE;
    };

  private:
    Object m_objs[SIZE];
};

class Iterator
{
  public:
    virtual ~Iterator();
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool is_done() = 0;
    virtual Object current_item() = 0;

  protected:
    Iterator();
};

class ConcreteIterator : public Iterator
{
  public:
    ConcreteIterator(Aggregate *ag, int idx = 0)
    {
        m_ag = ag;
        m_idx = idx;
    };
    ~ConcreteIterator();
    void first()
    {
        m_idx = 0;
    };
    void next()
    {
        if (m_idx < m_ag->get_size())
        {
            m_idx++;
        }
    };
    bool is_done()
    {
        return (m_idx == m_ag->get_size());
    };
    Object current_item()
    {
        return m_ag->get_item(m_idx);
    };

  private:
    Aggregate *m_ag;
    int m_idx;
};
int main()
{
    return 0;
}