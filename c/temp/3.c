#include <stdio.h>
#define PI 3.1415926
int main()
{
    double r,c,s;
    printf（“输入半径”）;
    scanf（%lf,&r）;
    c=2*PI*r;
    s=PI*r*r;
    printf("S=%lf,c=%lf/n",s,c);
    return 0;
}
