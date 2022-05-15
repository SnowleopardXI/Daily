#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee():firstName(""),lastName(""),salary(0.0){
	cout<<"Inside employee default constructor"<<endl;
}
Employee::Employee(const string& f,const string& l,const double& s):firstName(f),lastName(l),salary(s){
	cout<<"Inside employee non-default constructor"<<endl;
}
Employee::Employee(const Employee& d):firstName(d.firstName),lastName(d.lastName),salary(d.salary){
	cout<<"Inside employee copy constructor"<<endl;
}
Employee::~Employee(){
	cout<<"Employee object destructed"<<endl;
}
Employee& Employee::operator=(const Employee& e){
	firstName=e.firstName;
	lastName=e.lastName;
	salary=e.salary;
	return *this;
}
string Employee::getFirstName()const{
	return firstName;
}
string Employee::getLastName()const{
	return lastName;
}
double Employee::getSalary()const{
	return salary;
}
void Employee::setFirstName(const string& f){
	firstName=f;
}
void Employee::setLastName(const string& l){
	lastName=l;
}
void Employee::setSalary(const double& s){
	salary=s;
}
void Employee::readInfo(istream& in){
	cout<<endl;
	cout<<"\tEnter first name:";
	in>>firstName;
	cout<<"\tEnter last name:";
	in>>lastName;
	cout<<"\tEnter salary:";
	in>>salary;
}
void Employee::printInfo(ostream& out) const{
	cout<<endl;
	out<<"\tFull Name="<<firstName<<" "<<lastName<<endl;
	out<<"\tSalary="<<salary<<endl;
}
istream& operator>>(istream& in,Employee& e){
	e.readInfo(in);
	return in;
}
ostream& operator<<(ostream& out,const Employee& e){
	e.printInfo(out);
	return out;
}
