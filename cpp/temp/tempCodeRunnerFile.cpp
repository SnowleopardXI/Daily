#include <iostream>
using namespace std;
class MyMath
{
private:
    int x;

public:
    MyMath();
    MyMath(int x);
    void fun(int x);
    int factorial(int x);
};
MyMath::MyMath() : x(0) {}
MyMath::MyMath(int x)
{
    this->x = x;
}
void MyMath::fun(int x)
{
    //1!+2!+3!+...+n!
    int sum = 0;
    for (int i = 1; i <= x; i++)
    {
        sum += factorial(i);
    }
    cout << sum << endl;
}
int MyMath::factorial(int x)
{
    if (x == 0)
        return 1;
    return x * factorial(x - 1);
}
int main()
{
    MyMath m;
    m.fun(5);
    return 0;
}