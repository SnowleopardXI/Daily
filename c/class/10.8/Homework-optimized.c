#include <stdio.h>
int main() {
    int n,i=0;
    scanf("%d",&n);
    if(n>=0&&n<=10000)
    {
        do
    {
        i++;
        n/=10;
    } while (n>0);
    printf("%d",i);
    }
    else
        printf("Error");
    return 0;
}