//
// Created by hanoi_ahoj on 2018/12/30.
//

#ifndef CLASSDESIGN_STACK_H
#define CLASSDESIGN_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAXLENGTH 100

typedef int StackElemType;

typedef struct StackNode {
    StackElemType s_data[MAXLENGTH];
    int s_top;    // 栈顶
} Stack;

// 初始化一个栈
void StackInit(Stack *ps);
// 压栈
void StackPush(Stack *ps, const StackElemType e);
// 弹栈
void StackPop(Stack *ps);
// 返回栈顶元素
StackElemType StackGetTop(const Stack *ps);
// 栈空
bool StackEmpty(const Stack *ps);
// 栈满
bool StackFull(const Stack *ps);

#endif //CLASSDESIGN_STACK_H
