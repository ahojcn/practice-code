//
//  DLinkList.c
//  DLinkList
//  带头 双向 循环链表
//  Created by hanoi_ahoj on 2018/12/27.
//  Copyright © 2018 ahoj. All rights reserved.
//

#include "DLinkList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

static DListNode *DListBuyNode(const DLinkListElemType value)
{
    DListNode *new_node = (DListNode *)malloc(sizeof(DListNode));
    assert(new_node != NULL);
    new_node->val = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void ShowDLinkList(const DListNode *phead)
{
    assert(phead != NULL);
    DListNode *cur = phead->next;   // phead指向的是头节点，不打印
    
    printf("headnode <=> ");
    while(cur != phead)
    {
        printf("%d <=> ", cur->val);
        cur = cur->next;
    }
    printf("headnode\n");
}

int GetDLinkListLength(const DListNode *phead)
{
    assert(phead != NULL);
    
    DListNode *cur = phead->next;
    int ret = 0;
    while(cur != phead)
    {
        cur = cur->next;
        ret++;
    }
    return ret;
}

void InitDLinkList(DListNode **pphead)
{
    assert(pphead != NULL);

    (*pphead) = DListBuyNode(0);
    (*pphead)->prev = *pphead;
    (*pphead)->next = *pphead;
}

void ClearDLinkList(DListNode **pphead)
{
    assert(pphead != NULL);
    DListNode *cur = (*pphead)->next;
    DListNode *tmp = cur;
    while(cur != (*pphead))
    {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    (*pphead)->prev = *pphead;
    (*pphead)->next = *pphead;
}

void DestoryDLinkList(DListNode **pphead)
{
    assert(pphead != NULL);
    ClearDLinkList(pphead);
    free(*pphead);
    (*pphead) = NULL;
    pphead = NULL;
}

void InsertFromHead(DListNode *phead, DLinkListElemType value)
{
    assert(phead != NULL);
//    DListNode *new_node = DListBuyNode(value);
//
//    new_node->prev = phead;
//    new_node->next = phead->next;
//    phead->next->prev = new_node;
//    phead->next = new_node;
    // 在phead->next前插入一个节点
    InsertBeforeOneNode(phead->next, value);
}

void InsertFromTail(DListNode *phead, DLinkListElemType value)
{
    assert(phead != NULL);
//    DListNode *new_node = DListBuyNode(value);
//    new_node->next = phead;
//    new_node->prev = phead->prev;
//    phead->prev->next = new_node;
//    phead->prev = new_node;
    // 也就是在phead前插入new_node
    InsertBeforeOneNode(phead, value);
}

void InsertBeforeOneNode(DListNode *cur, DLinkListElemType value)
{
    assert(cur != NULL);
    
    DListNode *new_node = DListBuyNode(value);
    new_node->next = cur;
    new_node->prev = cur->prev;
    cur->prev->next = new_node;
    cur->prev = new_node;
}

void DelFromHead(DListNode *phead)
{
    assert(phead != NULL);
    DelPosNode(phead->next);
}

void DelFromTail(DListNode *phead)
{
    assert(phead != NULL);
    DelPosNode(phead->prev);
}

void DelPosNode(DListNode *pos)
{
    assert(pos != NULL);
    
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    
    free(pos);
    pos = NULL;
}

DListNode *SearchValue(const DListNode *phead, DLinkListElemType value)
{
    assert(phead != NULL);
    
    DListNode *cur = phead->next;
    while(cur != phead)
    {
        if(cur->val == value)
        {
            return cur;
        }
        cur = cur->next;
    }
    
    return NULL;
}

DListNode *SearchIndex(const DListNode *phead, int index)
{
    assert(phead != NULL);
    int dl_len = GetDLinkListLength(phead);
    assert(index >= 1 && index <=dl_len);
    
    DListNode *cur = phead->next;
    while(dl_len != 1)
    {
        cur = cur->next;
    }
    
    return cur;
}
