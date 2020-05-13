#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct SqList
{
	int *elem;
	int length;
};
typedef struct SqList SqList;
SqList CreatList(SqList L)
{
	int n;
	printf("请输入表的长度：");
	scanf("%d", &n);
	L.elem = (int *)malloc(sizeof(int)*n);
	L.length = n;
	printf("请从小到大输入%d个数\n",n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &L.elem[i]);
	}
	return L;
}
int Merge(int lengthA, int lengthB, int *a, int *b, int *c)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < lengthA&&j < lengthB)
	{
		if (a[i] == b[j])
		{
			i++;
			continue;
		}
		if (a[i] < b[j])
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = b[j++];
		}
	}
	while (i < lengthA)
	{
		c[k++] = a[i++];
	}
	while (j < lengthB)
	{
		c[k++] = b[j++];
	}
	return k;
}
void Free(SqList *L)
{
	if (L->elem != NULL)
	{
		free(L->elem);
		L->elem = NULL;
	}
}
int main()
{
	SqList La;
	La.elem = NULL;
	La.length = 0;
	SqList Lb;
	Lb.elem = NULL;
	Lb.length = 0;
	SqList Lc;
	La = CreatList(La);
	Lb = CreatList(Lb);
	Lc.elem = (int *)malloc(sizeof(int)*(La.length + Lb.length));
	Lc.length = La.length + Lb.length;
	int n = Merge(La.length, Lb.length, La.elem, Lb.elem, Lc.elem);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", Lc.elem[i]);
	}
	Free(&La);
	Free(&Lb);
	Free(&Lc);
	return 0;
}
