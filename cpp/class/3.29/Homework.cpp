#include <iostream>
using namespace std;
class counter
{
public:
    counter(int = 0); //构造函数
    counter(const counter &); //复制构造函数
    void increment(); //给value原值加1
    void decrement(); //给value原值减1
    void setvalue(int); //设置计数器值
    int getvalue(); //取得计数器值
    void print(); //显示计数
private:
    int value; //数据成员
};
int main()
{
    counter c1, c2(10), c3 = c2, c4 = 5;
    cout << "c1=";
    c1.print();
    c1.increment();
    cout << "now, c1=";
    c1.print();
    cout << "c2=";
    c2.print();
    c2.decrement();
    cout << "now, c2=";
    c2.print();
    cout << "c3=" << c3.getvalue() << endl;
    cout << "c4=" << c4.getvalue() << endl;
    c4.setvalue(100);
    cout << "now, c4=" << c4.getvalue() << endl;
    return 0;
}
counter::counter(int n)
{
    value = n;
}
counter::counter(const counter &obj)
{
    value = obj.value;
}
void counter::increment()
{
    value++;
}
void counter::decrement()
{
    value--;
}
void counter::setvalue(int n)
{
    value = n;
}
int counter::getvalue()
{
    return value;
}
void counter::print()
{
    cout << value << endl;
}