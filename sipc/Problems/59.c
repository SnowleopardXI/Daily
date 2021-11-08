#include <stdio.h>
int main()
{
    __int32_t h,m,s,sec;
    scanf("%d:%d:%d",&h,&m,&s);
    scanf("%d",&sec);
    s=+sec;
    printf("%d,%d,%d\n",&h,&m,&s);
    if (s>=60)
    {
        s-=60;
        m++;
    }
    if (m>=60)
    {
        m-=60;
        h++;
    }    
    printf("%d,%d,%d",&h,&m,&s);
    return 0;
}
