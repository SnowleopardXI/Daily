#include <iostream>
#include <cmath>
using namespace std;
class Point
{
private:
    int x;
    int y;

public:
    void init(int a, int b);
    int getX();
    int getY();
    void setX(int a);
    void setY(int b);
    void print();              //(2,3)
    double distance(Point &p); //两点之间的距离
};
int main()
{
    Point p1, p2;
    p1.init(1, 2);
    cout << "Point p1 is ";
    p1.print();
    cout << endl;
    p1.setX(3);
    p1.setY(4);
    cout << "Now x coordinate of p1 is " << p1.getX() << endl;
    cout << "And y coordinate of p1 is " << p1.getY() << endl;
    p2.init(7, 8);
    cout << "The distance of p1 and p2 is " << endl;
    p1.distance(p2);
    return 0;
}
void Point::init(int a, int b)
{
    x = a;
    y = b;
}
int Point::getX()
{
    return x;
}
int Point::getY()
{
    return y;
}
void Point::setX(int a)
{
    x = a;
}
void Point::setY(int b)
{
    y = b;
}
void Point::print() //(2,3)
{
    cout << "(" << x << "," << y << ")";
}
double Point::distance(Point &p) //两点之间的距离
{
    cout<<sqrt(((x - p.getX()) * (x - p.getX())) + ((y - p.getY()) * (y - p.getY())));
}