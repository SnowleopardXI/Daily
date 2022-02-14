#include <stdio.h>
int main()
{
    double inp;
    while(~scanf("%lf\n", &inp)) 
    {
        if (inp<0)
            inp=-inp;
        printf("%.2lf\n",inp);
    }
    return 0;
}