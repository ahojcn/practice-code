//
//  Seq.h
//  栈：回文判断
//
//  Created by hanoi_ahoj on 2018/10/18.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#ifndef Seq_h
#define Seq_h

#include <stdio.h>

#define MAXSIZE 10
#define FALSE 0
#define TRUE 1

typedef char ElemType;

typedef struct Node
{
    ElemType elem[MAXSIZE];
    int top;
}SeqStack;

void Init(SeqStack *S);
int Push(SeqStack *S, ElemType e);
int Pop(SeqStack *S, ElemType *e);
int GetTop(SeqStack *S, ElemType *e);

#endif /* Seq_h */
