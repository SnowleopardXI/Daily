#include <stdio.h>
int main()
{
    int a,b,c;
    char x;
    scanf("%d%c%d",&a,&x,&b);
    switch (x)
    {
    case '+':
        c=a+b;
        break;
    case '-':
        c=a-b;
        break;
     case '*':
        c=a*b;
        break;
    case '/':
        if(b!=0)
        c=(float)a/b;
        break;
    default:
        printf("Error");
        break;
    }
    printf("%d%c%d=%d",a,x,b,c);
    return 0;
}