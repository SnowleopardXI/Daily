#include <iostream>
using namespace std;
void Sum(const int &a,const int &b);
void Sum(const double &a,const double &b);
void Sum(const char &a,const char &b);
void Sum(const int &a,const int &b,const int &c);
int main()
{
    Sum(12,34);
    Sum(13.5,27.6);
    Sum('a','m');
    Sum(28,34,57);
    return 0; 
}
void Sum(const int &a,const int &b)
{
    cout<<a+b<<endl;
}
void Sum(const double &a,const double &b)
{
    cout<<a+b<<endl;
}
void Sum(const char &a,const char &b)
{
    cout<<a+b<<endl;
}
void Sum(const int &a,const int &b,const int &c)
{
    cout<<a+b+c<<endl;
}
