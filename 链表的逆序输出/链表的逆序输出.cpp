#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
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
	printf("请输入%d个数\n", n);
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
/*
	递归方式从尾到头打印
*/
void Print_Recursion(LNode *L)
{
	if (L->next != NULL)
		Print_Recursion(L->next);
	cout << L->date << "  ";
}
/*
	逆转节点,改变链表结构
*/
LNode* Change_Node(LNode *L)
{
	LNode *pre = NULL;
	pre = L->next;

	LNode *cur = NULL;
	cur = L->next->next;

	pre->next = NULL;

	LNode *temp = NULL;
	while (cur != NULL)
	{
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	L->next = pre;
	return L;
}
void Print_List(LNode *L)
{
	L = L->next;
	while(L != NULL)
	{
		cout << L->date << " ";
		L = L->next;
	}
}
/*
	正常从尾到头打印
*/
void Print_Normal(LNode *L)
{
	L = L->next;
	LNode *cur = NULL;
	LNode *tail = NULL;
	while (L != tail)
	{
		cur = L;
		while (cur->next != tail)
			cur = cur->next;
		cout << cur->date << " ";
		tail = cur;
	}
}
int main()
{
	LNode *p = CreatList(4);
	//1、
	//Print_Recursion(p->next);

	//2、
	//LNode *head = Change_Node(p);
	//Print_List(head);

	//3、
	Print_Normal(p);
	
}