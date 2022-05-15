#include <iostream>
#include <string>
#include <cstdlib>
#include "Complex.h"
using namespace std;

Complex operator+(const Complex &a,const Complex &b){
	return Complex(a.real+b.real,a.imag+b.imag);
}

Complex operator+(double a,const Complex &b){ 
	return b+a;
}
ostream & operator<<(ostream &os,const Complex &a){
	os<<a.real;
	if(a.imag>0)
		os<<"+"<<a.imag<<"i";
	else if(a.imag<0)
		os<<a.imag<<"i";
	return os;
}
istream & operator>>(istream &is,Complex &a){//空格,回车,tab 
	string s;
	is>>s;
	int pos=s.find("+",0);//1
	string sTemp=s.substr(0,pos);//2
	a.real=atof(sTemp.c_str());//char*
	sTemp=s.substr(pos+1,s.length()-pos-2);
	a.imag=atof(sTemp.c_str());
	return is;
}
bool operator==(const Complex& a,const Complex & b){
	if((a.real==b.real)&&(a.imag==b.imag))
		return true;
	else
		return false;
}
bool operator!=(const Complex& a,const Complex & b){
	return !(a==b);
}
 
Complex& operator--(Complex& a){
	a.real-=1;
	a.imag-=1;
	return a;
}
Complex operator--(Complex& a,int){
	Complex tmp(a);
	a.real-=1;
	a.imag-=1;
	return tmp; 
}
Complex& operator-=(Complex& a,const Complex& b){
	return a=a-b;
}
Complex& operator-(Complex& a){
	a.real=-a.real;
	a.imag=-a.imag;
	return a;
}
bool operator>=(const Complex& a, const Complex & b){
	return !(a<b);
}
/*********************************************************************/
Complex::Complex(double r,double i){
	real=r;
	imag=i;
}
Complex::Complex(istream & is){
	operator>>(is,*this);
	//is>>real>>imag;
}
Complex Complex::operator+(const Complex &a){
	return Complex(this->real+a.real,this->imag+a.imag);
}
double Complex::getReal() const{
	return real;
}
double Complex::getImag() const{
	return imag;
}
Complex Complex::operator+(double a)const{
	return Complex(a+this->real,this->imag);
}

Complex& Complex::operator=(const Complex& a){
	this-> real=a.real;
	this->imag=a.imag;
	return *this;
}
Complex& Complex::operator=(const double& a){
	Complex c(a,0);
	return *this=c;
}
//前置 ++
Complex& Complex::operator++(){
	this->real+=1;
	this->imag+=1;
	return *this;
}
//后置++ 
Complex Complex::operator++(int){
	Complex tmp(*this);//复制构造函数 
	this->real+=1;
	this->imag+=1;
	return tmp; 
}
//比较的是复数的模 
bool Complex::operator>(const Complex &a) const{
	double temp1=this->real*this->real+this->imag*this->imag;
	double temp2=a.real*a.real+a.imag*a.imag;
	if(temp1>temp2)
		return true;
	else
		return false;
}
bool Complex::operator<(const Complex &a) const{
	if(*this>a || *this==a)
		return false;
	else
		return true;
}

Complex& Complex::operator+=(const Complex& a){	
	return this->operator=(this->operator+(a));//*this=*this+a;
}
Complex Complex::operator-(const Complex& a){
	return Complex(real-a.real,imag-a.imag);
}
Complex& Complex::operator-(){
	real=-real;
	imag=-imag;
	return *this;
}
bool Complex::operator<=(const Complex& a) const{
	return !(*this>a);
}
