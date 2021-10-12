#include <stdio.h>
#include <math.h>
int main()
{
    char formula;
    long long int a,b,out1;
    long double out2;
    scanf("%lld%c%lld",&a,&formula,&b);
    switch (formula)
    {
    case '/':
        if(b==0)
        printf("Error\n");
        else
        {
            out1=a/b;
            if (out1-((long long int)out1)==0)
            {
                printf("%lld%c%lld=%lld\n",a,formula,b,out1);
            }
            else
                printf("%lld%c%lld=%.2lf\n",a,formula,b,out2);
        }
        break;
    case '+':
        out1=a+b;
        printf("%lld%c%lld=%lld\n",a,formula,b,out1);
        break;
    case '-':
        out1=a-b;
        printf("%lld%c%lld=%lld\n",a,formula,b,out1);
        break;
    case '*':
        out1=a*b;
        printf("%lld%c%lld=%lld\n",a,formula,b,out1);
        break;
    case '%':
        out1=a%b;
        printf("%lldmod%lld=%lld\n",a,b,out1);
        break;
    case '^':
        out1=pow(a,b);
        printf("%lld%c%lld=%lld\n",a,formula,b,out1);
        break;
    default:
        printf("Error\n");
        break;
    }

}