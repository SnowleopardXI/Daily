#include<iostream>
using namespace std;
class Employee
{
    private:
        string name;
        int age;
        double salary;
    public:
        Employee();
        Employee(string name, int age, double salary);
        Employee(const Employee& emp);
        void PrintInfo();
        double operator+(const Employee& emp) const;
};
Employee::Employee()
{
    name="";
    age=0;
    salary=0;
}
Employee::Employee(string name, int age, double salary)
{
    this->name=name;
    this->age=age;
    this->salary=salary;
}
Employee::Employee(const Employee& emp)
{
    this->name=emp.name;
    this->age=emp.age;
    this->salary=emp.salary;
}
void Employee::PrintInfo()
{
    cout<<"name="<<name<<endl;
    cout<<"age="<<age<<endl;
    cout<<"salary="<<salary<<endl;
}
double Employee::operator+(const Employee& emp) const
{
    return salary+emp.salary;
}
int main()
{
    Employee emp1("zhangsan",20,1000);
    Employee emp2("lisi",30,2000);
    emp1.PrintInfo();
    emp2.PrintInfo();
    cout<<"emp1+emp2="<<emp1+emp2<<endl;
    return 0;
}
