#include <stdio.h>
#include <math.h>

int menu()
{
    printf("1.Science mode\n");
    printf("2.Normal mode\n");
    printf("Please input a choice:\n");
}

int main()
{
	menu();
	int n0;
    scanf("%d",&n0);
    while (1) {
        program_express();
        program_sci();
        }
    while (2) {
        program_express();
        program_nor();
    }
    system("pause");
}

void program_express(char formula,int n0,long double a,long double b)
{
    printf("Please input the expression:\n");
    scanf("%lf%c%lf",&a,&formula,&b);
    printf("Please input how many nunmbers you want to print after the dot:\n");
    scanf("%d",n0);
}

void program_nor(char formula,int n0,long double a,long double b)
{
	char formula;
    short int n0;
    long double a,b,out1,out2;
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
                printf("%lf%c%lf=%lf\n",a,formula,b,out1);
            }
            else
                printf("%lf%c%lf=%.2lf\n",a,formula,b,out2);
        }
        break;
    case '+':
        out1=a+b;
        printf("%lf%c%lf=%lf\n",a,formula,b,out1);
        break;
    case '-':
        out1=a-b;
        printf("%lf%c%lf=%lf\n",a,formula,b,out1);
        break;
    case '*':
        out1=a*b;
        printf("%lf%c%lf=%lf\n",a,formula,b,out1);
        break;
    case '^':
        out1=pow(a,b);
        printf("%lf%c%lf=%lf\n",a,formula,b,out1);
        break;
    default:
        printf("Error\n");
        break;
    }
}

void program_sci(char formula,int n0,long double a,long double b)
{
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
                printf("%lf%c%lf=%lf\n",a,formula,b,out1);
            }
            else
                printf("%lf%c%lf=%.2lf\n",a,formula,b,out2);
        }
        break;
    case '+':
        out1=a+b;
        printf("%lf%c%lf=%lf\n",a,formula,b,out1);
        break;
    case '-':
        out1=a-b;
        printf("%lf%c%lf=%lf\n",a,formula,b,out1);
        break;
    case '*':
        out1=a*b;
        printf("%lf%c%lf=%lf\n",a,formula,b,out1);
        break;
    case '^':
        out1=pow(a,b);
        printf("%lf%c%lf=%lf\n",a,formula,b,out1);
        break;
    default:
        printf("Error\n");
        break;
    }
}
