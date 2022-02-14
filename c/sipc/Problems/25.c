#include<stdio.h>
int main()
{
    int i;
    for(i=6;i<=100000;i++){
        if(i%5==1&&i%6==5&&i%7==4&&i%11==10){
            printf("%d",i);
            break;
        }
    }
    return 0;
}
