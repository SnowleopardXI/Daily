#include <iostream>
using namespace std;
class RationalNumber
{
private:
    int a, b; // a为分子，b为分母
public:
    // construtors
    RationalNumber() : a(0), b(1) {} //用初始化成员列表设置默认值分子为0，分母为1
    RationalNumber(int x, int y)
    {
        a = x;
        if (y == 0)
        {
            b = 1;
        }
        else
        {
            b = y;
        }
    }
    //分子用普通赋值方法初始化，分母调用set函数初始化
    // getters
    int getNumerator()
    {
        return a;
    }
    //分子
    int getDenominator()
    {
        return b;
    }
    //分母
    //setters
    void setNumerator(int x)
    {
        a = x;
    }
    //分子
    void setDenominator(int y)
    {
        if (y == 0)
        {
            b = 1;
        }
        else
        {
            b = y;
        };
    }
    //分母,如果分母为0，设置为1
    //其他成员函数
    void print()
    {
        cout << a << "/" << b << endl;
    }
    //输出a/b的格式
    RationalNumber myAdd(RationalNumber r1, RationalNumber r2)
    {
        int m = r1.b * r2.b;
        int n = r1.a * r2.b + r2.a * r1.b;
        return RationalNumber(n, m);
    }
    RationalNumber mySubtract(RationalNumber r1, RationalNumber r2)
    {
        int m = r1.b * r2.b;
        int n = r1.a * r2.b - r2.a * r1.b;
        return RationalNumber(n, m);
    }
    friend RationalNumber myMutiply(RationalNumber r1, RationalNumber r2)
    {
        int m = r1.b * r2.b;
        int n = r1.a * r2.a;
        return RationalNumber(n, m);
    }
    friend RationalNumber myDivide(RationalNumber r1, RationalNumber r2)
    {
        int n = r1.a * r2.b;
        int m = r1.b * r2.a;
        return RationalNumber(n, m);
    }
};

int main()
{

    RationalNumber r1(5, 7), r2(3, 5);

    RationalNumber *p1 = new RationalNumber(2, 9);

    //调用成员函数myAdd计算r1+r2
    RationalNumber r3;
    r3=r3.myAdd(r1, r2);
    r1.print();
    cout << "+";
    r2.print();
    cout << "=";
    //调用成员函数print()输出r1+r2的结果
    r3.print();
    //调用成员函数mySubtract计算*p1-r1的值
    p1->print();
    cout << "-";
    r1.print();
    cout << "=";
    RationalNumber r4;
    r4=r4.mySubtract(*p1, r1);
    //调用成员函数print()输出*p1-r1的结果
    r4.print();
    //调用函数myDivide计算r1/r2
    r1.print();
    cout << "/";
    r2.print();
    cout << "=";
    RationalNumber r5;
    r5 = myDivide(r1, r2);
    //调用成员函数print()输出r1/r2的结果
    r5.print();
    //调用函数myMultiply计算*p1 * r1的值
    p1->print();
    cout << "*";
    r1.print();
    cout << "=";
    RationalNumber r6;
    r6 = myMutiply(*p1, r1);
    //调用成员函数print()输出*p1* r1的结果
    r6.print();
    return 0;
}
