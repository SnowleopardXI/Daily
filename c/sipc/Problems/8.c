#include <stdio.h>
#include <math.h>
int main()
{
    float inp,out,fx1,fx2;
    scanf("%f",&inp);
    fx1=pow(inp,0.5);
    fx2=pow(inp,2)+(4*inp)+(1/inp)+1;
    if(inp>=0){
        printf("%.2f",fx1);
        return 0;
    }
    if(inp<0){
        printf("%.2f",fx2);
        return 0;
    }
}
