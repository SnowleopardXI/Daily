#include <iostream>
#include <cmath>
using namespace std;
class Triangle
{
private:
    double s1, s2, s3;
public:
    Triangle();                                //用初始化成员列表初始化三条边分别为，1，2，sqrt(3.0)
    Triangle(double s1, double s2, double s3); // s1用初始化成员列表初始化，s2调用成员函数setSide2初始化，s3用函数内部赋值的方法初始化,注意this指针的应用，不能修改形参的名字
    double getSide1();                         //读取s1
    double getSide2();                         //读取s2
    double getSide3();                         //读取s3
    void setSide1(double);                     //修改s1
    void setSide2(double);                     //修改s2
    void setSide3(double);                     //修改s3
    double getArea();                          //计算面积，已知三角形的三条边，如何求面积的公式大家自己去查
    double getPerimeter();                     //计算周长
};
int main()
{
    Triangle t1, t2(3, 4, 5);
    cout << "t1 area is " << t1.getArea() << endl;
    cout << "t1 perimeter is " << t1.getPerimeter() << endl;
    cout << "t2 area is " << t2.getArea() << endl;
    cout << "t2 perimeter is " << t2.getPerimeter() << endl;
    system("Pause");
    return 0;
}
Triangle::Triangle():s1(1), s2(2), s3(sqrt(3.0))
{
}
Triangle::Triangle(double s1, double s2, double s3):s1(s1)
{
    setSide2(s2);
    this->s3 = s3;
}
double Triangle::getSide1()
{
    return s1;
}
double Triangle::getSide2()
{
    return s2;
}
double Triangle::getSide3()
{
    return s3;
}
void Triangle::setSide1(double s1)
{
    this->s1 = s1;
}
void Triangle::setSide2(double s2)
{
    this->s2 = s2;
}
void Triangle::setSide3(double s3)
{
    this->s3 = s3;
}
double Triangle::getArea()
{
    double p = getPerimeter() / 2;
    return sqrt(p*(p - s1)*(p - s2)*(p - s3));
}
double Triangle::getPerimeter()
{
    return s1 + s2 + s3;
}