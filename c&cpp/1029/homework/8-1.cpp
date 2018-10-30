#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Student
{
  public:
    string name;
    int score;
    Student(string n, int s) : name(n), score(s)
    {
    }
    bool operator<(const Student &other) const
    {
        return this->score < other.score;
    }
};

class StudentList
{
  public:
    list<Student> slist;
    void insertStudentScore(string name, int score)
    {
        Student s(name, score);
        slist.push_back(s);
    }
    int findStudentScoreByName(string name)
    {
        list<Student>::iterator it;
        it = slist.begin();

        while (it != slist.end())
        {
            if (it->name == name)
            {
                return it->score;
            }
            it++;
        }
        return -1;
    }
    void sortStudentList()
    {
        slist.sort();
    }
    void displayStudentScore()
    {
        list<Student>::iterator it;
        it = slist.begin();
        while (it != slist.end())
        {
            cout << it->name << ": " << it->score << endl;
            it++;
        }
    }
};

int main()
{
    StudentList sl;
    sl.insertStudentScore("Alice", 95);
    sl.insertStudentScore("Bob", 100);
    sl.insertStudentScore("Cindy", 85);

    sl.displayStudentScore();
    sl.sortStudentList();
    sl.displayStudentScore();
    cout<<sl.findStudentScoreByName("Alice")<<endl;

    return 0;
}