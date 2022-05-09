#include <iostream>
using namespace std;
class Time
{
private:
    int min, sec;

public:
    Time(int m, int s)
    {
        min = m;
        sec = s;
    }
    void display()
    {
        cout << min << ":" << sec << endl;
    }
    Time& operator--()
    {
        if (sec == 0)
        {
            sec = 59;
            min--;
        }
        else
            sec--;
        return *this;
    }
};
int main()
{
    Time t(2, 5);
    for (int i = 1; i< 10; i++)
    {
        --t;
        t.display();
    }
    return 0;
}