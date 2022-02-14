#include <stdio.h>
int main()
{
    int num1,num2,out1;
    float out2;
    char formula;
    scanf("%d%c%d",&num1,&formula,&num2);
    if (formula!='+'&&formula!='-'&&formula!='*'&&formula!='/')
        printf("非法输入\n");
    else 
    {
        if (formula=='/'&&num2==0)
            printf("非法输入\n");
        else
    {
        if(formula=='/')
        {
            out2=(double)num1/num2;
        }
        else {
            if (formula=='+')
            {
                out1=num1+num2;
            }
            else {
                if(formula=='-')
                {
                    out1=num1-num2;
                }
                else {
                    if(formula=='*')
                    {
                        out1=num1*num2;
                    }
                }
            }
        }
    if (formula=='/')
    {
        if((out2-((int)out2))==0){
            printf("%d%c%d=%d",num1,formula,num2,(int)out2);
        }
        else
        printf("%d%c%d=%.2f",num1,formula,num2,out2);
    }
    else
    {
        printf("%d%c%d=%d",num1,formula,num2,out1);
    }
    return 0;
}
}
}