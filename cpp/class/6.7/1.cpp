#include <iostream>
using namespace std;
class Coordinate
{
public:
    Coordinate()
        Coordinate(double x, double y) void display();
    void setX(double);
    void setY(double);
    double distance();

private:
    double x, y;
};
int main()
{
    Coordinate point1(1.0,1.0);
    double d1=point1.distance();
    cout<<
    return 0;
}