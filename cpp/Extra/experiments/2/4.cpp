#include <iostream>
using namespace std;
class magic //声明魔方阵类magic
{
public:
    void getdata();       //输入初值成员函数
    void setfirstmagic(); //设置初始魔方成员函数
    int generate();       //生成最终魔方成员函数
    int printmagic();     //显示魔方成员函数
private:
    int m[4][4];
    int step;
    int first;
    int sum;
};
void magic::getdata() //输入初值成员函数
{
    cout << "请输入初值：\t";
    cin >> first;
    cout << "请输入步数：\t";
    cin >> step;
}
void magic::setfirstmagic() //设置初始魔方成员函数
{
    int tmp = first;
    m[0][0] = first;
    for (int i = 0, j = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i == 0 && j == 0)
                continue;
            else
                tmp += step;
            m[i][j] = tmp;
        }
    }
    sum=m[0][0]+m[3][3];
    cout<<"sum=\t"<<sum<<endl;
    cout<<"变换前的魔方："<<endl;
    printmagic();
}
int magic::generate() //生成最终魔方成员函数
{
    for(int i=0;i<4;i++)
    {
        m[i][i]=sum-m[i][i];
        m[i][3-i]=sum-m[i][3-i];
    }
    return 0;
}
int magic::printmagic() //显示魔方成员函数
{
    cout<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout<<"|\t";
        for (int j = 0; j < 4; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout <<"|"<< endl;
    }
    return 0;
}
int main()
{
    magic m;
    m.getdata();
    m.setfirstmagic();
    m.generate();
    m.printmagic();
    return 0;
}