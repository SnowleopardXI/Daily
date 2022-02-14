#include <stdio.h>
int main()
{
    int input,out;
    scanf("%d",&input);
    if (input<0)
        out=-1;
    else
        if (input==0)
            out=0;
        else
            out=1;
    printf("%d",out);
    return 0;
}