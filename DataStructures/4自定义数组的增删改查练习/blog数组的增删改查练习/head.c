//
//  head.c
//  blog数组的增删改查练习
//
//  Created by hanoi_ahoj on 2018/10/3.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include <stdio.h>
#include "head.h"

// 初始化
void InitSeqList(SeqList *L)
{
    L->last = 5;
    for (int i = 0; i < L->last; i++)
    {
        L->data[i] = i+1;
    }
}

// 输出所有数据
void ShowAllSeqListData(SeqList *L)
{
    for (int i = 0; i < L->last; i++)
    {
        printf("%d,",L->data[i]);
    }
    printf("\n");
}

// 末尾增加一个数据
void AddOneData(SeqList *L,ElemType e)
{
    L->data[L->last] = e;
    L->last ++;
}

// 插入一个数据
void InsertOneData(SeqList *L,int sign,ElemType e)
{
    if (sign > MAXSIZE)
    {
        printf("插入，越界\n");
    }
    else if(sign > L->last)
    {
        printf("插入位置不合法\n");
    }
    else if(sign == L->last)
    {
        AddOneData(L, e);
    }
    else
    {
        // sign～(L->last-1)向后移动一个单位
        for (int i = L->last; i >= sign-1; i--)
        {
            L->data[i+1] = L->data[i];
        }
        // 插入e
        L->data[sign-1] = e;
        L->last++;
    }
}

// 根据位置删除一个数据
void DelOneData(SeqList *L,int sign)
{
    if (sign<1 || sign>MAXSIZE)
    {
        printf("删除，越界\n");
    }
    else if(sign > L->last)
    {
        printf("删除位置不合法\n");
    }
    else
    {
        for (int i = sign-1; i < L->last; i++)
        {
            L->data[i] = L->data[i+1];
        }
        L->last--;
    }
}

// 根据位置修改数据
void ChangeOneData(SeqList *L,int sign,ElemType e)
{
    L->data[sign-1] = e;
}

// 根据内容修改数据
void ChangeData(SeqList *L,ElemType a,ElemType e)
{
    for (int i=0; i<L->last; i++)
    {
        if(a == L->data[i])
        {
            L->data[i] = e;
        }
    }
}

// 根据位置查找，返回内容
ElemType FileData1(SeqList *L,int sign)
{
    return L->data[sign-1];
}

// 根据内容查找，返回编号
int FindData2(SeqList *L,ElemType e)
{
    for (int i=0; i<L->last; i++)
    {
        if (e == L->data[i])
        {
            return i+1;
        }
    }
    return -1;
}
