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
    //函数myAdd(),mySubtract()，分别实现两个有理数相加和相减功能。注意传递参数是RationalNumber类型
    RationalNumber myAdd(RationalNumber);
    RationalNumber mySubtract(RationalNumber &r);
    friend RationalNumber myMultiply(RationalNumber, RationalNumber); //定义myMultiply()为友元函数
};
//定义一个普通函数myDivide()，用来实现两个有理数相除。注意传递参数是RationalNumber类型
void myDivide(RationalNumber r1, RationalNumber r2)
{
    double Num = r1.getNumerator()*r2.getDenominator();
    double Den = r1.getDenominator()*r2.getNumerator();
    RationalNumber r3(Num, Den);
}
int main()
{
    RationalNumber r1(5, 7), r2(3, 5);
    RationalNumber *p1 = new RationalNumber(2, 9);
    //调用成员函数myAdd计算r1+r2
    RationalNumber r3 = r1.myAdd(r2);
    r1.print();
    cout << "+";
    r2.print();
    cout << "=";
    //调用成员函数print()输出r1+r2的结果
    r3.print();
    cout << endl;
    //调用成员函数mySubtract计算*p1-r1的值
    RationalNumber r4 = (*p1).mySubtract(r1);
    p1->print();
    cout << "-";
    r1.print();
    cout << "=";
    //调用成员函数print()输出*p1-r1的结果
    r4.print();
    cout << endl;
    //调用函数myDivide计算r1/r2
    myDivide(r1, r2);
    r1.print();
    cout << "/";
    r2.print();
    cout << "=";
    //调用成员函数print()输出r1/r2的结果
    r3.print();
    cout << endl;
    //调用函数myMultiply计算*p1 * r1的值
    RationalNumber r6 = myMultiply(*p1, r1);
    p1->print();
    cout << "*";
    r1.print();
    cout << "=";
    //调用成员函数print()输出*p1* r1的结果
    r6.print();
    cout << endl;
    return 0;
}
RationalNumber::RationalNumber():a(0), b(1)
{
}
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
RationalNumber RationalNumber::myAdd(RationalNumber r)
{
    RationalNumber result;
    result.a = a * r.b + b * r.a;
    result.b = b * r.b;
    return result;
}
RationalNumber RationalNumber::mySubtract(RationalNumber &r)
{
    RationalNumber result;
    result.a = a * r.b - b * r.a;
    result.b = b * r.b;
    return result;
}
RationalNumber myMultiply(RationalNumber r1, RationalNumber r2)
{
    RationalNumber result;
    result.a = r1.a * r2.a;
    result.b = r1.b * r2.b;
    return result;
}