#include<stdio.h>
struct score
{
    int mid;
    int final;
    float total;
}s[5];//结构体存储5门课程的成绩
int main()
{
    //录入成绩
    s[0].mid=86;
    s[0].final=81;
    s[1].mid=74;
    s[1].final=87;
    s[2].mid=92;
    s[2].final=90;
    s[3].mid=77;
    s[3].final=62;
    s[4].mid=82;
    s[4].final=88;
    //计算总成绩
    for (int i=0;i<5;i++)
    {
        s[i].total=s[i].mid*0.3+s[i].final*0.7;
    }
    //输出成绩
    printf("English: %.2f, Chinese: %.2f, Math: %.2f, History: %.2f, Music: %.2f\n",s[0].total,s[1].total,s[2].total,s[3].total,s[4].total);
    printf("Average: %.2f\n",(s[0].total+s[1].total+s[2].total+s[3].total+s[4].total)/5);
    printf("Average: %d\n",(int)(s[0].total+s[1].total+s[2].total+s[3].total+s[4].total)/5);
}