#include <stdio.h>
int main()
{
    int a,b,c,d; 
    printf("Input a, b\n");
    scanf("%d, %d", &a, &b); 
    c=(a++)+(b++); 
    printf("c=%d\n", c);
    d=(++a)+(++b); 
    printf("d=%d\n", d); 
}