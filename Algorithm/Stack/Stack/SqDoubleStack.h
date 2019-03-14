//
//  SqDoubleStack.h
//  Stack
//  两栈共享存储空间
//  Created by hanoi_ahoj on 2018/12/27.
//  Copyright © 2018 ahoj. All rights reserved.
//

#ifndef SqDoubleStack_h
#define SqDoubleStack_h

#define MAXSIZE 5

typedef enum
{
    OK = 1,ERROR = 0,
    
    FULL = 1,UNFULL = 0,
    
    EMPTY = 1,UNEMPTY = 0
} STATUS;

typedef int SqStackElemtype;

typedef struct
{
    SqStackElemtype data[MAXSIZE];
    int top1;
    int top2;
} SqDoubleStack;

void InitSqDoubleStack(SqDoubleStack *ds);

STATUS IsFull(const SqDoubleStack *ds);
STATUS IsEmpty(const SqDoubleStack *ds);

// 将元素e押入index(1/2)栈中
STATUS Push(SqDoubleStack *ds, SqStackElemtype e, int index);

STATUS Pop(SqDoubleStack *ds, SqStackElemtype *e, int index);

void TestSqDoubleStack(void );

#endif /* SqDoubleStack_h */
