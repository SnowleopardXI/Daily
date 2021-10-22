#include<stdio.h>
int swap(int a,int b)
{

}
int main()
{
    int n,i;
    char flag='a';
    scanf("%d",&n);
    int group[n];
    for (i=0;i<n&&flag!='\n';i++)
    {
        scanf("%d",&group[i]);
        flag=getchar();
    }
    for (i = 0; i < n; i++)
    {
        printf("%d",group[i]);
    }
    
}