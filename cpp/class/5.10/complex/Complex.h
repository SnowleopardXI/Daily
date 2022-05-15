#include <iostream>
using namespace std;
class Complex{
	private:
		double real=0;
		double imag=0;//类内初始值 
	public:
		Complex()=default;
		Complex(double r,double i);
		Complex(istream & is);
		double getReal() const;
		double getImag() const;
		Complex operator+(const Complex &a);
		Complex operator-(const Complex&);
		Complex operator+(double a)const;
		bool operator>(const Complex &a) const;
		bool operator<(const Complex &) const;
		bool operator<=(const Complex&) const;
		Complex& operator=(const Complex&);
		Complex& operator=(const double&);
		Complex& operator++();//前置 
		Complex operator++(int);//后置 
		Complex& operator+=(const Complex&);
		Complex& operator-();
		
		friend Complex operator+(const Complex &a,const Complex &b);
		friend Complex operator+(double a,const Complex &b);
		friend ostream & operator<<(ostream &os,const Complex &a);
		friend istream & operator>>(istream &is,Complex &a);
		friend bool operator==(const Complex& a,const Complex & b);
		friend bool operator!=(const Complex& a,const Complex & b);
		friend Complex& operator--(Complex&);
		friend Complex operator--(Complex&,int);
		friend Complex& operator-=(Complex&,const Complex&);
		friend Complex& operator-(Complex&);
		friend bool operator>=(const Complex&, const Complex &);
};
Complex operator+(const Complex &a,const Complex &b);
Complex operator+(double a,const Complex &b);
ostream & operator<<(ostream &os,const Complex &a);
istream & operator>>(istream &is,Complex &a);
bool operator==(const Complex& a,const Complex & b);
bool operator!=(const Complex& a,const Complex & b);
Complex& operator--(Complex&);
Complex operator--(Complex&,int);
Complex& operator-=(Complex&,const Complex&);
Complex& operator-(Complex&);//取反  2+2i 
bool operator>=(const Complex&, const Complex &);
