#include <iostream>
using namespace std;
class RationalNumber
{
private:
    int a, b;
public:
    // construtors
    RationalNumber(); 
    RationalNumber(int, int);
    RationalNumber(const RationalNumber &);
    // getters
    int getNumerator();
    int getDenominator(); 
    void setNumerator(int); 
    void setDenominator(int); 
    void standardize();
    void print(); 
    double toDouble(); 
    void reduce();
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
void RationalNumber::reduce()
{
    int gcd = 1;
    for (int i = 2; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
            gcd = i;
    }
    a /= gcd;
    b /= gcd;
}
