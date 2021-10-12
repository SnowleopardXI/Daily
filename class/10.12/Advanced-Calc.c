#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    const double pi=3.1415926;
    const double phi=0.6180339887;
    const double e=2.718281828;
    char choice[8]={0},spe[8]={0};
    short int n1,n2,judge0=0;
    double a,b,out1,out2,judge1;
    printf("Do you need pi,phi or e?\t Type yes or no:");
    scanf("%s",choice);
    if((strcmp(choice,"yes"))==0)
    {
        printf("\nWhich one would you like to use :");
        scanf("%s",spe);
        if(strcmp(spe,"pi")==0)
        {
            a=pi;
        }
        else {
            if(strcmp(spe,"phi")==0)
            {
                a=phi;
            }
            else {
                if(strcmp(spe,"e")==0)
                    a=e;
                    else {
                            printf("Error");
                            return 0;
                        }
                }  
            }
        printf("\nWhich position should be put?");
        scanf("%d",&n2);
        if(n2!=2&&n2!=1){
            printf("Invalid position!");
            return 0;
        }
        else {
            if(n2==1){
                judge0=1;
                printf("\nPlease input the expression:(Special Numbers please use 0)");
            }
            else {
                printf("\nPlease input the expression:(Special Numbers please use 0)");
                judge0=2;
                b=a;
            }            
        }
    }
    else {
        if((strcmp(choice,"no"))!=0){
            printf("Error");
            return 0;
        }
        else{}
    }
        int temp;
        char formula;
        if(judge0==0)
        printf("\nPlease input the expression:");
        if(judge0==1)
            {
                scanf("%d%c%lf",&temp,&formula,&b);
            }
        else {
                if(judge0==2)
                    scanf("%lf%c%d",&a,&formula,&temp);
                else if(judge0==0)
                    scanf("%lf%c%lf",&a,&formula,&b);
        }
        int judge=(a-((int)a)==0)&&(b-((int)b)==0);
        if (formula!='+'&&formula!='-'&&formula!='*'&&formula!='/'&&formula!='^'&&formula!='%')
        {
            printf("Invalid Input!\n");
            getchar();
            return 0;
        }
        if(formula=='%'&&judge==0)
            {
                printf("You can`t input decimal!\n");
                getchar();
                return 0;
            }
        else
        {
            switch (formula){
                case '/':
                    if(b==0)
                    printf("Error\n");
                    else
                    {
                        out1=a/b;
                        if (out1-((int)out1)==0)
                            printf("%lf%c%lf=%d\n",a,formula,b,(int)a/(int)b);
                        else
                            printf("%lf%c%lf=%.6lf\n",a,formula,b,a/b);
                    }
                    getchar();
                    break;
                case '+':
                    out2=a+b;
                    judge1=out2-((int)out2);
                    if(judge1!=0)
                    {
                        printf("%lf%c%lf=%.6lf\n",a,formula,b,out2);
                    }
                    else
                    {
                        printf("%d%c%d=%d\n",(int)a,formula,(int)b,(int)out2);
                    }
                    getchar();
                    break;
                case '-':
                    out2=a-b;
                    judge1=out2-((int)out2);
                    if(judge1!=0)
                    {
                        printf("%lf%c%lf=%.6lf\n",a,formula,b,out2);
                    }
                    else
                    {
                        printf("%d%c%d=%d\n",(int)a,formula,(int)b,(int)out2);
                    }
                    getchar();
                    break;
                case '*':
                    out2=a*b;
                    judge1=out2-((int)out2);
                    if(judge1!=0)
                    {
                        printf("%lf%c%lf=%.6lf\n",a,formula,b,out2);
                    }
                    else
                    {
                        printf("%d%c%d=%d\n",(int)a,formula,(int)b,(int)out2);
                    }
                    getchar();
                    break;
                case '^':
                    out2=pow(a,b);
                    judge1=out2-((int)out2);
                    if(judge1!=0)
                    {
                        printf("%lf%c%lf=%.6lf\n",a,formula,b,out2);
                    }
                    else
                    {
                        printf("%d%c%d=%d\n",(int)a,formula,(int)b,(int)out2);
                    }
                    getchar();
                    break;
                case '%':
                    int mod=(int)a%(int)b;
                    printf("%d%c%d=%d\n",(int)a,formula,(int)b,mod);
                    getchar();
                    break;
                default:
                    printf("Error\n");
                    getchar();
                    break;
                }
            }
    getchar();
    return 0;
}