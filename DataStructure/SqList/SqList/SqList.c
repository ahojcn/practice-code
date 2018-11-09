//
//  SqList.c
//  SqList
//
//  Created by hanoi_ahoj on 2018/11/9.
//  Copyright © 2018 ahoj. All rights reserved.
//

#include <stdio.h>
#include "SqList.h"

// 初始化，值为 1~MAXSIZE
Status InitSqList(SqList *S)
{
    for(int i=0; i<MAXSIZE; i++)
    {
        S->data[i] = i+1;
    }
    S->length = MAXSIZE;
    
    return OK;
}

// 打印
Status DisplaySqList(SqList *S)
{
    for(int i=0; i<S->length; i++)
    {
        printf("%d ", S->data[i]);
    }
    printf("\n");
    
    return OK;
}

// 查找第i个位置的值，该值通过参数e带回 和 返回该值
Status GetElem(SqList *S, int i, ElemType *e)
{
    if(S->length==0 || i<1 || i>S->length)
    {
        return ERROR;
    }
    else
    {
        *e = S->data[i-1];
        return OK;
    }
}


