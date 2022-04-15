#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
    long id;
    char name;
    char address;
    double salary;

public:
    Employee(long, char *, char *, double);
    ~Employee();
    void set_id(long);
    void set_name(char *);
    void set_address(char *);
    void set_salary(double);
    long get_id();
    double get_salary();
    char *get_name();
    char *get_address();
    void print();
};
char *Employee::get_name()
{
    return &name;
}
char *Employee::get_address()
{
    return &address;
}
void Employee::set_id(long id)
{
    this->id = id;
}
void Employee::set_name(char *name)
{
    this->name = *name;
}
void Employee::set_address(char *address)
{
    this->address = *address;
}
void Employee::set_salary(double salary)
{
    this->salary = salary;
}
long Employee::get_id()
{
    return id;
}
double Employee::get_salary()
{
    return salary;
}
void Employee::print()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Salary: " << salary << endl;
}
Employee::Employee(long id, char *name, char *address, double salary)
{
    this->id = id;
    this->name = *name;
    this->address = *address;
    this->salary = salary;
}
Employee::~Employee()
{
}
int main()
{
    Employee e1(1, "John", "New York", 100000);
    e1.print();
    return 0;
}
