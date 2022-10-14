#include <iostream>
#include<cmath>
//点与圆位置关系
class Point
{
public:
	Point(double x, double y) : x(x), y(y) {}
	double x;
	double y;
};
class Circle
{
public:
	Circle(Point center, double radius) : center(center), radius(radius) {}
	Point center;
	double radius;
};
Point getPoint(double x, double y)
{
	return Point(x, y);
}
Circle getCircle(double x, double y, double radius)
{
	return Circle(getPoint(x, y), radius);
}
void isPointInCircle(Point point, Circle circle)
{
	double distance = sqrt(pow(point.x - circle.center.x, 2) + pow(point.y - circle.center.y, 2));
	if (distance < circle.radius)
	{
		std::cout << "点在圆内" << std::endl;
	}
	else if (distance == circle.radius)
	{
		std::cout << "点在圆上" << std::endl;
	}
	else
	{
		std::cout << "点在圆外" << std::endl;
	}
}
int main()
{
	Circle circle = getCircle(10, 0, 10);
	Point point = getPoint(10, 10);
	isPointInCircle(point, circle);
	return 0;
}