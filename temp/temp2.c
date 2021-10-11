#include <stdio.h>
int main()
{
    double x,a;
    scanf("%lf",&x);
    if(x<0){
        printf("Invalid");
    }
    else {
        if(x<=50)
        {
            a=0.53*x;
        }
        else
        {
            a=0.53*50+0.58*(x-50);
        }
        printf("%.2f",a);
    }  
    
}