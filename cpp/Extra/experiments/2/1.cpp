#include <iostream>
using namespace std;
class Time //声明Time类
{
public:
    Time(int = 0, int = 0, int = 0); // 带默认参数的构造函数

    // set functions
    void setTime(int, int, int); // 设置hour, minute, second
    void setHour(int &h);           // 设置hour (确保数据在合理范围)
    void setMinute(int &m);         // 设置minute (确保数据在合理范围)
    void setSecond(int &s);         // 设置second (确保数据在合理范围)

    // get functions
    int getHour();   // 返回 hour
    int getMinute(); // 返回 minute
    int getSecond(); // 返回 second

    void printUniversal(); // 按24小时格式输出时间：23:56:12
    void printStandard();  // 按12小时格式输出时间：11:56:12 (PM) 或 9:23:55(AM)
private:
    int hour;   // 0 - 23 (24小时格式)
    int minute; // 0 - 59
    int second; // 0 - 59
};              // Timel类定义结束
void Time::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}
void Time::setHour(int &h)
{
    hour = (h >= 0 && h < 24) ? h : 0;
}
void Time::setMinute(int &m)
{
    minute = (m >= 0 && m < 60) ? m : 0;
}
void Time::setSecond(int &s)
{
    second = (s >= 0 && s < 60) ? s : 0;
}
int Time::getHour()
{
    return hour;
}
int Time::getMinute()
{
    return minute;
}
int Time::getSecond()
{
    return second;
}
void Time::printUniversal()
{
    cout << getHour() << ":" << getMinute() << ":" << getSecond();
}
void Time::printStandard()
{
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << getMinute() << ":" << getSecond() << (getHour() < 12 ? " AM" : " PM");
}
Time::Time(int h, int m, int s)
{
    setTime(h, m, s);
}
int main()
{
    Time t1(12, 34, 56);
    t1.printUniversal();
    cout << endl;
    return 0;
}