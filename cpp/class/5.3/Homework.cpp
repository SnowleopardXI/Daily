#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
    string firstName, lastName;

protected:
    double salary;

public:
    Employee();
    Employee(const string &, const string &, const double &);
    Employee(const Employee &);
    Employee &operator=(const Employee &);
    string getFirstName() const;
    string getLastName() const;
    double getSalary() const;
    void setFirstName(const string &);
    void setLastName(const string &);
    void setSalary(const double &);
    friend ostream &operator<<(ostream &, const Employee &);
};
ostream &operator<<(ostream &, const Employee &);

Employee::Employee():firstName(""), lastName(""), salary(0){}
Employee::Employee(const string &first, const string &last, const double &sal)
{
    firstName = first;
    lastName = last;
    salary = sal;
}
Employee::Employee(const Employee &e)
{
    firstName = e.firstName;
    lastName = e.lastName;
    salary = e.salary;
}
Employee &Employee::operator=(const Employee &e)
{
    if (this != &e)
    {
        firstName = e.firstName;
        lastName = e.lastName;
        salary = e.salary;
    }
    return *this;
}
string Employee::getFirstName() const
{
    return firstName;
}
string Employee::getLastName() const
{
    return lastName;
}
double Employee::getSalary() const
{
    return salary;
}
void Employee::setFirstName(const string &first)
{
    firstName = first;
}
void Employee::setLastName(const string &last)
{
    lastName = last;
}
void Employee::setSalary(const double &sal)
{
    salary = sal;
}
ostream &operator<<(ostream &os, const Employee &e)
{
    os << e.firstName << " " << e.lastName << " " << e.salary;
    return os;
}
int main()
{
    Employee e1("Adam", "Steve", 23333);
    Employee e2("Mitsuha", "Miku", 60000);
    cout <<"e1 :"<<e1 << endl;
    cout <<"e2 :"<<e2 << endl;
    e1 = e2;
    cout <<"e1 :"<<e1 << endl;
    return 0;
}
