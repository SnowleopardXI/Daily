#include <stdio.h>
#include <cstdlib>
#define N 3
typedef struct ss
{
    int id;
    float score;
} STU;
void fun(STU a[], STU *s)
{

    int i;
    *s = a[0];
    for (i = 0; i < N; i++)
    {
        if (a[i].score < s->score)
        {
            *s = a[i];
        }
    }
}
int main()
{
    STU a[N] = {{201901, 80.5}, {201902, 98.2}, {201903, 84.3}};
    STU *s;
    s = (STU *)malloc(sizeof(STU));
    fun(a, s);
    printf("%d %.1f\n", s->id, s->score);//fu
}
