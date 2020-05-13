#pragma once
//
//  stack_.h
//  Stack
//
//  Created by ljpc on 2018/4/17.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#ifndef stack__h
#define stack__h

#include <stdio.h>
#include <stdlib.h>

typedef int T; // 数据元素的数据类型

struct Stack {
	T* data;   // 数据元素存储空间的开始地址
	int top;   // 栈顶的位置
	int max;   // 栈的最大长度
};


Stack* Stack_Create(int maxlen);
// 创建栈

void Stack_Free(Stack* stk);
// 释放栈

void Stack_MakeEmpty(Stack* stk);
// 置为空栈

bool Stack_IsEmpty(Stack* stk);
// 判断栈是否空

bool Stack_IsFull(Stack* stk);
// 判断栈是否满

T Stack_Top(Stack* stk);
// 返回栈顶元素

T Stack_Push(Stack* stk, T e);
// 将元素e压入栈顶
// 返回栈顶点元素

T Stack_Pop(Stack* stk);
// 将栈顶元素出栈
// 返回栈顶元素

void Stack_Print(Stack* stk);
// 打印栈顶到栈低的元素

void Decimal_Conversion_Octal(T e);
//  利用stack栈实现整数的十进制转八进制
//  输入参数：十进制整数 e
//  打印结果，末尾换行

#endif /* stack__h */
