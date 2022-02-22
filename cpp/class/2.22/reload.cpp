#include <iostream>
using namespace std;
int max(int a, int b);
float max(float a, int b);
float max(float a, float b);
double max(double &a, const double &b);
char max(char a, char b);
int main()
{
    int x=1,y;
    //max(1,2);
    cout<<max(3.465464894d,2.58469419410d)<<endl;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
float max(float a, int b)
{
    cout<<"double"<<endl;
    if (a > b)
        return a;
    else
        return b;
}
float max(float a, float b)
{
    if (a > b)
        return a;
    else
        return b;
}
double max(double a,double b)
{
    if (a > b)
        return a;
    else
        return b;    
}
char max(char a,char b)
{    
    if (a > b)
        return a;
    else
        return b;
}