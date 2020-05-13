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
			G->arc[i][j] = INT_MAX;
		}
	}
	cout << "请输入每条边之间的顶点编号(顶点编号从1开始),以及该边的权重:" << endl;
	int start;
	int end;
	int weight;
	for (i = 0; i < G->edge; i++)
	{
		cin >> start >> end >> weight;
		G->arc[start - 1][end - 1] = weight;
		G->arc[end - 1][start - 1] = weight;
	}
}
void PrintGraph(Graph *G)
{
	int i, j;
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			if (G->arc[i][j] == INT_MAX)
				cout << "0  ";
			else
				cout << G->arc[i][j]<<"  ";
		}
		cout << endl;
	}
}
struct Assis_Array//记录边的信息
{
	int start;
	int end;
	int weight;
};
void Prim(Graph *G, int begin)
{
	Assis_Array *close_edge = new Assis_Array[G->vexnum];
	int j;
	//初始化
	for (j = 0; j < G->vexnum; j++)
	{
		if (j != begin - 1)
		{
			close_edge[j].start = begin - 1;
			close_edge[j].end = j;
			close_edge[j].weight = G->arc[begin - 1][j];
		}
	}
	//把起点设置为-1代表已经加入到集合中
	close_edge[begin - 1].weight = -1;
	for (j = 1; j < G->vexnum; j++)
	{
		int min = INT_MAX;
		int k;
		int index;
		for (k = 0; k < G->vexnum; k++)
		{
			if(close_edge[k].weight!=-1)
				if (close_edge[k].weight < min)
				{
					min = close_edge[k].weight;
					index = k;
				}
		}
		close_edge[index].weight = -1;
		cout << close_edge[index].start + 1 << "----" << close_edge[index].end + 1 << "=" <<
			G->arc[close_edge[index].start][close_edge[index].end] << endl;
		for (k = 0; k < G->vexnum; k++)
		{
			if (G->arc[close_edge[index].end][k] < close_edge[k].weight)
			{
				close_edge[k].weight = G->arc[close_edge[index].end][k];
				close_edge[k].start = close_edge[index].end;
				close_edge[k].end = k;
			}
		}
	}
}
int main()
{
	Graph G;
	CreateGraph(&G);
	PrintGraph(&G);
	Prim(&G, 1);
	return 0;
}
