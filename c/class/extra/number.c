#include<stdio.h>
int main()
{
    int i;
    for(i=6;i<=100000;i++){
        if(i==((i%3*70)+(i%5*21)+(i%7*15))%105){
        }
        printf("%d",i);
    }
    return 0;
}
