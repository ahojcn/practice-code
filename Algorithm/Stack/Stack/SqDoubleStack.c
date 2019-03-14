//
//  SqDoubleStack.c
//  Stack
//  两栈共享存储空间
//  Created by hanoi_ahoj on 2018/12/27.
//  Copyright © 2018 ahoj. All rights reserved.
//

#include "SqDoubleStack.h"
#include <assert.h>
#include <stdio.h>

STATUS IsFull(const SqDoubleStack *ds)
{
    return ds->top1+1 == ds->top2 ? FULL : UNFULL;
}

STATUS IsEmpty(const SqDoubleStack *ds)
{
    return (ds->top1 + ds->top2) == MAXSIZE-2 ? EMPTY : UNEMPTY;
}

void InitSqDoubleStack(SqDoubleStack *ds)
{
    assert(ds != NULL);
    
    ds->top1 = -1;
    ds->top2 = MAXSIZE-1;
}

STATUS Push(SqDoubleStack *ds, SqStackElemtype e, int index)
{
    assert(ds != NULL);
    
    if(IsFull(ds) == FULL)
    {
        return ERROR;
    }
    else
    {
        if(index == 1)
        {
            ds->data[++ds->top1] = e;
        }
        else
        {
            ds->data[--ds->top2] = e;
        }
        return OK;
    }
}

STATUS Pop(SqDoubleStack *ds, SqStackElemtype *e, int index)
{
    assert(ds != NULL);
    
    if(IsEmpty(ds) == EMPTY)
    {
        return ERROR;
    }
    else
    {
        if(index == 1)
        {
            *e = ds->data[ds->top1--];
        }
        else
        {
            *e = ds->data[ds->top2++];
        }
        return OK;
    }
}

void TestSqDoubleStack(void )
{
    SqDoubleStack ds;
    InitSqDoubleStack(&ds);
    
    Push(&ds, 1, 1);
    Push(&ds, 11, 1);
    Push(&ds, 2, 2);
    Push(&ds, 22, 2);
    Push(&ds, 222, 2);
}
