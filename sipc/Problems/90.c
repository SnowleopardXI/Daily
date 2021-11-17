#include "stdio.h"
int main(int argc,char *argv[])
{
    int M,N,sum,t,k;
    printf("Enter M & N(int 1<M<N)...\n");
    if (scanf("%d%d", &M, &N) == 2 && M > 1 && M < N)
    {
        for (M==2?(k=1,sum=2):sum=0,M+=!(M&1);M<=N;M+=2)
        {
            for (t=3;t*t<=M;t+=2)
                if (!(M % t))
                    break;
            if (t*t > M)
                sum+=M, k++;
        }
        printf("%d  %d\n",sum,k);
    }
    else
        printf("Input error, exit...\n");
    return 0;
}