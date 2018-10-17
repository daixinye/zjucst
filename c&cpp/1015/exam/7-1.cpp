#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class Date
{
  public:
    int year;
    int month;
    int day;
    Date(int y, int m, int d) : year(y), month(m), day(d)
    {
    }
    bool operator<(const Date &d)
    {
        return (year < d.year) || (year == d.year && month < d.month) || (year == d.year && month == d.month && day < d.day);
    }
    bool operator==(const Date &d)
    {
        return year == d.year && month == d.month && day == d.day;
    }
};

class Time
{

  public:
    int hour;
    int minute;
    int second;
    Time(int h, int m, int s) : hour(h), minute(m), second(s)
    {
    }
    bool operator<(const Time &t)
    {
        return (hour < t.hour) || (hour == t.hour && minute < t.minute) || (hour == t.hour && minute == t.minute && second < t.second);
    }
    bool operator==(const Time &t)
    {
        return hour == t.hour && minute == t.minute && second == t.second;
    }
};

class Schedule
{
  public:
    Time time;
    Date date;
    int ID;

    Schedule(int i, Date &d, Time &t) : ID(i), date(d), time(t)
    {
    }
    bool operator<(const Schedule &s2)
    {
        return date < s2.date || (date == s2.date && time < s2.time);
    }
};
int main()
{
    int n;
    string s;
    Schedule *sche;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }

        int year, month, day, hour, minute, second;
        scanf("%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

        Date *date = new Date(year, month, day);
        Time *time = new Time(hour, minute, second);
        Schedule *schedule = new Schedule(n, *date, *time);
        if (sche == NULL || *schedule < *sche)
        {
            sche = schedule;
        }
    }
    printf("The urgent schedule is No.%d: %d/%d/%d %d:%d:%d\n", sche->ID, sche->date.year, sche->date.month, sche->date.day, sche->time.hour, sche->time.minute, sche->time.second);
    return 0;
}