#include <iostream>
using namespace std;

class Shape
{
  public:
    virtual double GetArea() = 0;
    virtual double GetPerim() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
  private:
    double width;
    double length;

  public:
    Rectangle(double width, double length)
    {
        this->width = width;
        this->length = length;
    }
    double GetArea()
    {
        return width * length;
    }
    double GetPerim()
    {
        return 2 * (width + length);
    }
};

class Circle : public Shape
{
  private:
    double radius;
    const double PI;

  public:
    Circle(double radius) : PI(3.1415)
    {
        this->radius = radius;
    }
    double GetArea()
    {
        return PI * radius * radius;
    }
    double GetPerim()
    {
        return 2 * PI * radius;
    }
};

int main()
{
    Rectangle rect(3, 4);
    cout << rect.GetArea() << endl;
    cout << rect.GetPerim() << endl;

    Circle cir(5);
    cout << cir.GetArea() << endl;
    cout << cir.GetPerim() << endl;
    return 0;
}