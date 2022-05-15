#include <iostream>
#include "Manager.h"
using namespace std;
Manager::Manager():num(0){
	cout<<"Inside manager default constructor"<<endl;
}
Manager::Manager(const string& f,const string& l,const double& s,const int& n):Employee(f,l,s),num(n){
	cout<<"Inside manager non-default constructor"<<endl;
	
}
Manager::Manager(const Manager& m):Employee(m),num(m.num){
	cout<<"Inside manager copy constructor"<<endl;
}
Manager::~Manager(){
	cout<<"Manager object destructed"<<endl;
}
int Manager::getSubordinates()const{
	return num;
}
void Manager::setSubordinates(const int& n){
	num=n;
}
Manager& Manager::operator=(const Manager& m){	
	this->Employee::operator=(m);
	num=m.num;
	return *this;
}

void Manager::readInfo(istream& in){
	Employee::readInfo(in);
	cout<<"\tEnter number of subordinates:";
	in>>this->num;
}
void Manager::printInfo(ostream& out) const{
	Employee::printInfo(out);
	out<<"\tNumber of the subordinate="<<this->num<<endl;
}
istream& operator>>(istream& in,Manager& m){
	m.readInfo(in);
	return in;
}
ostream& operator<<(ostream& out,const Manager& m){
	m.printInfo(out);
	return out;
}
