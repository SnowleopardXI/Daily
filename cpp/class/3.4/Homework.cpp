#include <iostream>
#include <cmath>
using namespace std;
class Point
{
private:
    int x;
    int y;

public:
    void init(int a, int b)
    {
        x = a;
        y = b;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void setX(int a)
    {
        x = a;
    }
    void setY(int b)
    {
        y = b;
    }
    void print()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
    double distance(Point p)
    {
        return sqrt((x - p.getX()) * (x - p.getX()) + (y - p.getY()) * (y - p.getY()));
    }
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
    cout << "The distance of p1 and p2 is " << p1.distance(p2) << endl;
    return 0;
}