#include <iostream>
using namespace std;
class Student
{
public:
    Student(int); // 构造函数
    ~Student();   // 析构函数

    void account(int);       // 设置分数
    static int sum();        // 返回总成绩
    static double average(); // 返回平均成绩

    void print(); // 打印输出Student的相关信息

private:
    int score;              // 分数
    static int total_score; // 总分
    static int count;       // 总人数
};                          // Student类声明结束
Student::Student(int score) // 构造函数
{
    this->score = score;
    total_score += score;
    count++;
}
Student::~Student() // 析构函数
{
    total_score -= score;
    count--;
}
void Student::account(int score) // 设置分数
{
    this->score = score;
    total_score += score;
    count++;
}
int Student::sum() // 返回总成绩
{
    return total_score;
}
double Student::average() // 返回平均成绩
{
    return (double)total_score / count;
}
void Student::print() // 打印输出Student的相关信息
{
    cout << "分数: " << score << endl;
    cout << "总分: " << total_score << endl;
    cout << "平均分: " << average() << endl;
    cout << "总人数: " << count << endl;
}
int Student::total_score = 0; // 总分
int Student::count = 0;       // 总人数
int main()
{
    Student s1(100);
    Student s2(90);
    Student s3(80);
    Student s4(70);
    Student s5(60);
    Student::print();
    return 0;
}