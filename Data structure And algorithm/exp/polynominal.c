#include <stdio.h>
#include <stdlib.h>
struct monomial
{
    int exponent;
    floast coefficient;
};
struct node
{
    monomial m;
    Node * next;
}
struct polynomial
{
    Node firstNode;
}
void initPolynomial (polynomial *p, monomial *input, int count)
{
    memset(p->firstNode,0,sizeof(node));
    Node * rear= p->firstNode;
    for (int i=0;i<count;i++)
    {
        rear->next = (Node *)malloc(sizeof(Node));
        rear = rear->next;
        rear->m.exponent=input[i].exponent;
        rear->m.coefficient=input[i].coefficient;
        rear->next=NULL;
    }
}
void printPolynomial (polynomial *p)
{
    Node * rear = p->firstNode->next;
    while (rear!=NULL)
    {
        printf("%f*x^%d",rear->m.coefficient,rear->m.exponent);
        rear=rear->next;
    }
}