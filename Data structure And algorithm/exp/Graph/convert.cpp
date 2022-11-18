#include <bits/stdc++.h>
using namespace std;
//图的邻接表存储结构定义如下
const int MaxVertexNum = 100; // 图中顶点数目的最大值
typedef struct ArcNode
{                         //边表结点
    int adjvex;           // 该弧所指向的顶点的位置
    struct ArcNode *next; //指向下一条弧的指针
} ArcNode;
typedef struct VNode
{                   //顶点表结点
    ArcNode *first; // 指向第一条依附该顶点的弧的指针
} VNode, AdjList[MaxVertexNum];
typedef struct
{
    AdjList vertices;   //邻接表
    int vexnum, arcnum; //图的顶点数和弧数
} ALGraph;              // ALGraph是以邻接表存储的图类型

//图的邻接矩阵存储结构定义如下
typedef struct
{
    int Edge[MaxVertexNum][MaxVertexNum]; //邻接矩阵，边表
    int vexnum, arcnum;                   //图的当前顶点数和弧数
} MGraph;

void Create_Graph(ALGraph &AG, MGraph &MG)
{                                          //创建一个邻接表和邻接矩阵
    scanf("%d%d", &AG.vexnum, &AG.arcnum); //输入图的顶点数和边数
    MG.arcnum = AG.arcnum;
    MG.vexnum = AG.vexnum;
    for (int i = 1; i <= MG.vexnum; i++)
    { // 初始化邻接矩阵
        for (int j = 1; j <= MG.vexnum; j++)
        {
            MG.Edge[i][j] = 0;
        }
    }
    for (int i = 1; i <= AG.vexnum; i++)
    {
        AG.vertices[i].first = NULL; //初始化第一条依附该顶点的弧的指针为空
    }
    ArcNode *p;
    for (int i = 0; i < AG.arcnum; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v); // u, v表示u有一条边指向v;
        MG.Edge[u][v] = 1;
        p = (ArcNode *)malloc(sizeof(ArcNode)); // p = new ArcNode;
        p->adjvex = v;
        p->next = AG.vertices[u].first; //用头插法将v插到结点u的边表结点中
        AG.vertices[u].first = p;       // 插入后将第一条依附该顶点的弧的指针修改为p
    }
}

void matrix_convert_table(ALGraph &G1, MGraph G2)
{ // 邻接矩阵转化为邻接表
    G1.arcnum = G2.arcnum;
    G1.vexnum = G2.vexnum;
    for (int i = 1; i <= G1.vexnum; i++)
    {
        G1.vertices[i].first = NULL; // 初始化指向第一条依附该顶点的弧的指针
    }
    ArcNode *p;
    for (int i = 1; i <= G2.vexnum; i++)
    { // 依次遍历整个邻接矩阵
        for (int j = 1; j <= G2.vexnum; j++)
        {
            if (G2.Edge[i][j] == 1)
            {
                p = (ArcNode *)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->next = G1.vertices[i].first;
                G1.vertices[i].first = p;
            }
        }
    }
}

void table_convert_matrix(MGraph &G1, ALGraph G2)
{ // 邻接表转化为邻接矩阵
    G1.arcnum = G2.arcnum;
    G1.vexnum = G2.vexnum;
    for (int i = 1; i <= G1.vexnum; i++)
    {
        for (int j = 1; j <= G1.vexnum; j++)
        {
            G1.Edge[i][j] = 0; // 初始化邻接矩阵
        }
    }
    ArcNode *p;
    for (int i = 1; i <= G2.vexnum; i++)
    {                             //依次遍历各顶点表结点为头的边链表
        p = G2.vertices[i].first; // 取出顶点 i 的第一条出边
        while (p)
        { //遍历边链表
            G1.Edge[i][p->adjvex] = 1;
            p = p->next; // 取出下一条出边
        }
    }
}

void print_matrix(MGraph G)
{ // 打印邻接矩阵
    for (int i = 1; i <= G.vexnum; i++)
    {
        for (int j = 1; j <= G.vexnum; j++)
        {
            cout << G.Edge[i][j] << " ";
        }
        puts("");
    }
}
void print_table(ALGraph G)
{ // 打印邻接表
    for (int i = 1; i <= G.vexnum; i++)
    {
        printf("(%d) ", i);
        ArcNode *p = G.vertices[i].first;
        while (p)
        {
            printf("-> %d ", p->adjvex);
            p = p->next;
        }
        puts("");
    }
}
int main()
{
    MGraph MG1, MG2;
    ALGraph AG1, AG2;
    Create_Graph(AG1, MG1);
    cout << endl;
    print_matrix(MG1);
    cout << endl;
    print_table(AG1);
    cout << endl;
    matrix_convert_table(AG2, MG1); // 邻接矩阵转邻接表
    print_table(AG2);               // 打印转化后的邻接表
    cout << endl;
    table_convert_matrix(MG2, AG1); // 邻接表转邻接矩阵
    print_matrix(MG2);              // 打印转化后的邻接矩阵

    return 0;
}