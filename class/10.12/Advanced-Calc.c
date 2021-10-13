#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int menu()
{
    printf("1.Calculator\n");
    printf("2.3*3 Matrix Solver\n");
    printf("");
}

int main()
{
    short int menu0;
    menu();
    scanf("%d",&menu0);
    while (menu==1)
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
    while (menu0==2)
    {
        matrix3();
        return 0;
    }

    while (menu0==3)
    {
        matrix4();
    }  
}

int matrix3()
{
    int i,j,t,s=0,a[3][3];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<3;i++)
    {t=1;
    for(j=0;j<3;j++)
        t*=a[(i+j)%3][j];
    s+=t;
    t=1;
    for(j=0;j<3;j++)
        t*=a[(i+3-j)%3][j];
    s-=t;
    }
    printf("%d\n",s);
    return 0;
}

int matrix4()
{
    int A[]={2,1,3,-1,1,-5,1,1,2,3,2,2,0,-1,4,2};
    printf("%d\n", det(A, 4));
    return 0;
}

int* M(int *A, int n, int i, int j)
{
    int *B= (int*)malloc((n - 1)*sizeof(int));
    int k = 0;
    for (int k1 = 0; k1 < n; ++k1)
    {
        if (k1 != i)
            for (int k2 = 0; k2 < n; ++k2)
                if (k2 != j)
                    B[k++] = A[k1*n + k2];
    }
    return B;
}
 
int det(int A[], int n)
{
    int sum = 0, N = n*n;
    if (n == 1)
        sum = A[0];
    else
    {
        for (int i = 0; i < n; ++i)
        {
            int *tmp = M(A, n, i, 0);
            int Aij = A[i*n]*det(tmp, n - 1);
            if (i%2 != 0)
                Aij = -Aij;
            sum = sum + Aij;
             
        }
    }
    return sum;
}
 
