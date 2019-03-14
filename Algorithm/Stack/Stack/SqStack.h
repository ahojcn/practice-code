//
//  SqStack.h
//  Stack
//  顺序栈
//  Created by hanoi_ahoj on 2018/12/27.
//  Copyright © 2018 ahoj. All rights reserved.
//

#ifndef SqStack_h
#define SqStack_h

#include <stdio.h>

#define MAXSIZE 5

typedef enum
{
    OK = 1,
    ERROR = 0,
    
    FULL = 1,
    UNFULL = 0,
    
    EMPTY = 1,
    UNEMPTY = 0
} STATUS;

typedef int SqStackElemtype;

typedef struct
{
    SqStackElemtype data[MAXSIZE];
    int top;
} SqStack;

void InitSqStack(SqStack *s);

// 判断栈是否满
STATUS IsFull(const SqStack *s);

// 判断栈是否空
STATUS IsEmpty(const SqStack *s);

// 压栈
STATUS Push(SqStack *s, SqStackElemtype e);

// 弹栈
STATUS Pop(SqStack *s, SqStackElemtype *e);

void SqStackTest(void);

#endif /* SqStack_h */
