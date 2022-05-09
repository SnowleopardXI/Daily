#include <iostream>
#include <string>
using namespace std;
class Time
{
    private:
        int hour;
        int minute;
        int second;
    public:
        Time();
        Time(int h,int m,int s);
        void setTime(int h,int m,int s);
        void print();
};
class Date
{
    private:
        int year;
        int month;
        int day;
    public:
        Date();
        Date(int y,int m,int d);
        void setDate(int y,int m,int d);
        void print();
};
class Birthtime:public Time,public Date
{
    private:
        string Childname;
    public:
        Birthtime();
        Birthtime(string str,int y,int mon,int d,int h,int m,int s);
        void print();
};
Time::Time()
{
    hour=0;
    minute=0;
    second=0;
}
Time::Time(int h,int m,int s)
{
    hour=h;
    minute=m;
    second=s;
}
void Time::setTime(int h,int m,int s)
{
    hour=h;
    minute=m;
    second=s;
}
void Time::print()
{
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}
Date::Date()
{
    year=0;
    month=0;
    day=0;
}
Date::Date(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
}
void Date::setDate(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
}
void Date::print()
{
    cout<<year<<"-"<<month<<"-"<<day<<endl;
}
Birthtime::Birthtime()
{
    Time::setTime(0,0,0);
    Date::setDate(0,0,0);
}
Birthtime::Birthtime(string str,int y,int mon,int d,int h,int m,int s)
{
    Time::setTime(h,m,s);
    Date::setDate(y,mon,d);
    Childname=str;
}
void Birthtime::print()
{
    cout<<Childname<<endl;
    Date::print();
    Time::print();
}
int main()
{
    Birthtime bt1("Test",2002,12,13,01,02,03);
    Birthtime bt2("Test2",2005,12,12,11,12,13);
    bt1.print();
    bt2.print();
    return 0;
}