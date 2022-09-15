#include <stdio.h>
int main()
{
    int a[60][70];
    printf("%p\n",a);
    printf("size:%d\\n",sizeof(a)/4200);
    printf("%p\n",&a[31][57]);
    return 0;
}