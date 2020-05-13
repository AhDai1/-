#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct TNode
{
	char data;
	struct TNode *lchild;
	struct TNode *rchild;
};
typedef struct TNode TNode;
/*
	递归创建二叉树
*/
TNode* create_bt()
{
	char ch;
	scanf("%c", &ch);
	getchar();
	TNode *bt;
	if (ch == '0')
	{
		bt = NULL;
	}
	else
	{
		bt = (TNode *)malloc(sizeof(TNode));
		bt->data = ch;
		printf("请输入%c左孩子数据:",bt->data);
		bt->lchild = create_bt();
		printf("请输入%c右孩子数据:",bt->data);
		bt->rchild = create_bt();
	}
	return bt;
}
/*
	广义表法输出二叉树
*/
void print_bt(TNode *bt)
{
	if (bt != NULL)
	{
		printf("%c", bt->data);
		if (bt->lchild != NULL)
		{
			printf("(");
			print_bt(bt->lchild);
			if (bt->rchild != NULL)
			{
				printf(",");
				print_bt(bt->rchild);
			}
			printf(")");
		}
		else if (bt->rchild != NULL)
		{
			printf("(");
			print_bt(bt->rchild);
			if (bt->lchild != NULL)
			{
				printf(",");
				print_bt(bt->lchild);
			}
			printf(")");
		}
	}
}
/*
	统计叶子节点
*/
int count_leaf;
void num_leaf(TNode *bt)
{
	if (bt != NULL)
	{
		if (bt->lchild == NULL && bt->rchild == NULL)
			count_leaf++;
		num_leaf(bt->lchild);
		num_leaf(bt->rchild);
	}
}
/*
	统计节点
*/
int count_bt;
void num_bt(TNode *bt)
{
	if (bt != NULL)
	{
		count_bt++;
		num_bt(bt->lchild);
		num_bt(bt->rchild);
	}
}
/*
	求深度
*/
int dep_bt(TNode *bt)
{
	int ldep, rdep;
	if (bt == NULL)
		return 0;
	else
	{
		ldep = dep_bt(bt->lchild);
		rdep = dep_bt(bt->rchild);
	}
	if (ldep > rdep)
	{
		return ldep + 1;
	}
	else
		return rdep + 1;
}
int main()
{
	TNode *bt = NULL;
	bt = create_bt();
	print_bt(bt);
	num_leaf(bt);
	printf("叶子节点为:%d个\n", count_leaf);
	num_bt(bt);
	printf("节点为:%d个\n", count_bt);
	printf("深度为:%d", dep_bt(bt));
	return 0;
}
