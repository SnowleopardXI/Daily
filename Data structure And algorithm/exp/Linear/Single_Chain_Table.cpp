#include <stdio.h>
#include <stdlib.h>
typedef int Elemtype;

typedef struct LNode
{
    Elemtype data;
    LNode *next;
} LNode;

LNode *Creat_LNode()
{
    LNode *L;
    L = (LNode *)malloc(sizeof(LNode));
    L->data = 0;
    L->next = NULL;
    if (!L)
        exit(0);
    return L;
}

void insert_LNode(LNode *L, Elemtype test[], int len)
{
    LNode *p, *q;
    p = L;
    for (int i = 0; i < len; i++)
    {
        q = (LNode *)malloc(sizeof(LNode));
        if (!q)
            exit(0);
        q->data = test[i];
        q->next = NULL;
        p->next = q;
        p = p->next;
        L->data++;
    }
}

void display(LNode *L)
{
    LNode *p;
    p = L;
    while (p->next != NULL)
    {
        printf("%d ", p->next->data);
        p = p->next;
    }
    printf("\n");
}

void delete_LNode(LNode *L, Elemtype min, Elemtype max)
{
    LNode *p;
    p = L;
    while (p->next != NULL)
    {
        if (p->next->data > min && p->next->data < max)
        {
            LNode *q;
            q = p->next;
            p->next = q->next;
            free(q);
        }
        else
            p = p->next;
    }
}

int main()
{
    LNode *L;
    L = Creat_LNode();
    int T; //测试组数
    scanf("%d", &T);
    int len; //链表长
    scanf("%d", &len);
    Elemtype test[len];
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &test[i]); //链表中的data，按增序输入
    }
    insert_LNode(L, test, len);
    int q; //进行q次操作
    scanf("%d", &q);
    int op[q];
    Elemtype min, max;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &op[i]);
        if (op[i] == 2)
            scanf("%d %d", &min, &max);
    }
    for (int i = 0; i < q; i++)
    {
        if (op[i] == 1)
            display(L);
        else
            delete_LNode(L, min, max);
    }
}
