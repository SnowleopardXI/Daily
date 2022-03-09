#include <iostream>
using namespace std;
class Point
{
    private:
        int x;
        int y;
    public:
        Point middle(const Point &p);
        Point getX();
        Point getY();
};
Point Point::getX()
{
    return x;
}
Point Point::getY()
{
    return y;
}
Point Point::middle(const Point &p)
{
    Point q;
    q.x = (x + p.x) / 2;
    q.y = (y + p.y) / 2;
    return q;
}
int main()
{
    Point p1(0,0), p2(2,2), p3;
    cout << p3.getX() << " " << p3.getY() << endl;
    return 0;
}