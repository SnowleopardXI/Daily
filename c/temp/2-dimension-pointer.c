#include <stdio.h>
int main()
{
    int array[3][4]={{1,3,5,7},{9,11,13,15},{17,19,21,23}};
    int (*p)[4]=array;
    int i,j;
    for (i = 0; i < 3; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            printf("%-2d\x20",*(*(p+i)+j));
        }
    }
    
}