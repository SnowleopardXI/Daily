#include <stdio.h>
int main()
{
    char s[80]="abcdefghijkl",*p;
    int *q;
    p=&s[2];
    printf("%p %s\n",p,p);
    q=(int *)p;
    q++;
    p=(char *)q;
    printf("%p %c %s\n",p,*p,p);
    return 0;
}