#include <iostream>
using namespace std;

class Base
{
protected:
    int a;

public:
    Base()
    {
        a = 5;
        cout << "B a=" << a << endl;
    }
};

class Base1 : virtual public Base
{
public:
    Base1()
    {
        a = a + 10;
        cout << "B1 a=" << a << endl;
    }
};

class Base2 : virtual public Base
{
public:
    Base2()
    {
        a = a + 20;
        cout << "B2 a=" << a << endl;
    }
};

class Derived : public Base1, public Base2
{
public:
    Derived()
    {
        cout << "Derived a=" << a << endl;
        cout << "Base1 a=" << Base1::a << endl;
        cout << "Base2 a=" << Base2::a << endl;
    }
};
class Derived1 : public Base1
{
public:
    Derived1()
    {
        cout << "Derived1 a=" << a << endl;
        cout << "Base1 a=" << Base1::a << endl;
    }
};
int main()
{
    Derived obj;
    cout << "Base对象所占空间:" << sizeof(Base) << endl;
    cout << "Base1对象所占空间:" << sizeof(Base1) << "字节" << endl;
    cout << "Base2对象所占空间:" << sizeof(Base2) << "字节" << endl;
    cout << "Derived对象所占空间:" << sizeof(Derived) << "字节" << endl;
    cout << "Derived1对象所占空间:" << sizeof(Derived1) << "字节" << endl;
}