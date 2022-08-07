#include <iostream>
using namespace std;
class Shape
{
    public:
        virtual double Area() = 0;
        virtual void PrintInfo() = 0;
        friend ostream& operator<<(ostream& os, Shape& s);
}
class Rectangle : public Shape
{
    private:
        double w, h;
    public:
    Rectangle();
    Rectangle(double w, double h);
    virtual double Area();
    virtual void PrintInfo();
}
Rectangle::Rectangle():w(0),h(0){}
Rectangle::Rectangle(double w, double h):w(w),h(h){}