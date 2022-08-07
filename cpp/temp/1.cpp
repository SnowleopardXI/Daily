#include <iostream>
using namespace std;
class RationalNumber
{
private:
    int a = 100, b; // a为分子，b为分母
public:
    // construtors
    RationalNumber()
    {
        b = 2;
    }
    RationalNumber(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    // getters
    int getNumerator()
    {
        return a;
    }
    int getDenominator()
    {
        return b;
    }
    // setters
    void setNumerator(int a)
    {
        this->a = a;
    }
    void setDenominator(int b)
    {
        if (b == 0)
        {
            this->b = 1;
        }
        else
        {
            this->b = b;
        }
    }
    //其他成员函数
    void print()
    {
        cout << a << "/" << b << endl;
    }
};
int main()
{
    RationalNumber r1, r2(-2, 0);
    r2.print();
    return 0;
}
