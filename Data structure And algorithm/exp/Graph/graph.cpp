#include<iostream>
#include<stack>
#include<queue>
#include<cstring>
#include<fstream>
using namespace std;
struct graph
{
    int vertexNum;
    int edgeNum;
    int **matrix;
};
//从文件读取图的邻接矩阵
void readGraph(graph &G)
{
    ifstream fin("graph.txt");
    fin >> G.vertexNum;
    fin >> G.edgeNum;
    G.matrix = new int *[G.vertexNum];
    for (int i = 0; i < G.vertexNum; i++)
    {
        G.matrix[i] = new int[G.vertexNum];
        for (int j = 0; j < G.vertexNum; j++)
        {
            fin >> G.matrix[i][j];
        }
    }
    fin.close();
}
//计算连通分支数
int connectedComponent(graph &G)
{
    int *visited = new int[G.vertexNum];
    memset(visited, 0, sizeof(int) * G.vertexNum);
    int count = 0;
    for (int i = 0; i < G.vertexNum; i++)
    {
        if (visited[i] == 0)
        {
            count++;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                for (int j = 0; j < G.vertexNum; j++)
                {
                    if (G.matrix[v][j] == 1 && visited[j] == 0)
                    {
                        q.push(j);
                        visited[j] = 1;
                    }
                }
            }
        }
    }
    delete[] visited;
    return count;
}
//计算顶点0所在有向图的强连通分支数
int strongConnectedComponent(graph &G)
{
    int *visited = new int[G.vertexNum];
    memset(visited, 0, sizeof(int) * G.vertexNum);
    int count = 0;
    stack<int> s;
    for (int i = 0; i < G.vertexNum; i++)
    {
        if (visited[i] == 0)
        {
            s.push(i);
            visited[i] = 1;
            while (!s.empty())
            {
                int v = s.top();
                s.pop();
                for (int j = 0; j < G.vertexNum; j++)
                {
                    if (G.matrix[v][j] == 1 && visited[j] == 0)
                    {
                        s.push(j);
                        visited[j] = 1;
                    }
                }
            }
        }
    }
    memset(visited, 0, sizeof(int) * G.vertexNum);
    for (int i = 0; i < G.vertexNum; i++)
    {
        if (visited[i] == 0)
        {
            count++;
            s.push(i);
            visited[i] = 1;
            while (!s.empty())
            {
                int v = s.top();
                s.pop();
                for (int j = 0; j < G.vertexNum; j++)
                {
                    if (G.matrix[j][v] == 1 && visited[j] == 0)
                    {
                        s.push(j);
                        visited[j] = 1;
                    }
                }
            }
        }
    }
    delete[] visited;
    return count;
}
//计算随机图边概率与连通分支数的关系
void connectedComponentProbability()
{
    ofstream fout("connectedComponentProbability.txt");
    //50次实验
    for (int i = 0; i < 50; i++)
    {
        graph G;
        G.vertexNum = 80;
        G.edgeNum = 100;
        G.matrix = new int *[G.vertexNum];
        for (int i = 0; i < G.vertexNum; i++)
        {
            G.matrix[i] = new int[G.vertexNum];
            for (int j = 0; j < G.vertexNum; j++)
            {
                G.matrix[i][j] = 0;
            }
        }
        //随机生成边
        for (int i = 0; i < G.edgeNum; i++)
        {
            int v1 = rand() % G.vertexNum;
            int v2 = rand() % G.vertexNum;
            while (v1 == v2 || G.matrix[v1][v2] == 1)
            {
                v1 = rand() % G.vertexNum;
                v2 = rand() % G.vertexNum;
            }
            G.matrix[v1][v2] = 1;
        }
        //计算连通分支数
        int count = connectedComponent(G);
        //输出边概率与连通分支数的关系
        fout << (double)G.edgeNum / (G.vertexNum * (G.vertexNum - 1)) << " " << count << endl;
        for (int i = 0; i < G.vertexNum; i++)
        {
            delete[] G.matrix[i];
        }
        delete[] G.matrix;
    }
    fout.close();
}
int main()
{
    graph G;
    readGraph(G);
    cout << "连通分支数：" << connectedComponent(G) << endl;
    connectedComponentProbability();
    cout << "顶点0所在有向图强连通分支数：" << strongConnectedComponent(G) << endl;
    return 0;
}