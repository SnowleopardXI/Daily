#include <iostream>
#include <string>
using namespace std;
class CPerson
{
    private:
        long long int ID;
        string name;
        int age;
    public:
    void set(long long int ID, string name, int age)
    {
        this->ID = ID;
        this->name = name;
        this->age = age;
    }
    CPerson(long long int ID, string name, int age)
    {
        this->ID = ID;
        this->name = name;
        this->age = age;
    }
    CPerson(const CPerson &obj)
    {
        this->ID = obj.ID;
        this->name = obj.name;
        this->age = obj.age;
    }
    void print()
    {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
