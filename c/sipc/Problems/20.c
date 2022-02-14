#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int sum=1;
        while(n>1){
            sum++;
            sum=sum*2;
            n--;
        }
        printf("%d",sum);
        printf("\n");
    }
    return 0;
}