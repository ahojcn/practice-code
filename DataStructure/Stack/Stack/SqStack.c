//
//  SqStack.c
//  Stack
//  顺序栈
//  Created by hanoi_ahoj on 2018/12/27.
//  Copyright © 2018 ahoj. All rights reserved.
//

#include "SqStack.h"
#include <assert.h>

void InitSqStack(SqStack *s)
{
    assert(s != NULL);
    
    s->top = -1;
}

STATUS IsFull(const SqStack *s)
{
    return s->top == MAXSIZE-1 ? FULL : UNFULL;
}

STATUS IsEmpty(const SqStack *s)
{
    return s->top == -1 ? EMPTY : UNEMPTY;
}

STATUS Push(SqStack *s, SqStackElemtype e)
{
    assert(s != NULL);
    
    if(IsFull(s) == FULL)
    {
        printf("FULL SqStack\n");
        return ERROR;
    }
    else
    {
        s->top++;
        s->data[s->top] = e;
        return OK;
    }
}

STATUS Pop(SqStack *s, SqStackElemtype *e)
{
    assert(s != NULL);
    
    if(IsEmpty(s) == EMPTY)
    {
        printf("EMPYT SqStack\n");
        return ERROR;
    }
    else
    {
        *e = s->data[s->top];
        s->top--;
        return OK;
    }
}

static void ShowSqStack(const SqStack *s)
{
    assert(s != NULL);
    
    if(IsEmpty(s) == EMPTY)
    {
        printf("EMPYT SqStack\n");
    }
    else
    {
        for(int i=s->top; i>-1; i--)
        {
            printf("%d\n", s->data[i]);
        }
        printf("s\n");
    }
}

void SqStackTest(void)
{
    SqStack s;
    InitSqStack(&s);
    ShowSqStack(&s);
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 4);
    Push(&s, 5);
    ShowSqStack(&s);
    
    SqStackElemtype e;
    Pop(&s, &e);
    printf("e = %d\n", e);
    ShowSqStack(&s);
    Pop(&s, &e);
    Pop(&s, &e);
    Pop(&s, &e);
    Pop(&s, &e);
}
