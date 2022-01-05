#include <stdio.h>
#define N 3
int pos=0;
struct STU
{
    int id,score;
}stu[N];
int fun(int *p)
{
    int i,temp;
    for (i = 0; i < N; i++)
    {
        
    }
    
}
int main()
{
    struct STU stu[N]={{201901,80},{201902.98},{201903,84}};
    struct STU *s;
    fun(s);
    printf("%d %d",s->id,s->score);
    return 0;
}