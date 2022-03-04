#include <iostream>
#include "rectangle.h"
using namespace std;
class Rectangle
{
private:
    int length;
    int width;
public:
    int area();
    int perimeter();
    void Print();
    void _init(int w,int h);
};
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
{
    int l,w;
    Rectangle r,r2;
    cout << "Enter length and width of rectangle: ";
    cin >> l >> w;
    r._init(l,w);
    cout << "Area of rectangle: " << r.area() << endl;
    cout << "Perimeter of rectangle: " << r.perimeter() << endl;
    r.Print();
    r2._init(8,4);
    cout << "Area of rectangle: " << r2.area() << endl;
    cout << "Perimeter of rectangle: " << r2.perimeter() << endl;
    r2.Print();
    return 0;
}