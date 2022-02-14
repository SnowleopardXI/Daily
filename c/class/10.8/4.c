#include <stdio.h>
int main()
{
    double input,out;
    scanf("%lf",&input);
    if (input<1)
    out=input;
    else if(input>=10)
        out=3*input-11;
        else
            out=2*input-1;
    printf("%lf",out);
    return 0;
}