#include <iostream>
using namespace std;
void Sum(int a, int b);
void Sum(double a, double b);
void Sum(char a, char b);
void Sum(int a, int b, int c);
int main()
{
    Sum(12,34);
    Sum(13.5,27.6);
    Sum('a','m');
    Sum(28,34,57);
}
void Sum(int a, int b)
{
    cout<<a+b<<endl;
}
void Sum(double a, double b)
{
    cout<<a+b<<endl;
}
void Sum(char a, char b)
{
    cout<<a+b<<endl;
}
void Sum(int a, int b, int c)
{
    cout<<a+b+c<<endl;
}