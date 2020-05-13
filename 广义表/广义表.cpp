#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct lnode
{
	int tag;//类型
	union 
	{
		char data;
		struct lnode *sublist;
	}val;
	struct lnode *link;//下一个元素
};
typedef struct lnode GLnode;
/*
	括号表示法的广义表链式储存结构（递归）
*/
GLnode* create_g(const char **s)//行地址，不是首元素
{
	GLnode *p = NULL;
	char ch = *((*s)++);//行地址取*为首元素首地址再++取*则为元素的值
	//char ch = *s++;//err
	if (ch != '\0')
	{
		p = (GLnode *)malloc(sizeof(GLnode));
		if (ch == '(')
		{
			p->tag = 1;
			p->val.sublist = create_g(s);
		}
		else if (ch == ')')
		{
			p = NULL;
		}
		else if (ch == '#')
		{
			p->val.sublist = NULL;
		}
		else
		{
			p->tag = 0;
			p->val.data = ch;
		}
	}
	else
	{
		p = NULL;
	}
	ch = *((*s)++);
	//ch = *s++;
	if (p != NULL)
	{
		if (ch == ',')
		{
 			p->link = create_g(s);
		}
		else
		{
			p->link = NULL;
		}
	}
	return p;
}
/*
	输出广义表
*/
void print_g(GLnode *p)
{
	if (p != NULL)
	{
		if (p->tag == 0)
		{
			printf("%c", p->val.data);
		}
		else
		{
			printf("(");
			if (p->val.sublist == NULL)
			{
				printf("#");
			}
			else
			{
				print_g(p->val.sublist);
			}
			printf(")");
		}
		if (p->link != NULL)
		{
			printf(",");
			print_g(p->link);
		}
	}
}
/*
	求广义表长度
*/
int g_length(GLnode *p)
{
	int n = 0;
	p = p->val.sublist;
	while (p != NULL)
	{
		n++;
		p = p->link;
	}
	return n;
}
/*
	求广义表深度
*/
int g_dplength(GLnode *p)
{
	int max = 0;
	int dep;
	if (p->tag == 0)
	{
		return 0;
	}
	p = p->val.sublist;
	if (p == NULL)
	{
		return 1;
	}
	while (p != NULL)
	{
		if (p->tag == 1)
		{
			dep = g_dplength(p);
			if (dep > max)
			{
				max = dep;
			}
		}
		p = p->link;
	}
	return max + 1;
}
/*
	求广义表最大元素
*/
char g_max(GLnode *p)
{
	char max1, max2;
	if (p != NULL)
	{
		if (p->tag == 0)
		{
			max1 = g_max(p->link);
			if (p->val.data > max1)
				return p->val.data;
			else
				return max1;
		}
		else
		{
			max1 = g_max(p->val.sublist);
			max2 = g_max(p->link);
			if (max1 > max2)
				return max1;
			else
				return max2;
		}
	}
	return 0;
}
/*
	销毁广义表
*/
void g_free(GLnode **p)
{
	GLnode *p1 = NULL;
	GLnode *p2 = NULL;
	p1 = (*p)->val.sublist;
	while (p1 != NULL)
	{
		if (p1->tag == 0)
		{
			p2 = p1->link;
			free(p1);
			p1 = p2;
		}
		else
		{
			p2 = p1->link;
			g_free(&p1);
			p1 = p2;
		}
	}
	free(p);
}
int main()
{
	GLnode *p = NULL;
	const char *str = "(b,(b,a,(#),d),((a,b),c,((#))))";
	p = create_g(&str);//传过去的是行地址
	//p = create_g(str);
	print_g(p);
	printf("\n深度：%d\n", g_dplength(p));
	printf("长度：%d\n", g_length(p));
	printf("最大元素：%c", g_max(p));
	return 0;
}
