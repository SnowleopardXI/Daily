#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{ //定义链表结构体
    int xi;
    int mi;
    struct LNode *next;
} LNode;

typedef LNode *LinkList;

void Creat_List(LinkList &L, int length)
{   //建立空链表
    L = (LinkList)malloc(sizeof(LinkList));
    if (!L)
    {
        printf("创建失败");
    }
    else
    {
        L->next = NULL;
        L->mi = 0;
        L->xi = length;
    }
}

void insert_List(LinkList &L, int a[], int n)
{
    LinkList p[L->xi];
    for (int i = 0; i < L->xi; i++)
    {
        p[i] = (LinkList)malloc(sizeof(LinkList));
    }
    int k = 0;
    for (int i = 0; i < L->xi; i++)
    {
        p[i]->xi = a[k];
        k++;
        p[i]->mi = a[k];
        k++;
    }
    LinkList q = L;
    for (int i = 0; i < L->xi; i++)
    {
        q->next = p[i];
        q = q->next;
    }
}

LinkList KL(LinkList L)
{
    LinkList p, q;
    p = (LinkList)malloc(sizeof(LinkList));
    p->mi = L->mi;
    p->xi = L->xi;
    LinkList a[L->xi];
    for (int i = 0; i < L->xi; i++)
    {
        a[i] = (LinkList)malloc(sizeof(LinkList));
    }
    q = L->next;
    for (int i = 0; i < L->xi; i++)
    {
        a[i]->xi = q->xi;
        a[i]->mi = q->mi;
        a[i]->next = NULL;
        q = q->next;
    }
    for (int i = 0; i < L->xi; i++)
    {
        a[i]->next = a[i + 1];
    }
    p->next = a[0];
    return p;
}

void display1(LinkList L1, LinkList L2)
{
    LinkList p, q;
    p = L1->next, q = L2->next;
    for (int i = 0; i < L1->xi; i++)
    {
        if (p->xi != 0)
        {
            printf("%dX^%d", p->xi, p->mi);
            if (i != L1->xi - 1)
                if (p->next->xi != 0)
                    printf("+");
        }
        p = p->next;
    }
    printf("\n");
    for (int i = 0; i < L2->xi; i++)
    {
        printf("%dX^%d", q->xi, q->mi);
        if (i != L2->xi - 1)
            printf("+");
        q = q->next;
    }
}

void display2(LinkList &L1, LinkList L2)
{
    int count = L2->xi;
    LinkList p, q, k;
    p = L1;
    for (int i = 0; i < L1->xi; i++)
    {
        p = p->next;
    }
    k = p;
    q = KL(L2);
    p->next = q->next;
    L1->xi += L2->xi;
    q = p;
    p = L1->next;
    for (int i = 0; i < L1->xi - count; i++)
    {
        k = q;
        for (int i = 0; i < count; i++)
        {
            if (p->mi == k->next->mi)
            {
                p->xi += k->next->xi;
                k->next = k->next->next;
                L1->xi--;
                count--;
            }
            else
                k = k->next;
        }
        p = p->next;
    }
}

void display3(LinkList L1, LinkList L2)
{
    int count = L2->xi;
    LinkList p, q, k;
    p = L1;
    for (int i = 0; i < L1->xi; i++)
    {
        p = p->next;
    }
    k = p;
    q = KL(L2);
    p->next = q->next;
    L1->xi += L2->xi;
    q = p;
    p = L1->next;
    for (int i = 0; i < L1->xi - count; i++)
    {
        k = q;
        for (int i = 0; i < count; i++)
        {
            if (p->mi == k->next->mi)
            {
                p->xi -= k->next->xi;
                k->next = k->next->next;
                L1->xi--;
                count--;
            }
            else
                k = k->next;
        }
        p = p->next;
    }
    k = q->next;
    for (int i = 0; i < count; i++)
    {
        k->xi = -k->xi;
        k = k->next;
    }
    k = L1->next;
    for (int i = 0; i < L1->xi; i++)
    {
        if (k->xi != 0)
        {
            printf("%dX^%d", k->xi, k->mi);
            if (i < L1->xi - count - 1 && k->next->xi != 0)
            {
                printf("+");
            }
        }
        k = k->next;
    }
    printf("\n");
    k = L2->next;
    for (int i = 0; i < L2->xi; i++)
    {
        printf("%dX^%d", k->xi, k->mi);
        if (i != L2->xi - 1)
            printf("+");
        k = k->next;
    }
}

int main()
{
    int test; //测试次数
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int length1, length2;
        scanf("%d %d", &length1, &length2);
        LinkList L1, L2;
        Creat_List(L1, length1);
        Creat_List(L2, length2);
        int num1[length1 * 2], num2[length2 * 2];
        for (int i = 0; i < length1 * 2; i++)
        {
            scanf("%d", &num1[i]);
        }
        for (int i = 0; i < length2 * 2; i++)
        {
            scanf("%d", &num2[i]);
        }
        insert_List(L1, num1, length1 * 2);
        insert_List(L2, num2, length2 * 2);
        int cz;
        scanf("%d", &cz);
        int op[cz];
        for (int i = 0; i < cz; i++)
        {
            scanf("%d", &op[i]);
        }
        for (int i = 0; i < cz; i++)
        {
            if (op[i - 1] == 3)
                continue;
            if (op[i] == 1)
            {
                display1(L1, L2);
                printf("\n");
            }
            if (op[i] == 2)
            {
                display2(L1, L2);
                printf("\n");
            }
            if (op[i] == 3 && op[i + 1] == 1)
            {
                display3(L1, L2);
            }
        }
    }
}
