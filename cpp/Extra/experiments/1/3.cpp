#include <iostream>
using namespace std;

class countner
{
public:
    countner(int number); //构造函数
    void increment();     //给value原值加1
    void decrement();     //给value原值减1
    int getvalue();       //取得计数器值
    void print();         //显示计数
private:
    int value; //数据成员
};
void countner::increment()
{
    value++;
}
void countner::decrement()
{
    value--;
}
int countner::getvalue()
{
    return value;
}
void countner::print()
{
    cout << "value = " << value << endl;
}
countner::countner(int number)
{
    value = number;
}

int main()
{
    countner c1(10);
    c1.increment();
    c1.print();
    c1.decrement();
    c1.print();
    return 0;
}