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
//initaluize a polynomial
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
//print a polynomial
void printPolynomial (polynomial *p)
{
    if(firstNode->next==NULL)
        printf("0\n");
    Node * theNode=p->firstNode;
    while(theNode->next!=NULL)
    {
        printf("+%fX^%d",theNode->m.coefficient,theNode->m.exponent);
        theNode=theNode->next;
    }
    printf("\n");
}
//free memory
void freePolynomial (polynomial *p)
{
    Node * theNode=p->firstNode;
    while(p->firstNode->next!=NULL)
    {
        theNode=p-firstNode->next;
        p->firstNode->next=theNode->next;
        free(theNode);
    }
    free(p);
}
//add two polynomials
polynomial * addPolynomial(polynomial * p1,polynomial * p2)
{
    polynomial * result=(polynomial *)malloc(sizeof(polynomial));
    Node *idx1=p1->firstNode->next;
    Node *idx2=p2->firstNode->next;
    Node *idx=result->firstNode;
    while(idx1!=NULL ||idx2!=NULL)
    {
        if(idx1==NULL)
        
    }
}