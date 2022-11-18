#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
typedef struct
{
    int data[MAXSIZE];
    int length;
} SqList;
//初始化顺序表
SqList init_SqList()
{
    SqList L;
    L.length = 0;
    return L;
}
//顺序表插入
SqList insert_SqList(SqList L, int i, int x)
{
    if (L.length == MAXSIZE)
        exit(1);
    if (i < 1 || i > L.length + 1)
        exit(1);
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = x;
    L.length++;
    return L;
}
//顺序表删除
SqList delete_SqList(SqList L, int i)
{
    if (i < 1 || i > L.length)
        exit(1);
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return L;
}
//顺序表查找
int search_SqList(SqList L, int x)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == x)
            return i + 1;
    return 0;
}
//顺序表合并
SqList merge_SqList(SqList La, SqList Lb)
{
    SqList Lc;
    Lc.length = La.length + Lb.length;
    int i = 0, j = 0, k = 0;
    while (i < La.length && j < Lb.length)
    {
        if (La.data[i] <= Lb.data[j])
            Lc.data[k++] = La.data[i++];
        else
            Lc.data[k++] = Lb.data[j++];
    }
    while (i < La.length)
        Lc.data[k++] = La.data[i++];
    while (j < Lb.length)
        Lc.data[k++] = Lb.data[j++];
    return Lc;
}
//斐波那契数列
int fibonacci(int n)
{
    if (n <= 2)
        return 1;
    else
        return (fibonacci(n - 1) + fibonacci(n - 2));
}
int main(void)
{
    int i, j;
    SqList A, B, C;
    A = init_SqList();
    B = init_SqList();
    C = init_SqList();
    for (int i = 0; i < 10; i++)
    {
        A = insert_SqList(A, i + 1, fibonacci(i + 1));
        B = insert_SqList(B, i + 1, fibonacci(i + 3));
    }
    delete_SqList(A, 2);
    insert_SqList(A, 2, 40);
    printf("A:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d  ", A.data[i]);
    }
    printf("\nB:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d  ", B.data[i]);
    }
    C = merge_SqList(A, B);
    printf("\nC:\n");
    for (i = 0; i < 20; i++)
    {
        printf("%d  ", C.data[i]);
    }
}