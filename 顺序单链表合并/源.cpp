#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct LNode
{
	int date;
	struct LNode *next;
};
typedef struct LNode LNode;
typedef struct LNode *LinkList;
LNode* CreatList(int n)
{
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LinkList p = NULL;
	LinkList ptr = L;
	printf("请输入%d个数", n);
	for (int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->date);
		ptr->next = p;
		ptr = p;
	}
	ptr->next = NULL;
	return L;
}
void Merge(LinkList a, LinkList b, LinkList c)
{
	while (a&&b)
	{
		
		if (a->date > b->date)
		{
			c->next = b;
			c = b;
			b = b->next;
		}
		else
		{
			c->next = a;
			c = a;
			a = a->next;
		}
#if 1
		if (a->date == b->date)
		{
			a = a->next;
		}
#endif
	}
	while (a)
	{
		c->next = a;
		c = a;
		a = a->next;
	}
	while (b)
	{
		c->next = b;
		c = b;
		b = b->next;
	}
}
void Free(LNode *L)
{
	LNode *ptr = NULL;
	while (L != NULL)
	{
		ptr = L;
		L = L->next;
		free(ptr);
		ptr = NULL;
	}
}
int main()
{
	LinkList La = NULL;
	LinkList Lb = NULL;
	LinkList Lc = NULL;
	int n = 0;
	printf("输入第一条链的长度:");
	scanf("%d", &n);
	int m = 0;
	printf("输入第二条链的长度:");
	scanf("%d", &m);
	La = CreatList(n);
	Lb = CreatList(m);
	Lc = (LinkList)malloc(sizeof(LNode));
	LinkList c = Lc;
	Lc->next = NULL;
	Merge(La->next,Lb->next,Lc);
	Lc = Lc->next;
	while (Lc)
	{
		printf("%d ", Lc->date);
		Lc = Lc->next;
	}
	Free(c);
	c = NULL;
	return 0;
}
