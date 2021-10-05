#include <stdio.h>
#include <math.h>
int main()
{
    int ori=1000;
    double r1=0.015,r2=0.021,r3=0.0275,r5=0.03,r6=0.0035;
    double q1,q2,q3,q4,q5;
    q1=1000*(1+5*r5);
    q2=((double)1000*(1+(2*r2)))*(1+(3*r3));
    q3=((double)1000*(1+(3*r3)))*(1+(2*r2));
    q4=((double)1000*pow((1+r1),5));
    q5=((double)1000)*pow((1+(r6/4)),20);
    printf("一次存5年期为：%7.1lf\n",q1);
    printf("先存2年期，到期后本息再存3年期为：%7.2lf\n",q2);
    printf("先存3年期，到期后本息再存2年期为：%7.2lf\n",q3);
    printf("存1年期，到期后将本息再存1年期，连续存5次为：%7.2lf\n",q4);
    printf("存活期存款，每季度结算一次为：%7.2lf\n",q5);
}