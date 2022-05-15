#include <iostream>
#include "Employee.h"
using namespace std;
class Manager:public Employee{
	private:
		int num;
	public:
		Manager();
		Manager(const string&,const string&,const double&,const int&);
		Manager(const Manager&);
		Manager& operator=(const Manager&);
		~Manager();
		int getSubordinates()const;
		void setSubordinates(const int&);
		void readInfo(istream&);
		void printInfo(ostream&) const;
		friend istream& operator>>(istream&,Manager&);
		friend ostream& operator<<(ostream&,const Manager&);
};		
istream& operator>>(istream&,Manager&);
ostream& operator<<(ostream&,const Manager&);

