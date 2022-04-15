#include <iostream>
using namespace std;
bool CreateListR(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *temp;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    temp = L;

    int i;
    for (i = 0; i < n; i++)
    {
        LinkNode *p;
        p = (LinkNode *)malloc(sizeof(LinkNode));
        p->data = a[i];
        p->next = temp->next;
        temp->next = p;
        temp = p;
    }
    temp->next = NULL;
};