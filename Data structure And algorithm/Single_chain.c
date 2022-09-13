#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
//初始化链表
LinkList init_LinkList()
{
    LinkList L;
    L = (LinkList)malloc(sizeof(LNode));
    if (!L)
        exit(1);
    L->next = NULL;
    return L;
}
//链表插入
LinkList insert_LinkList(LinkList L, int i, int x)
{
    LNode *p;
    p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
        exit(1);
    LNode *s;
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = p->next;
    p->next = s;
    return L;
}
//链表删除
LinkList delete_LinkList(LinkList L, int i)
{
    LNode *p;
    p = L;
    int j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)
        exit(1);
    LNode *q;
    q = p->next;
    p->next = q->next;
    free(q);
    return L;
}
//链表查找
int search_LinkList(LinkList L, int x)
{
    LNode *p;
    p = L->next;
    int i = 1;
    while (p && p->data != x)
    {
        p = p->next;
        ++i;
    }
    if (!p)
        return 0;
    else
        return i;
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
    LinkList L;
    L = init_LinkList();
    for (int i = 0; i < 10; i++)
    {
        L = insert_LinkList(L, i + 1, fibonacci(i + 1));
    }
    delete_LinkList(L, 7);
    insert_LinkList(L, 3, 2222);
    int i = search_LinkList(L, 2222);
    printf("%d", i);
    return 0;
}