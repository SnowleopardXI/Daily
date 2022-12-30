#include <stdio.h>
int main()
{
    static int number=63245;
    //number to 632 45
    int a=number/100;
    int b=number%100;
    printf("a=%d, b=%d\n",a,b);
    printf("a+b=%d\ta-b=%d\ta*b=%d\n",a+b,a-b,a*b);
    printf("a/b=%.2f\ta%%b=%d",(float)a/b,a%b);
    return 0;
}