#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
#define STACK_INIT_SIZE 10
#define STACK_ADD_SIZE 2
struct Stack1//运算符
{
	char *base;
	char *top;
	int stack_size;
};
struct Stack2//数
{
	double *base;
	double *top;
	int stack_size;
};
bool InitStack1(Stack1 &S)
{
	S.base = (char *)malloc(sizeof(char)*STACK_INIT_SIZE);
	if (S.base == NULL)
		exit(-2);
	S.top = S.base;
	S.stack_size = STACK_INIT_SIZE;
	return true;
}
bool InitStack2(Stack2 &S)
{
	S.base = (double *)malloc(sizeof(double)*STACK_INIT_SIZE);
	if (S.base == NULL)
		exit(-2);
	S.top = S.base;
	S.stack_size = STACK_INIT_SIZE;
	return true;
}
bool Push1(Stack1 &S, char e)
{
	if (S.top - S.base >= S.stack_size)
	{
		S.base = (char *)realloc(S.base, sizeof(char)*(STACK_INIT_SIZE + STACK_ADD_SIZE));
		if (S.base == NULL)
			exit(-2);
		S.top = S.base + S.stack_size;
	}
	*(S.top) = e;
	S.top++;
	return true;
}
bool Push2(Stack2 &S, double e)
{
	if (S.top - S.base >= S.stack_size)
	{
		S.base = (double *)realloc(S.base, sizeof(double)*(STACK_INIT_SIZE + STACK_ADD_SIZE));
		if (S.base == NULL)
			exit(-2);
		S.top = S.base + S.stack_size;
	}
	*(S.top) = e;
	S.top++;
	return true;
}
bool Pop1(Stack1 &S, char &e)
{
	if (S.top == S.base)
		return false;
	S.top--;
	e = *(S.top);
	return true;
}
bool Pop2(Stack2 &S, double &e)
{
	if (S.top == S.base)
		return false;
	S.top--;
	e = *(S.top);
	return true;
}
char GetTop1(Stack1 S)
{
	if (S.top == S.base)
		return 0;
	char *p = S.top;
	p--;
	return *p;
}
double GetTop2(Stack2 S)
{
	if (S.top == S.base)
		return 0;
	double *p = S.top;
	p--;
	return *p;
}
bool Is_Operator(char c)
{
	if (c == '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
		return true;
	else
		return false;
}
double operate(double a, char op, double b)
{
	double num;
	switch (op)
	{
	case '+':num = a + b; break;
	case '-':num = a - b; break;
	case '*':num = a * b; break;
	case '/':num = a / b; break;
	}
	return num;
}
char priority(char p1, char p2)
{
	switch (p1)
	{
	case '+':
		if (p2 == '+' || p2 == '-' || p2 == ')' || p2 == '=')
			return '>';
		else
			return '<';
		//break;
	case '-':
		if (p2 == '+' || p2 == '-' || p2 == ')' || p2 == '=')
			return '>';
		else
			return '<';
		//break;
	case '*':
		if (p2 == '(')
			return '<';
		else
			return '>';
		//break;
	case '/':
		if (p2 == '(')
			return '<';
		else
			return '>';
	//	break;
	case '(':
		if (p2 == ')')
			return '=';
		else
			return '<';
		//break;
	case ')':
		return '>';
		//break;
	case '=':
		if (p2 == '=')
			return '=';
		else
			return '<';
	default:
		return 0;
	}
}
double Calc()
{
	Stack1 s1;
	Stack2 s2;
	InitStack1(s1);
	Push1(s1, '=');//结束符
	InitStack2(s2);
	char Express[50];
	char temp[10];
	cin >> Express;
	char *p = Express;
	int i = 0;
	double date;
	char x;
	double a, b;
	while (*p != '=' || GetTop1(s1) != '=')
	{
		if (!Is_Operator(*p))//判断是否为运算符
		{
			temp[i] = *p;
			p++;
			i++;
			if (Is_Operator(*p))//该情况为大于一位数
			{
				temp[i] = '\0';
				date = atof(temp);
				Push2(s2, date);
				i = 0;
			}
		}
		else
		{
			char c = priority(GetTop1(s1), *p);
			if (c == 0)
			{
				cout << "输入错误" << endl;
				exit(2);
			}
			switch (c)
			{
			case '<':
				Push1(s1, *p);
				p++;
				break;
			case '=':
				Pop1(s1, x);
				p++;
				break;
			case '>':
				Pop1(s1, x);
				Pop2(s2, a);
				Pop2(s2, b);
				Push2(s2,operate(a, x, b));
				break;
			}
		}
	}
	return GetTop2(s2);
}
int main()
{
	cout << Calc() << endl;
	return 0;
}
