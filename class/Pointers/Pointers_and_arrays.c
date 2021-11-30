#include <stdio.h>
int main()
{
    int A[]={2,4,5,8,1};
    int i;
    int *p=A;
    //A++;  //Invalid
    p++;//Valid
    for ( i = 0; i < 5; i++)
    {
        printf("Address = %p\n",&A[i]);
        printf("Address = %p\n",A+i);
        printf("Value = %d\n",A[i]);
        printf("Value = %d\n",*(A+i));
    }
    
    return 0;
}