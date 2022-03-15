#include <iostream>
using namespace std;
class RationalNumber
{
private:
    int a, b; // a为分子，b为分母
public:
    // construtors
    RationalNumber(); //默认值分子为0，分母为1
    RationalNumber(int, int); //判断如果用户传入分母为0，设置分母为1
    RationalNumber(const RationalNumber &); //复制构造函数
    // getters
    int getNumerator(); //分子
    int getDenominator(); //分母
    // setters
    void setNumerator(int); //分子
    void setDenominator(int); //分母,如果分母为0，设置为1
    //其他成员函数
    void standardize(); //输出标准化工作，判断如果a和b都是负数，把它们都变成正数；如果a是正b是负，把a变成负b变成正，这样可以使得输出时分母中不出现负号
    void print(); //输出a/b的格式，输出前调用standardize()
    double toDouble(); //得到a/b的double值，注意不要整除
};
int main()
{
    RationalNumber r1, r2(-5, 6);
    RationalNumber *r3 = new RationalNumber();
    RationalNumber *r4;
    r4 = new RationalNumber(4, -6);
    cout << "r1 numerator is " << r1.getNumerator() << endl;
    cout << "r3 denominator is " << r3->getDenominator() << endl;
    r2.setDenominator(-10);
    cout << "r2 is now ";
    r2.print();
    cout << "r1 = ";
    r1.print();
    cout << "r2 = ";
    r2.print();
    cout << "r3 = ";
    r3->print();
    cout << "r4 = ";
    r4->print();
    cout << "In double format, r4= " << r4->toDouble() << endl;
    delete r3;
    delete r4;
    return 0;
}
RationalNumber::RationalNumber()
{
    a = 0;
    b = 1;
}
RationalNumber::RationalNumber(int numerator, int denominator)
{
    a = numerator;
    b = denominator;
    b=b==0?1:b;
}
RationalNumber::RationalNumber(const RationalNumber &r)
{
    a = r.a;
    b = r.b;
}
int RationalNumber::getNumerator()
{
    return a;
}
int RationalNumber::getDenominator()
{
    return b;
}
void RationalNumber::setNumerator(int numerator)
{
    a = numerator;
}
void RationalNumber::setDenominator(int denominator)
{
    if (denominator == 0)
        b = 1;
    else
        b = denominator;
}
void RationalNumber::standardize()
{
    if (a < 0 && b < 0)
    {
        a = -a;
        b = -b;
    }
    else if (a > 0 && b < 0)
    {
        a = -a;
        b = -b;
    }
}
void RationalNumber::print()
{
    standardize();
    cout << a << "/" << b << endl;
}
double RationalNumber::toDouble()
{
    return (double)a / b;
}