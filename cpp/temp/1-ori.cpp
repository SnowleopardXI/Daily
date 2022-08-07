#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int age;
    double wage;
    string name;

public:
    Employee();
    Employee(int, double, string);
    Employee(Employee &);
    void PrintInfo();
    operator+(Employee &E1, Employee &E2);
};

int main()
{
    Employee a(20, 1000, "lihua");
    Employee b(30, 2000, "lixing");
    a.PrintInfo();
    b.PrintInfo();
    cout<<a+b<<endl;
    return 0;
}

Employee::Employee() : age(0), wage(0), name(0)
{
}
Employee::Employee(int a, double w, string n)
{
    age = a;
    wage = w;
    name = n;
}
Employee::Employee(Employee &e)
{
    age = e.age;
    wage = e.wage;
    name = e.name;
}
void Employee::PrintInfo()
{
    cout << "name:" << name << " "
         << "age:" << age << " "
         << "wage:" << wage << endl;
}
operator+(Employee &E1, Employee &E2)
{
    return E1.wage + E2.wage;
}