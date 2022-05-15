#include <iostream>
#include "Employee.h"
#include "Manager.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Manager m1,m2("Sam","Smith",2000.00,5);
	Manager m3(m2);
	m2.Employee::printInfo(cout);
	return 0;
}
