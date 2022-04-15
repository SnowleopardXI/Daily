#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; //元素的数据类型

typedef struct LNode
{
    ElemType data;      //结点的数据域
    struct LNode *next; //指向后继结点
} LinkNode;             //单链表结点类型

//尾插法建立单链表
void CreateListR(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *temp;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    temp = L;
}
//输出线性表
void DispList(LinkNode *L)
{
    LinkNode *p;
    p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
//单链表插入排序：元素递增排序
void insertion_sort(LinkNode *&L)
{
    LinkNode *p, *q, *r;
    p = L->next;
    L->next = NULL;
    while (p != NULL)
    {
        q = L;
        r = p->next;
        while (q->next != NULL && q->next->data < p->data)
        {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
        p = r;
    }
}
int main()
{
    int n;

    scanf("%d", &n);
    ElemType a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    LinkNode *A;
    CreateListR(A, a, n);

    insertion_sort(A);
    printf("排序后的单链表: ");
    DispList(A);

    return 0;
}
