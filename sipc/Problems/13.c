#include <stdio.h>
int main(){
    int i,n,sum=0,input=0;
    float result;
    scanf("%d",&n);
    while (~scanf("%d ",&input))
    {
        sum+=input;
        result=(float)input/n;
        printf("%d\t%.1f",sum,result);
    }
    
    return 0;
}