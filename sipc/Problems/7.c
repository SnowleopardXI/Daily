#include <stdio.h>
int main()
{
    float inp,out;
    scanf("%f",&inp);
    if(inp>0){
        out=1.0/inp;
        printf("%.1f",out);
        return 0;
    }
    if(inp==0){
        out=0;
        printf("%.1f",out);
        return 0;
    }
}