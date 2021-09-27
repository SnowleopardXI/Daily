#include <stdio.h>
int main() 
{
    char c; 
    short s; 
    int i; 
    long l; 
    float f; 
    double d; 
    long double ld; 
    printf("sizeof(char)=%d\n", sizeof(char)); 
    printf("sizeof(short)=%d\n", sizeof(short)); 
    printf("sizeof(int)=%d\n", sizeof(int)); 
    printf("sizeof(long)=%d\n", sizeof(long)); 
    printf("sizeof(float)=%d\n", sizeof(float)); 
    printf("sizeof(double)=%d\n", sizeof(double)); 
    printf("sizeof(long double)=%d\n", sizeof(long double)); 
    printf("\n"); 
    c='A'; 
    s=10; 
    i=100; 
    l=1000; 
    f=0.0; 
    d=4.6787866; 
    ld=50.0134345; 
    printf("%c\n", c); 
    printf("%d\n", s); 
    printf("%d\n", i); 
    printf("%d\n", l); 
    printf("%f\n", f); 
    printf("%f\n", d); 
    printf("%lf\n", ld); 
    printf("\n"); 
    printf("sizeof(char)=%d\n", sizeof(c)); printf("sizeof(short)=%d\n", sizeof(s)); printf("sizeof(int)=%d\n", sizeof(i)); 
    printf("sizeof(long)=%d\n", sizeof(l)); printf("sizeof(float)=%d\n", sizeof(f)); printf("sizeof(double)=%d\n", sizeof(d)); printf("sizeof(long double)=%d\n", sizeof(ld)); 
    return 0;
}