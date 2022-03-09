#include <iostream>
using namespace std;

class coutner
{
public:
    coutner(int number);  //构造函数
    void increment();     //给value原值加1
    void decrement();     //给value原值减1
    void setvalue(int a); //设计计数器值
    int getvalue();       //取得计数器值
    void print();         //显示计数
private:
    int value; //数据成员
};

int main()
{
    coutner A(12); //定义counter类的几个对象并调用有关成员函数
    A.decrement(); //
    A.print();     //两行 输出
    A.increment();
    A.print();
    A.setvalue(23);
    cout << A.getvalue() << endl;

    return 0;
}

//构造函数
coutner::coutner(int number)
{
    value = number;
}
void coutner::increment() //给value原值加1
{
    value += 1;
}
void coutner::decrement() //给value原值减1
{
    value -= 1;
}
void coutner::setvalue(int a) //设计计数器值
{
    value = a;
}
int coutner::getvalue() //取得计数器值
{
    return value;
}
void coutner::print() //显示计数
{
    cout << value << endl;
}