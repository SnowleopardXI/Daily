#include <stdio.h>
void main() 
{ 
    int a,b,c;
    a=b=c=8;
    !a&&b++&&c;
    printf("%d, %d, %d\n", a, b, c);
    a||--b||c--; 
    printf("%d, %d, %d\n", a, b, c);
    a-8&&--b||c||b++;
    printf("%d, %d, %d\n", a, b, c);
    --a||b&&c||++b; 
    printf("%d, %d, %d\n", a, b, c); 
}