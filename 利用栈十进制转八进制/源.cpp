//
//  stack_.cpp
//  Stack
//
//  Created by ljpc on 2018/4/17.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "stack_.h"

// 栈操作实现文件
//////////////////////////////////////////////////////////////


Stack* Stack_Create(int maxlen)
// 创建栈
{
	Stack* stk = (Stack*)malloc(sizeof(Stack));
	stk->data = (T*)malloc(sizeof(T)*maxlen);
	stk->max = maxlen;
	stk->top = -1;
	return stk;
}

void Stack_Free(Stack* stk)
// 释放栈
{
	free(stk->data);
	free(stk);
}

void Stack_MakeEmpty(Stack* stk)
// 置为空栈
{
	stk->top = -1;
}

bool Stack_IsEmpty(Stack* stk)
// 判断栈是否空
{
	return -1 == stk->top;
}

bool Stack_IsFull(Stack* stk)
// 判断栈是否满
{
	return stk->top == stk->max - 1;
}

T Stack_Top(Stack* stk)
// 获取当前栈顶元素
{
	return stk->data[stk->top];
}

T Stack_Push(Stack* stk, T e)
// 将元素e压入栈顶
// 返回栈顶点元素
{
	if (Stack_IsFull(stk)) {
		printf("Stack_IsFull(): stack full error when push element to the stack!\n");
		Stack_Free(stk);
		exit(0);
	}
	else {
		stk->top += 1;
		stk->data[stk->top] = e;
		return Stack_Top(stk);
	}
}

T Stack_Pop(Stack* stk)
// 将栈顶元素出栈
// 返回栈顶元素
{
	if (Stack_IsEmpty(stk)) {
		printf("Stack_IsEmpty(): stack empty error when pop element of the stack top!\n");
		Stack_Free(stk);
		exit(0);
	}
	else {
		T topE = Stack_Top(stk);
		stk->top -= 1;
		return topE;
	}
}

void Stack_Print(Stack* stk)
// 打印栈顶到栈低的元素
{
	if (Stack_IsEmpty(stk)) {
		printf("The stack is empty.\n");
		return;
	}

	//printf("The stack contains: ");
	for (int i = stk->top; i >= 0; i--) {
		printf("%d", stk->data[i]);
	}
	printf("\n");

}


void Decimal_Conversion_Octal(T e)
//  利用stack栈实现整数的十进制转八进制
//  输入参数：十进制整数 e
//  打印e的八进制结果，末尾换行
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	int n = 0;
	n = e / 8 + 1;
	int num = e;
	Stack *stack = NULL;
	stack = Stack_Create(n);
	while (num)
	{
		Stack_Push(stack, num % 8);
		num /= 8;
	}
	Stack_Print(stack);


	/********** End **********/
}
int main()
{
	Decimal_Conversion_Octal(15);
}




