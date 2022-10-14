#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
struct Vertex
{
    int Vname;
};
int VertexCount = 0;
Vertex VertexSet[N];

struct Edge
{
    int v1;
    int v2;
};
int EdgeCount = 0;
Edge EdgeSet[N];
//加载数据
void loadData()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR!");
    }
    fscanf(fp, "%d\n", &VertexCount);
    int i;
    for (i = 0; i < VertexCount; i++)
    {
        VertexSet[i].Vname = i + 1;
    }
    while (!feof(fp))
    {
        fscanf(fp, "%d,%d\n", &EdgeSet[EdgeCount].v1, &EdgeSet[EdgeCount].v2);
        EdgeCount++;
    }
}
//打印读入的数据
void printDate()
{
    printf("VertextCount is %d\n", VertexCount);
    int i;
    for (i = 0; i < EdgeCount; i++)
    {
        printf("%d,%d\n", EdgeSet[i].v1, EdgeSet[i].v2);
    }
}
//建立双亲表示法结点结构
struct parentTree
{
    int Vname;
    int parentIndex;
    int k;
};
parentTree parentNode[N];

#define unknown -1000
void BuildParentTree()
{
    int i, j, k;
    for (i = 0; i < VertexCount; i++)
    {
        parentNode[i].Vname = VertexSet[i].Vname;
        parentNode[i].parentIndex = unknown;
    }
    parentNode[0].parentIndex = -1;
    for (i = 0; i < VertexCount; i++)
    {
        for (j = 1; j < VertexCount; j++)
        {
            for (k = 0; k < EdgeCount; k++)
            {
                if (
                    (EdgeSet[k].v1 == parentNode[i].Vname &&
                     EdgeSet[k].v2 == parentNode[j].Vname &&
                     parentNode[i].parentIndex != unknown &&
                     parentNode[j].parentIndex == unknown) ||
                    (EdgeSet[k].v1 == parentNode[j].Vname &&
                     EdgeSet[k].v2 == parentNode[i].Vname &&
                     parentNode[i].parentIndex != unknown &&
                     parentNode[j].parentIndex == unknown))
                {
                    parentNode[j].parentIndex = i;
                }
            }
        }
    }
    //求层数
    for (i = 0; i < VertexCount; i++)
    {
        parentNode[i].k = 0;
        for (j = i; parentNode[j].parentIndex != -1; j = parentNode[j].parentIndex)
        {
            parentNode[i].k++;
        }
    }
}
//凸凹表示法输出
void printParentTree(int v)
{
    if (v == 0)
    {
        printf("%d\n", parentNode[v].Vname);
    }
    int i, j;
    for (i = 0; i < VertexCount; i++)
    {
        if (parentNode[i].parentIndex == v)
        {
            for (j = 0; j < parentNode[i].k; j++)
            {
                printf("\t");
            }
            printf("%d\n", parentNode[i].Vname);
            printParentTree(i);
        }
    }
}
//孩子兄弟表示法树的建立
struct BrotherChildTree
{
    int Vname;
    BrotherChildTree *firstchild;
    BrotherChildTree *nextsibling;
};
void buildBCTree(int index, BrotherChildTree *T)
{
    int tIndex;
    int i;
    //找孩子
    for (i = 0; i < VertexCount; i++)
    {
        if (parentNode[i].parentIndex == index)
        {
            BrotherChildTree *p = (BrotherChildTree *)malloc(sizeof(BrotherChildTree));
            p->Vname = parentNode[i].Vname;
            p->firstchild = NULL;
            p->nextsibling = NULL;
            T->firstchild = p;
            T->nextsibling = NULL;
            tIndex = i;
            break;
        }
    }
    if (T->firstchild != NULL)
    {
        buildBCTree(tIndex, T->firstchild);
    }
    //找兄弟
    for (i = index + 1; i < VertexCount; i++)
    {
        if (parentNode[i].parentIndex == parentNode[index].parentIndex)
        {
            BrotherChildTree *p = (BrotherChildTree *)malloc(sizeof(BrotherChildTree));
            p->Vname = parentNode[i].Vname;
            p->firstchild = NULL;
            p->nextsibling = NULL;
            T->nextsibling = p;
            tIndex = i;
            break;
        }
    }
    if (T->nextsibling != NULL)
    {
        buildBCTree(tIndex, T->nextsibling);
    }
}
//括号表示法输出
void printBCTree(BrotherChildTree *root,char *string){
	strcat(string,"(");
	char temp[10];
    sprintf(temp,"%d",root->Vname);
    strcat(string,temp);
    if(root->firstchild!=NULL){
    	strcat(string,",");
		printBCTree(root->firstchild,string);
	} 
	if(root->nextsibling != NULL){
		strcat(string,",");
   		printBCTree(root->nextsibling,string);
	}
	strcat(string,")");
}

int main()
{
    loadData();
    BuildParentTree();
    printParentTree(0);
    BrotherChildTree *root =
        (BrotherChildTree *)malloc(sizeof(BrotherChildTree));
    root->Vname = parentNode[0].Vname;
    root->firstchild = NULL;
    root->nextsibling = NULL;
    buildBCTree(0, root);
    char string[1000] = " ";
    printBCTree(root, string);
    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL)
    {
        printf("open file error");
        return 0;
    }
    fprintf(fp, "%s", string);
    fclose(fp);
    printf("%s", string);
}
