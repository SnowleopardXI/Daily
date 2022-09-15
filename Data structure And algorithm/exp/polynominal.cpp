#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
struct monomial
{
    int exponent;
    float coefficient;
};
struct Node
{
    monomial m;
    Node *next;
};
struct polynomial
{
    Node firstNode;
    Node *lastNode;
};
// initalize a polynomial
void initPolynomial(polynomial *p, monomial *input, int count)
{
    p->firstNode.next = NULL;
    p->lastNode = &p->firstNode;
    for (int i = 0; i < count; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->m = input[i];
        newNode->next = NULL;
        p->lastNode->next = newNode;
        p->lastNode = newNode;
    }
}
// print polynomial
void printPolynomial(polynomial *p)
{
    Node *node = p->firstNode.next;
    while (node != NULL)
    {
        printf("%fX^%d", node->m.coefficient, node->m.exponent);
        node = node->next;
        if (node != NULL)
        {
            printf("+");
        }
    }
    printf("\n");
}
// free polynomial
void freePolynomial(polynomial *p)
{
    Node *theNode;
    Node *node = p->firstNode.next;
    while (node != NULL)
    {
        theNode = node;
        node = node->next;
        free(theNode);
    }
    free(p);
}
// add two polynomials
polynomial *addPolynomial(polynomial *p1, polynomial *p2)
{
    polynomial *result = (polynomial *)malloc(sizeof(polynomial));
    Node *idx1 = p1->firstNode.next;
    Node *idx2 = p2->firstNode.next;
    Node *idx = &result->firstNode;
    while (idx1 != NULL && idx2 != NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = NULL;
        if (idx1->m.exponent == idx2->m.exponent)
        {
            newNode->m.exponent = idx1->m.exponent;
            newNode->m.coefficient = idx1->m.coefficient + idx2->m.coefficient;
            idx1 = idx1->next;
            idx2 = idx2->next;
        }
        else if (idx1->m.exponent > idx2->m.exponent)
        {
            newNode->m.exponent = idx1->m.exponent;
            newNode->m.coefficient = idx1->m.coefficient;
            idx1 = idx1->next;
        }
        else
        {
            newNode->m.exponent = idx2->m.exponent;
            newNode->m.coefficient = idx2->m.coefficient;
            idx2 = idx2->next;
        }
        idx->next = newNode;
        idx = newNode;
    }
    while (idx1 != NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = NULL;
        newNode->m.exponent = idx1->m.exponent;
        newNode->m.coefficient = idx1->m.coefficient;
        idx1 = idx1->next;
        idx->next = newNode;
        idx = newNode;
    }
    while (idx2 != NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = NULL;
        newNode->m.exponent = idx2->m.exponent;
        newNode->m.coefficient = idx2->m.coefficient;
        idx2 = idx2->next;
        idx->next = newNode;
        idx = newNode;
    }
    result->lastNode = idx;
    return result;
}
// substract two polynomials
polynomial *substractPolynomial(polynomial *p1, polynomial *p2)
{
    polynomial *result = (polynomial *)malloc(sizeof(polynomial));
    Node *idx1 = p1->firstNode.next;
    Node *idx2 = p2->firstNode.next;
    Node *idx = &result->firstNode;
    while (idx1 != NULL && idx2 != NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = NULL;
        if (idx1->m.exponent == idx2->m.exponent)
        {
            newNode->m.exponent = idx1->m.exponent;
            newNode->m.coefficient = idx1->m.coefficient - idx2->m.coefficient;
            idx1 = idx1->next;
            idx2 = idx2->next;
        }
        else if (idx1->m.exponent > idx2->m.exponent)
        {
            newNode->m.exponent = idx1->m.exponent;
            newNode->m.coefficient = idx1->m.coefficient;
            idx1 = idx1->next;
        }
        else
        {
            newNode->m.exponent = idx2->m.exponent;
            newNode->m.coefficient = -idx2->m.coefficient;
            idx2 = idx2->next;
        }
        idx->next = newNode;
        idx = newNode;
    }
    while (idx1 != NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = NULL;
        newNode->m.exponent = idx1->m.exponent;
        newNode->m.coefficient = idx1->m.coefficient;
        idx1 = idx1->next;
        idx->next = newNode;
        idx = newNode;
    }
    while (idx2 != NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = NULL;
        newNode->m.exponent = idx2->m.exponent;
        newNode->m.coefficient = -idx2->m.coefficient;
        idx2 = idx2->next;
        idx->next = newNode;
        idx = newNode;
    }
    result->lastNode = idx;
    return result;
}
// multiply two polynomials
polynomial *multiplyPolynomial(polynomial *p1, polynomial *p2)
{
    polynomial *result = (polynomial *)malloc(sizeof(polynomial));
    Node *idx1 = p1->firstNode.next;
    Node *idx2 = p2->firstNode.next;
    Node *idx = &result->firstNode;
    while (idx1 != NULL)
    {
        while (idx2 != NULL)
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->next = NULL;
            newNode->m.exponent = idx1->m.exponent + idx2->m.exponent;
            newNode->m.coefficient = idx1->m.coefficient * idx2->m.coefficient;
            idx2 = idx2->next;
            idx->next = newNode;
            idx = newNode;
        }
        idx1 = idx1->next;
        idx2 = p2->firstNode.next;
    }
    result->lastNode = idx;
    return result;
}
// divide two polynomials
polynomial *dividePolynomial(polynomial *p1, polynomial *p2)
{
    polynomial *result = (polynomial *)malloc(sizeof(polynomial));
    Node *idx1 = p1->firstNode.next;
    Node *idx2 = p2->firstNode.next;
    Node *idx = &result->firstNode;
    while (idx1 != NULL)
    {
        while (idx2 != NULL)
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->next = NULL;
            newNode->m.exponent = idx1->m.exponent - idx2->m.exponent;
            newNode->m.coefficient = idx1->m.coefficient / idx2->m.coefficient;
            idx2 = idx2->next;
            idx->next = newNode;
            idx = newNode;
        }
        idx1 = idx1->next;
        idx2 = p2->firstNode.next;
    }
    result->lastNode = idx;
    return result;
}

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2, *outfile;
    fp1 = fopen(argv[1], "r");
    int a, c, i = 0, j = 0, k = 0;
    int lines1 = 0, lines2 = 0;
    while ((c = fgetc(fp1)) != EOF)
    {
        if (c == '\n')
            lines1++;
    }
    lines1++;
    fclose(fp1);
    monomial po1[lines1 + 1];
    float coefficient;
    int exponent;
    fp1 = fopen(argv[1], "r"); //打开并读取参数argv[1]对应的输入文件
    while (!feof(fp1))         // feof本身是一个非负的整型常量，表明以达到文件末尾
    {
        fscanf(fp1, "%d,%f", &exponent, &coefficient);
        po1[i].exponent = exponent;
        po1[i].coefficient = coefficient;
        i++;
    }
    fclose(fp1);
    i = 0, j = 0;
    fp2 = fopen(argv[2], "r"); //打开并读取参数argv[2]对应的输入文件
    while ((c = fgetc(fp2)) != EOF)
    {
        if (c == '\n')
            lines2++;
    }
    lines2++;
    fclose(fp2);
    monomial po2[lines2 + 1];
    fp2 = fopen(argv[2], "r");
    while (!feof(fp2)) // feof本身是一个非负的整型常量，表明以达到文件末尾
    {
        fscanf(fp2, "%d,%f", &exponent, &coefficient);
        po2[j].exponent = exponent;
        po2[j].coefficient = coefficient;
        j++;
    }
    fclose(fp2);
    polynomial *p1 = (polynomial *)malloc(sizeof(polynomial));
    polynomial *p2 = (polynomial *)malloc(sizeof(polynomial));
    initPolynomial(p1, po1, lines1);
    initPolynomial(p2, po2, lines2);
    polynomial *add = standardizePolynomial(addPolynomial(p1, p2));
    polynomial *sub = standardizePolynomial(substractPolynomial(p1, p2));
    polynomial *mul = standardizePolynomial(multiplyPolynomial(p1, p2));
    polynomial *div = standardizePolynomial(dividePolynomial(p1, p2));
    /*For debugging
    printf("line1=%d,line2=%d\n",lines1,lines2);
    printf("p1:\n");
    for (i = 0; i < lines1; i++)
    {
        printf("%d\t%f\n", po1[i].exponent, po1[i].coefficient);
    }
    printf("p2:\n");
    for (j = 0; j < lines2; j++)
    {
        printf("%d\t%f\n", po2[j].exponent, po2[j].coefficient);
    }
    printf("out:\n");
    printPolynomial(out);
    */
    outfile = fopen(argv[3], "w"); //打开并读取参数argv[3]对应的输出文件
    Node *idx = add->firstNode.next;
    while (idx != NULL)
    {
        fprintf(outfile, "%d,%f\n", idx->m.exponent, idx->m.coefficient);
        idx = idx->next;
    }
    fprintf(outfile, "\n");
    idx = sub->firstNode.next;
    while (idx != NULL)
    {
        fprintf(outfile, "%d,%f\n", idx->m.exponent, idx->m.coefficient);
        idx = idx->next;
    }
    fprintf(outfile, "\n");
    idx = mul->firstNode.next;
    while (idx != NULL)
    {
        fprintf(outfile, "%d,%f\n", idx->m.exponent, idx->m.coefficient);
        idx = idx->next;
    }
    fprintf(outfile, "\n");
    idx = div->firstNode.next;
    while (idx != NULL)
    {
        fprintf(outfile, "%d,%f\n", idx->m.exponent, idx->m.coefficient);
        idx = idx->next;
    }
    fclose(outfile);
    freePolynomial(p1);
    freePolynomial(p2);
    freePolynomial(add);
    freePolynomial(sub);
    freePolynomial(mul);
    freePolynomial(div);
    fclose(outfile);
    return 0;
}
