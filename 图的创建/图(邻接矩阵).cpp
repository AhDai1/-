#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXNUM 100
typedef struct
{
	char vertex[MAXNUM];
	int arcs[MAXNUM][MAXNUM];
	int vexnum, arcsnum;
}Graph;
void Create(Graph *G)
{
	int i, j;
	cout << "���붥��ͱ���:" << endl;
	cin >> G->vexnum >> G->arcsnum;
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j] = 0;
		}
	}
	cout << "���붥����Ϣ:" << endl;
	for (i = 0; i < G->vexnum; i++)
		cin >> G->vertex[i];
	cout << "�����(Vi,Vj)�е��±�i,j:" << endl;
	for (int k = 0; k < G->arcsnum; k++)
	{
		//����ͼ
		cin >> i >> j;
		G->arcs[i][j] = 1;
		G->arcs[j][i] = 1;
	}
}
void Print(Graph *G)
{
	int i, j;
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			printf("%2d", G->arcs[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	Graph G;
	Create(&G);
	Print(&G);
	return 0;
}
