//静态成员函数
#include <iostream>
using namespace std;
class Student
{
public:
    Student(int n, int a, float s) : num(n), age(a), score(s) {}
    void total();
    static float aver(); //定义静态成员函数
    static float sum;    //定义静态成员
    static float count;

private:
    int num;
    int age;
    float score;
};
void Student::total()
{
    sum = sum + score;
    count = count + 1;
}
float Student::sum = 0.0; //给静态成员赋值
float Student::count = 0.0;
float Student::aver() //注意类型的使用 ，静态成员的调用
{
    return ((float)sum / count);
}
int main()
{
    Student stu[3] = //数组的使用注意！！！
        {
            Student(1001, 18, 70.0),
            Student(1002, 19, 78.0),
            Student(1003, 20, 98.1)

        };
    int n;
    cin >> n;
    for (n = 0; n <= 2; n++) //利用循环计算总分
    {
        stu[n].total();
    }
    cout << "平均值为：" << Student::aver() << endl;
}