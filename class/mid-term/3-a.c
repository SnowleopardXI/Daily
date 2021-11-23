#include <stdio.h>/*三、四位数*/
int main()
{
    int i,j,hun,ten,data,N;
    scanf("%d",&N);
    for (i = 100; i <= N; i++)
    {
        j = 10;
        while (j*j <= i)
        {
            if (i==j*j)
            {
                hun=i/100;
                data=i-hun*100;
                ten=data/10;
                data=data-ten*10;
                if (hun == ten || hun == data || ten == data)
                    printf("%5d",i);
            }
            j++;
        }
    }
    return 0;
}