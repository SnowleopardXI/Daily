#include <stdio.h>
int main(void)
{
    int n1 = 1, n2 = 0, n3 = 0;
    int total = 0;
    int i=1, num, t;
    scanf("%d", &num);
    while(1){
        total = n1 + n2 + n3;
        if(total >= num)
        break;
        i += 1;
        t = n1;
        n1 = n3 + n2;
        n3 += n2;
        n2 = t;
    }
    printf("%d\n", i);
    return 0;
}