#include <iostream>
#include <cmath>
using namespace std;
class Location //声明类Location
{
public:
    Location(double, double);                        //构造函数
    double Getx();                                   //成员函数，取x坐标的值
    double Gety();                                   //成员函数，取y坐标的值
    double distance1(Location &);                    //成员函数，求两坐标点之间的距离
    friend double distance2(Location &, Location &); //友元函数，求两坐标点之间的距离
private:
    double x, y;
};
Location::Location(double x, double y) //构造函数
{
    this->x = x;
    this->y = y;
}
double Location::Getx() //成员函数，取x坐标的值
{
    return x;
}
double Location::Gety() //成员函数，取y坐标的值
{
    return y;
}
double Location::distance1(Location &r) //成员函数，求两坐标点之间的距离
{
    return sqrt((x - r.x) * (x - r.x) + (y - r.y) * (y - r.y));
}
double distance2(Location &r1, Location &r2) //友元函数，求两坐标点之间的距离
{
    return sqrt((r1.x - r2.x) * (r1.x - r2.x) + (r1.y - r2.y) * (r1.y - r2.y));
}
int main()
{
    Location A(-3,-4);
    Location B(-2,3);
    cout<<"A ("<<A.Getx()<<","<<A.Gety()<<")"<<" ,"<<"B ("<<B.Getx()<<","<<B.Gety()<<")"<<endl;
    cout<<"Distance1="<<A.distance1(B)<<endl;
    cout<<"Distance2="<<distance2(A,B)<<endl;
    return 0;
}