#include <stdio.h>
#include <stdlib.h>
typedef struct Sqlist
{
    int data[100];
    int length;
} Sqlist;

Sqlist *Creat_Sqlist()
{
    Sqlist *L;
    L = (Sqlist *)malloc(sizeof(Sqlist));
    if (!L)
        exit(0);
    L->length = 0;
    return L;
}

void insert_Sqlist(Sqlist *L, int a[], int length)
{
    for (int i = 0; i < length; i++)
    {
        L->data[i] = a[i];
        L->length++;
    }
}

int display(Sqlist *L, int p)
{
    int q;
    if (p > L->length)
    {
        p = p % L->length;
        q = L->data[p - 1];
    }
    else
    {
        q = L->data[p - 1];
    }
    int i;
    for (i = p - 1; i < L->length; i++)
    {
        L->data[i] = L->data[i + 1];
    }
    L->length--;
    return q;
}

int main()
{
    Sqlist *L;
    L = Creat_Sqlist();
    int n; //人数
    scanf("%d", &n);
    int num[n]; //密码数组
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    insert_Sqlist(L, num, n);
    int m; //初始数字
    scanf("%d", &m);
    int JS[n];
    int p, w;
    p = m;
    w = L->data[m - 1];
    JS[0] = display(L, w);
    p--;
    for (int i = 1; i < n; i++)
    {
        JS[i] = display(L, p + w);
        w = JS[i];
        p = p + w - 1;
        if (p > L->length)
            p = p % (L->length + 1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", JS[i]);
    }
}
