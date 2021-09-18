#include<stdio.h>
int main()
{
    double inp,out0,out1;
    scanf("%lf",&inp);
    if(inp<0){
      printf("Invalid Value!");
      return 0;
    }
    if(inp<=50){
        printf("%.2f",0.53*inp);
    }
    if(inp>50){
        printf("%.2f",(inp-50)*0.58+26.5);
    }
    return 0;
}