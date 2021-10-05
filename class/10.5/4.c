#include<stdio.h>
void main() 
{ 
    int x=1,y=3,z=5;
    int d,e;
    x+=y+=z; 
    printf("x=%d, y=%d, z=%d\n", x, y, z); 
    d= x<y?y:x; 
    e= x<y?x++:y++; 
    printf("d=%d\n", d); 
    printf("e=%d\n", e); 
    printf("x=%d\n", x); 
    printf("y=%d\n", y); 
}