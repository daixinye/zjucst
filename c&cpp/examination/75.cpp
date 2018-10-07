#include <iostream>
#include <stdio.h>
using namespace std;

class Date
{
  protected:
    int year;

    int month;

    int day;

  public:
    Date(int year, int month, int day)
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }
};

class Time
{
  protected:
    int hour;

    int minute;

    int second;

  public:
    Time(int h, int m, int s)
    {
        this->hour = h;
        this->minute = m;
        this->second = s;
    }
};

class Schedule
{
  public:
    Time *t;
    Date *d;
    int i;
    Schedule(int i, Date &d, Time &t)
    {
        this->t = &t;
        this->d = &d;
        this->i = i;
    }
    bool operator<(const Schedule &s2){};
};

int main()
{

    return 0;
}