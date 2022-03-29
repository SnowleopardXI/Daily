#include <iostream>
using namespace std;

class CDate
{
private:
    int year;
    int month;
    int day;
public:
    CDate()
    {
        year = 1970;
        month = 1;
        day = 1;
        cout<<"No parameter constructor is called"<<endl;
    }
    CDate(int a, int b, int c)
    {
        year = a;
        month = b;
        day = c;
    }
    ~CDate()
    {
        cout << "析构函数被调用" << endl;
    }
    void display()
    {
        cout << year<<"年"<<month<<"月"<<day<<"日"<<endl;
    }
};
int main()
{
    CDate obj1;
    obj1.display();
    CDate obj2(2002, 11, 9);
    obj2.display();
    return 0;
}