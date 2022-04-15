#include <iostream>
using namespace std;
class RationalNumber
{
private:
    int a, b; // a为分子，b为分母
public:
    // construtors
    RationalNumber(); //用初始化成员列表设置默认值分子为0，分母为1
    RationalNumber(int, int); //分子用普通赋值方法初始化，分母调用set函数初始化
    // getters
    int getNumerator(); //分子
    int getDenominator(); //分母
    // setters
    void setNumerator(int); //分子
    void setDenominator(int); //分母,如果分母为0，设置为1
    //其他成员函数
    void print(); //输出a/b的格式
    RationalNumber operator+(RationalNumber &r);
    RationalNumber operator-(RationalNumber &r);
    friend RationalNumber operator+(const RationalNumber &r1, int i);
    friend RationalNumber operator+(int i, const RationalNumber &r1);
    friend RationalNumber operator-(const RationalNumber &r1, int i);
    friend RationalNumber operator-(int i,const RationalNumber &r1);
};
//有理数类RationalNumber中实现对 + 和 - 运算符重载，使得如下主程序能够输出正确结果。
int main()
{
    RationalNumber r1(2, 3), r2(1, 2), r3(-2, 3), r4, *r5;
    r4 = r1 + r2;
    r5 = new RationalNumber();
    *r5 = r1 - r3;
    r1.print();
    cout << "+";
    r2.print();
    cout << "=";
    r4.print();
    cout << endl;
    r1.print();
    cout << "-";
    r3.print();
    cout << "=";
    r5->print();
    cout << endl;
    r4 = r1 + 3;
    *r5 = 3 + r2;
    r1.print();
    cout << "+3";
    cout << "=";
    r4.print();
    cout << endl;
    cout << "3+";
    r2.print();
    cout << "=";
    r5->print();
    cout << endl;
    r4 = r3 - 3;
    *r5 = 3 - r1;
    r3.print();
    cout << "-3";
    cout << "=";
    r4.print();
    cout << endl;
    cout << "3-";
    r1.print();
    cout << "=";
    r5->print();
    cout << endl;
    delete r5;
    return 0;
}
//构造函数
RationalNumber::RationalNumber():a(0), b(1){}
RationalNumber::RationalNumber(int a, int b)
{
    setNumerator(a);
    setDenominator(b);
}
int RationalNumber::getNumerator()
{
    return a;
}
int RationalNumber::getDenominator()
{
    return b;
}
void RationalNumber::setNumerator(int a)
{
    this->a = a;
}
void RationalNumber::setDenominator(int b)
{
    if (b == 0)
        b = 1;
    this->b = b;
}
void RationalNumber::print()
{
    cout << a << "/" << b;
}
RationalNumber RationalNumber::operator+(RationalNumber &r)
{
    return RationalNumber(a*r.b + b*r.a, b*r.b);
}
RationalNumber RationalNumber::operator-(RationalNumber &r)
{
    return RationalNumber(a*r.b - b*r.a, b*r.b);
}
RationalNumber operator+(const RationalNumber &r1, int i)
{
    return RationalNumber(r1.a + i*r1.b, r1.b);
}
RationalNumber operator+(int i,const RationalNumber &r1)
{
    return RationalNumber(i*r1.b + r1.a, r1.b);
}
RationalNumber operator-(const RationalNumber &r1, int i)
{
    return RationalNumber(r1.a - i*r1.b, r1.b);
}
RationalNumber operator-(int i,const RationalNumber &r1)
{
    return RationalNumber(i*r1.b - r1.a, r1.b);
}