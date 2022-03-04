#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void main()
{
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        printf("%d",rand()%6);
    }
}