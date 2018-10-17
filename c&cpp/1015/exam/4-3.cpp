#include <iostream>
using namespace std;

enum NOTE
{
    middleC,
    Csharp,
    Cflat
};
class Instrument
{
  public:
    virtual void play(NOTE) const = 0;
    virtual char *what() const = 0;
    virtual void adjust(int) = 0;
};

class Wind : public Instrument
{
  public:
    void play(NOTE) const
    {
        cout << 1 << endl;
    }
    char *what() const { return "Wind"; }
    void adjust(int) {}
};

class Percussion : public Instrument
{
  public:
    void play(NOTE) const
    {
        cout << 2 << endl;
    }
    char *what() const { return "Percussion"; }
    void adjust(int) {}
};

class Stringed : public Instrument
{
  public:
    void play(NOTE) const
    {
        cout << 3 << endl;
    }
    char *what() const { return "Stringed"; }
    void adjust(int) {}
};

class Brass : public Wind
{
  public:
    void play(NOTE) const
    {
        cout << 11 << endl;
    }
    char *what() const { return "Brass"; }
};

class Woodwind : public Wind
{
  public:
    void play(NOTE) const
    {
        cout << 12 << endl;
    }
    char *what() const { return "Woodwind"; }
};

void tune(Instrument &i)
{
    i.play(middleC);
}

void f(Instrument &i) { i.adjust(1); }

int main()
{
    Wind flute;
    Percussion drum;
    Stringed violin;
    Brass flugelhorn;
    Woodwind recorder;
    tune(flute);
    tune(drum);
    tune(violin);
    tune(flugelhorn);
    tune(recorder);
    f(flugelhorn);
    return 0;
}