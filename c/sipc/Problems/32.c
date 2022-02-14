#include <stdio.h>
int main()
{
    int str1[20], str2[20], str3[40];
    int len1,len2,len3,i,j,temp=0,num=0;
    scanf("%d",&len1);
    for (i = 0; i < len1; i++)
    {
        scanf("%d", &str1[i]);
    }
    scanf("%d", &len2); 
    for (i = 0; i < len2; i++)
    {
        scanf("%d", &str2[i]);
    }
    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {
            if (str1[i] == str2[j])
                break;
        }
        if (j == len2)
        {
            str3[temp] = str1[i];
            temp++;
        }
    }
    for (i = 0; i < len2; i++)
    {
        for (j = 0; j < len1; j++)
            if (str2[i] == str1[j])
                break;
        if (j == len1)
        {
            str3[temp] = str2[i];
            temp++;
        }
    }
    for (i = 0; i < temp; i++)
    {
        for (j = 0; j < i; j++) 
        {
            if (str3[i] == str3[j])
                break;
        }
        if (i == j)
        {
            if (num != 0)
                printf(" ");
            printf("%d", str3[i]);
            num++;
        }
    }
    return 0;
}