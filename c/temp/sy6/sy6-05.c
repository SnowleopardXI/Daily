#include <stdio.h>
int N; 
int highstu(float, float[]);
float average(float[]);
void input(float[]);

int main()
{
    float score[50], avg;
    int n;
    printf("Please input the number of students: ");
    scanf("%d", &N);
    input(score);
    avg = average(score);
    n = highstu(avg, score);
    printf("高于平均成绩%.2f的人数为%d\n", avg, n);
}
void input(float score[])
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("Enter score of No.%d= ", i+1);
        scanf("%f", &score[i]);
    }
}

float average(float score[])
{
    int i;
    float sum = 0;
    for (i = 0; i < N; i++)
        sum += score[i];
    return sum / N;
}
int highstu(float avg, float score[])
{
    int n = 0, i;
    for (i = 0; i < N; i++)
        if (score[i] > avg)
            n++;
    return n;
}
