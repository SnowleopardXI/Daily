#pragma once 
#include <iostream>
using namespace std;
class Employee{
	private:
		string firstName,lastName;
		
	protected:
		double salary;
	public:
		Employee();
		Employee(const string&,const string&,const double&);
		Employee(const Employee&);
		~Employee();
		Employee& operator=(const Employee&);
		string getFirstName()const;
		string getLastName()const;
		double getSalary()const;
		void setFirstName(const string&);
		void setLastName(const string&);
		void setSalary(const double&);
		void readInfo(istream&);
		void printInfo(ostream&) const;
		friend istream& operator>>(istream&,Employee&);
		friend ostream& operator<<(ostream&,const Employee&);
};
istream& operator>>(istream&,Employee&);
ostream& operator<<(ostream&,const Employee&);
