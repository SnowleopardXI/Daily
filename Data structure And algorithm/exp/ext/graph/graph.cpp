#include <iostream>
#include <cstring>
using namespace std;
#define MAX_VERTEX_NUM 8 // 顶点最大个数
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
    int weight;        // 边的权
} ArcNode;             // 表结点
#define VertexType int // 顶点元素类型
typedef struct VNode
{
    int degree, indegree; // 顶点的度，入度
    VertexType data;
    ArcNode *firstarc;
} Vnode, AdjList[MAX_VERTEX_NUM];
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum; // 顶点的实际数，边的实际数
} ALGraph;
void CreateGraph(ALGraph &G)
{
    int i, j, k;
    ArcNode *p;
    cout << "请输入顶点数和边数：";
    cin >> G.vexnum >> G.arcnum;
    cout << "请输入顶点信息：";
    for (i = 0; i < G.vexnum; i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
        G.vertices[i].degree = 0;
        G.vertices[i].indegree = 0;
    }
    cout << "请输入边的信息：";
    for (k = 0; k < G.arcnum; k++)
    {
        cin >> i >> j;
        p = new ArcNode;
        p->adjvex = j;
        p->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p;
        G.vertices[i].degree++;
        G.vertices[j].indegree++;
    }
}
void DestroyGraph(ALGraph &G)
{
    int i;
    ArcNode *p, *q;
    for (i = 0; i < G.vexnum; i++)
    {
        p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            q = p;
            p = p->nextarc;
            delete q;
        }
    }
}
void DisplayGraph(ALGraph G)
{
    int i;
    ArcNode *p;
    cout << "图的邻接表为：" << endl;
    for (i = 0; i < G.vexnum; i++)
    {
        cout << G.vertices[i].data << " ";
        p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            cout << p->adjvex << " ";
            p = p->nextarc;
        }
        cout << endl;
    }
}
void DFS(ALGraph G, int v, bool visited[])
{
    ArcNode *p;
    cout << G.vertices[v].data << " ";
    visited[v] = true;
    p = G.vertices[v].firstarc;
    while (p != NULL)
    {
        if (!visited[p->adjvex])
            DFS(G, p->adjvex, visited);
        p = p->nextarc;
    }
}
void DFSTraverse(ALGraph G)
{
    int i;
    bool visited[MAX_VERTEX_NUM];
    for (i = 0; i < G.vexnum; i++)
        visited[i] = false;
    for (i = 0; i < G.vexnum; i++)
        if (!visited[i])
            DFS(G, i, visited);
}
void BFS(ALGraph G, int v, bool visited[])
{
    int q[MAX_VERTEX_NUM], front = 0, rear = 0;
    ArcNode *p;
    cout << G.vertices[v].data << " ";
    visited[v] = true;
    q[rear++] = v;
    while (front != rear)
    {
        v = q[front++];
        p = G.vertices[v].firstarc;
        while (p != NULL)
        {
            if (!visited[p->adjvex])
            {
                cout << G.vertices[p->adjvex].data << " ";
                visited[p->adjvex] = true;
                q[rear++] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
}
void BFSTraverse(ALGraph G)
{
    int i;
    bool visited[MAX_VERTEX_NUM];
    for (i = 0; i < G.vexnum; i++)
        visited[i] = false;
    for (i = 0; i < G.vexnum; i++)
        if (!visited[i])
            BFS(G, i, visited);
}
int main()
{
    ALGraph G;
    int choice;
    bool flag = true;
    while (flag)
    {
        cout << "1.创建图" << endl;
        cout << "2.销毁图" << endl;
        cout << "3.显示图" << endl;
        cout << "4.深度优先遍历" << endl;
        cout << "5.广度优先遍历" << endl;
        cout << "6.退出" << endl;
        cout << "请输入你的选择：";
        cin >> choice;
        switch (choice)
        {
        case 1:
            CreateGraph(G);
            break;
        case 2:
            DestroyGraph(G);
            break;
        case 3:
            DisplayGraph(G);
            break;
        case 4:
            DFSTraverse(G);
            cout << endl;
            break;
        case 5:
            BFSTraverse(G);
            cout << endl;
            break;
        case 6:
            flag = false;
            break;
        default:
            cout << "输入错误！" << endl;
            break;
        }
    }
    return 0;
}
