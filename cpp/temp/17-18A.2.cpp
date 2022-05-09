/*设计和实现圆类Circle，要求如下： 
（1）该类有1个double类型的私有数据成员：radius表示圆的半径值； 
（2）为Circle类设计运算符重载函数：
以友元函数形式重载“+”加法运算：Circle类的对象 a和 b，a+b运算返回两圆面积之和；
以类内成员函数形式重载“-”减法运算： a-b运算返回两圆面积之差（注意差值为正数）； 
（3）按需要可为Circle类添加其它必要的成员函数；
（4）设计测试程序：在main（）函数中创建Circle类对象，并测试运算符函数的功能。
*/
#include <iostream>
using namespace std;

class Circle{
	private:
		double radius;
	public:
		Circle();
		Circle(int m);
		friend Circle operator+(Circle &a,Circle &b);
		Circle operator-(Circle &c);
		void print();
		void prints();
};
int main()
{
	Circle c1(4),c2(2),c3,c4;
	c3=c1+c2;
	c4=c1-c2;
	c1.print();cout<<"+";c2.print();cout<<"=";c3.prints();cout<<endl; 
	c1.print();cout<<"-";c2.print();cout<<"=";c4.prints();cout<<endl;
	return 0;
}
Circle::Circle():radius(0){}
Circle::Circle(int m):radius(m){}
Circle operator+(Circle &a,Circle &b)
{
	return (a.radius*a.radius+b.radius*b.radius);
}
Circle Circle::operator-(Circle &c)
{
	return (radius*radius-c.radius*c.radius);
}
void Circle::print()
{
	cout<<3.14*radius*radius;
}
void Circle::prints()
{
	cout<<3.14*radius;
}