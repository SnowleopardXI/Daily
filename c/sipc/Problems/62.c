#include <stdio.h>
#include <string.h>
#define MAXN 11
int main(void)
{
    int n;
    scanf("%d", &n);
    int max = -1, sum = 0, score1 = 0, score2 = 0, score3 = 0, result_sum = 0;
    char name[MAXN], result_name[MAXN], id[MAXN], result_id[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%s",&id);
        scanf("%s",&name);
        scanf("%d",&score1);
        scanf("%d",&score2);
        scanf("%d",&score3);
        sum=score1+score2+score3;
        if (sum>max)
        {
            max=sum;
            strcpy(result_name, name);
            strcpy(result_id, id);
            result_sum = sum;
        }
    }
    printf("%s %s %d\n", result_name, result_id, result_sum);
    return 0;
}