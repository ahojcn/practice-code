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
    DListNode *cur = phead->next;   // phead指向的是头节点，不打印
    
    printf("headnode -> ");
    while(cur != phead)
    {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("headnode\n");
}

void InitDLinkList(DListNode **pphead)
{
    assert(pphead != NULL);

    (*pphead) = DListBuyNode(0);
    (*pphead)->prev = *pphead;
    (*pphead)->next = *pphead;
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

