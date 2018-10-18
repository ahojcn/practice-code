//
//  Seq.c
//  栈：回文判断
//
//  Created by hanoi_ahoj on 2018/10/18.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include "Seq.h"

void Init(SeqStack *S)
{
    S->top = -1;
}

int Push(SeqStack *S, ElemType e)
{
    if (S->top == MAXSIZE-1)
    {
        return FALSE;
    }
    else
    {
        S->top++;
        S->elem[S->top] = e;
        return TRUE;
    }
}

int Pop(SeqStack *S, ElemType *e)
{
    if (S->top == -1)
    {
        return FALSE;
    }
    else
    {
        *e = S->elem[S->top];
        S->top--;
        return TRUE;
    }
}

int GetTop(SeqStack *S, ElemType *e)
{
    if (S->top == -1)
    {
        return FALSE;
    }
    else
    {
        *e = S->elem[S->top];
        return TRUE;
    }
}
