#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define MAXVEX 20
typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode *next;
}EdgeNode;//边表节点

typedef struct VertexNode
{
	char data;
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];//顶点表节点

typedef struct
{
	AdjList adjlist;
	int numVertexes, numEdges;
}GraphAdjList;
void Create(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *p = NULL;
	cout << "输入顶点和边数:" << endl;
	cin >> G->numVertexes >> G->numEdges;
	cout << "输入顶点信息:" << endl;
	for (i = 0; i < G->numVertexes; i++)
	{
		cin >> G->adjlist[i].data;
		G->adjlist[i].firstedge = NULL;
	}
	cout << "输入边<Vi,Vj>中的下标i,j:" << endl;
	for (k = 0; k < G->numEdges; k++)
	{
		cin >> i >> j;
		p = new EdgeNode;
		p->adjvex = j;
		p->next = G->adjlist[i].firstedge;
		G->adjlist[i].firstedge = p;

#if 1
		//无向图则有下面代码
		p = new EdgeNode;
		p->adjvex = i;
		p->next = G->adjlist[j].firstedge;
		G->adjlist[j].firstedge = p;
#endif
	}
}
void Print(GraphAdjList *G)
{
	int i;
	EdgeNode *p = NULL;
	for (i = 0; i < G->numVertexes; i++)
	{
		p = G->adjlist[i].firstedge;
		while (p)
		{
			cout << "(" << G->adjlist[i].data << "," << G->adjlist[p->adjvex].data << ")";
			p = p->next;
		}
		cout << endl;
	}
}
int visited[100];
void DFS(GraphAdjList *G, int i)
{
	EdgeNode *p = NULL;
	visited[i] = 1;
	cout << G->adjlist[i].data << "--";
	p = G->adjlist[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFS(G, p->adjvex);
		}
		p = p->next;
	}
}
void DFSTraverse(GraphAdjList *G)
{
	cout << "深度遍历的结果:" << endl;
	for (int i = 0; i < G->numVertexes; i++)
		visited[i] = 0;
	for (int i = 0; i < G->numVertexes; i++)
	{
		if (!visited[i])
		{
			DFS(G, i);
		}
	}
	cout << endl;
}
void BFS(GraphAdjList *G, int v)
{
	cout << "广度优先结果:" << endl;
	int w, i;
	EdgeNode *p = NULL;
	queue<int> que;
	for (i = 0; i < G->numVertexes; i++)
		visited[i] = 0;
	cout << G->adjlist[v].data << "--";
	visited[v] = 1;
	que.push(v);
	while (!que.empty())
	{
		w = que.front();
		que.pop();
		p = G->adjlist[w].firstedge;
		while (p)
		{
			if (visited[p->adjvex] == 0)
			{
				cout << G->adjlist[p->adjvex].data << "--";
				visited[p->adjvex] = 1;
				que.push(p->adjvex);
			}
			p = p->next;
		}
	}
	cout << endl;
}
int main()
{
	GraphAdjList G;
	Create(&G);
	Print(&G);
	DFSTraverse(&G);
	BFS(&G, 0);
	return 0;
}
