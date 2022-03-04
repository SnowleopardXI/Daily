#include <iostream>
#include "rectangle.h"
using namespace std;
int Rectangle::area()
{
    return length*width;
}
int Rectangle::perimeter()
{
    return 2*(length+width);
}
void Rectangle::Print()
{
    int i,j;
    for(i=0;i<length;i++)
    {
        for(j=0;j<width;j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void Rectangle::_init(int w,int h)
{
    length=w;
    width=h;
}
int main()
{}