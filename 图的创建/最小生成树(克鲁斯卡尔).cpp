#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
struct Graph
{
	int vexnum;
	int edge;
	int **arc;
};
void CreateGraph(Graph *G)
{
	cout << "请输入顶点数 边数:" << endl;
	cin >> G->vexnum >> G->edge;
	G->arc = new int*[G->vexnum];
	int i, j;
	for (i = 0; i < G->vexnum; i++)
	{
		G->arc[i] = new int[G->vexnum];
		for (j = 0; j < G->vexnum; j++)
		{
			G->arc[i][j] = 0;
		}
	}
	cout << "请输入每条边之间的顶点编号(顶点编号从0开始),以及该边的权重:" << endl;
	int start;
	int end;
	int weight;
	for (i = 0; i < G->edge; i++)
	{
		cin >> start >> end >> weight;
		G->arc[start][end] = weight;
		G->arc[end][start] = weight;
	}
}
void PrintGraph(Graph *G)
{
	int i, j;
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			if (G->arc[i][j] == 0)
				cout << "0  ";
			else
				cout << G->arc[i][j] << "  ";
		}
		cout << endl;
	}
}
typedef struct Edge//记录边的信息
{
	int start;
	int end;
	int weight;
}Edge;
int Find(int parent[], int f)
{
	while (parent[f] > 0) {
		f = parent[f];
	}
	return f;
}
bool cmp(Edge edge1, Edge edge2)
{
	return edge1.weight < edge2.weight;
}
void Kruskal(const Graph *G)
{
	Edge *Edges = new Edge[G->edge];
	//邻接矩阵转换为边集数组
	int k = 0;
	int i, j;
	for(i=0;i<G->vexnum;i++)
		for (j = i; j < G->vexnum; j++)
		{
			if (G->arc[i][j] != 0)
			{
				Edges[k].start = i;
				Edges[k].end = j;
				Edges[k].weight = G->arc[i][j];
				k++;
			}			
		}
	sort(Edges,Edges+G->edge,cmp);
	/*for(int i=0;i<G->edge;i++)
		for (int j = 0; j < G->edge - 1 - i; j++)
		{
			if (Edges[j].weight > Edges[j + 1].weight)
			{
				Edge temp = Edges[j];
				Edges[j] = Edges[j + 1];
				Edges[j + 1] = temp;
			}
		}*/
	int n, m;


	int *parent = new int[G->edge];
	for (i = 0; i < G->edge; i++)
	{
		parent[i] = 0;
	}

	for (i = 0; i < G->edge; i++)
	{
		Edge edge = Edges[i];
		n = Find(parent, edge.start);
		m = Find(parent, edge.end);
		if (n != m)
		{

			cout << "(" << edge.start << "," << edge.end << ")" << "---->" << edge.weight << endl;
			parent[n] = m;
		}
	}
}
int main()
{
	Graph G;
	CreateGraph(&G);
	Kruskal(&G);
}
//9 15
//0 1 10
//0 5 11
//1 2 18
//1 6 16
//1 8 12
//2 8 8
//2 3 22
//3 8 21
//3 6 24
//3 4 20
//3 7 16
//4 5 26
//4 7 7
//5 6 17
//6 7 19
