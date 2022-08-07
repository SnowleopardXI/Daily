#include <iostream>
#include <cmath>
#define N 3
using namespace std;

class Shape{
	public:
		virtual double Area()=0;
		virtual void PrintInfo(ostream& out)=0;
		friend ostream& operator<<(ostream& out,Shape& shape);
		virtual ~Shape(){
		} 
};
ostream& operator<<(ostream& out,Shape& shape)
{
	shape.PrintInfo(cout);
	return out;
}

//矩形 
class Rectangle:public Shape{
	private:
		double w,h;
	public:
		Rectangle():w(1),h(2){
		}
		Rectangle(double w,double h):w(w),h(h){
		}
		virtual double Area();
		virtual void PrintInfo(ostream& out);
		virtual ~Rectangle(){
		} 
};
double Rectangle::Area()
{
	return w*h;
}
void Rectangle::PrintInfo(ostream& out)
{
	cout<<"Rectangle "<<"area="<<Area()<<endl;
}

//圆形 
class Circle:public Shape{
	private:
		double r;
		const double pai;
	public:
		Circle():r(1),pai(3.14){
		}
		Circle(double r,double pai=3.14):r(r),pai(pai){
		}
		virtual double Area();
		virtual void PrintInfo(ostream& out);
		virtual ~Circle(){
		} 
};
double Circle::Area()
{
	return pai*r*r;
}
void Circle::PrintInfo(ostream& out)
{
	cout<<"Circle "<<"area="<<Area()<<endl;
}

//三角形 
class Triangle:public Shape{
	private:
		double side1,side2,side3;
	public:
		Triangle():side1(1),side2(1),side3(1){
		}
		Triangle(double side1,double side2,double side3){
			this->side1=side1;
			this->side2=side2;
			this->side3=side3;
		}
		virtual double Area();
		virtual void PrintInfo(ostream& out);
		virtual ~Triangle(){
		} 
};
double Triangle::Area()
{
	double s=(side1+side2+side3)/2;
	return sqrt(s*(s-side1)*(s-side2)*(s-side3));
}
void Triangle::PrintInfo(ostream& out)
{
	cout<<"Triangle "<<"area="<<Area()<<endl;
}

//正方形 
class Square:public Rectangle{
	private:
		double side;
	public:
		Square():Rectangle(1,1),side(1){
		}
		Square(double side):Rectangle(side,side),side(side){
		}
		virtual void PrintInfo(ostream& out);
		virtual ~Square(){
		} 
};
void Square::PrintInfo(ostream& out)
{
	cout<<"Square "<<"area="<<Area()<<endl;
}

int main()
{
	/*Shape *p;
	Triangle t;
	Rectangle r;
	Square s;
	Circle c;
	/*p=&t;                     //114~126行调用PrintInfo(cout)输出 
	p->PrintInfo(cout);
	p=&r;
	p->PrintInfo(cout);
	p=&s;
	p->PrintInfo(cout);
	p=&c;
	p->PrintInfo(cout);*/
	//cout<<t<<r<<s<<c;         //调用12~16行 cout输出 
	
	Shape *pshapes[N];
	char c;
	double x,y,z;
	
	//输入 
	for(int i=0;i<N;i++)
	{
		cout<<"请输入形状选择：";
		cin>>c;
		switch(c){
			case 'R':
				cout<<"请输入长和宽："; 
				cin>>x>>y;
				pshapes[i]=new Rectangle(x,y);
				break;
			case 'T':
				cout<<"请输入三角形的三条边：";
				cin>>x>>y>>z;
				pshapes[i]=new Triangle(x,y,z);
				break;
			case 'C':
				cout<<"请输入圆形半径：";
				cin>>x;
				pshapes[i]=new Circle(x);
				break;
			case 'S':
				cout<<"请输入正方形边长：";
				cin>>x;
				pshapes[i]=new Square(x);
				break;
		}
	}
	
	//排序 
	Shape *p;
	for(int i=0;i<N-1;i++){
		for(int j=0;j<N-i-1;j++){
			if(pshapes[j]->Area()>pshapes[j+1]->Area()){
				p=pshapes[j];
				pshapes[j]=pshapes[j+1];
				pshapes[j+1]=p;
			}
		}
	}
	
	//输出 
	for(int i=0;i<N;i++)
	{
		pshapes[i]->PrintInfo(cout);
		//delete pshapes[i];
	}
	delete []pshapes;
	return 0;
}
