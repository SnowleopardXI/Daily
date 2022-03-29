#include <iostream>
using namespace std;
class cylinder
{
    private:
        double radius;
        double height;
    public:
        cylinder(double r, double h)
        {
            radius = r;
            height = h;
        }
        double area()
        {
            return 2 * 3.14 * radius * height + 2 * 3.14 * radius * radius;
        }
        double volume()
        {
            return 3.1415926 * radius * radius * height;
        }
        void print()
        {
            cout << "半径：" << radius << "\t高度：" << height << endl;
            cout << "面积：" << area() << "\t体积：" << volume() << endl;
        }
};
int main()
{
    cylinder obj(3, 4);
    return 0;
}