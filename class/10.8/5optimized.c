#include <stdio.h>
int main() {
    int n,sum=0;
    scanf("%d",&n);
    switch (n)
    {
    case 0:
        printf("该数的位数为：1");
        break;
    default:
        while(n){
                sum++;
                n/=10;
                } 
        printf("该数的位数为：%d\n",sum);
    }     
    return 0;
}