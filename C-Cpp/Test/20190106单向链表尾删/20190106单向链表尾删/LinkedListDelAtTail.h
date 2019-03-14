//
//  LinkedListDelAtTail.h
//  20190106单向链表尾删
//
//  Created by hanoi_ahoj on 2019/1/6.
//  Copyright © 2019 ahoj. All rights reserved.
//

#ifndef LinkedListDelAtTail_h
#define LinkedListDelAtTail_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LinkedListElemType;

typedef struct LinkedListNode
{
    LinkedListElemType val;
    struct LinkedListNode *next;
} LinkedListNode;

// 初始化一个带头单链表
LinkedListNode* InitLinkedList(void )
{
    LinkedListNode *phead = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    assert(phead != NULL);
    phead->next = NULL;
    phead->val = 0;
    return phead;
}

// 头插一个val为e的节点
void InsertNodeAtHead(LinkedListNode *phead, LinkedListElemType e)
{
    assert(phead != NULL);
    LinkedListNode *new_node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    new_node->val = e;
    new_node->next = phead->next;
    phead->next = new_node;
}

// 打印单链表
void PrintLinkedList(const LinkedListNode *phead)
{
    assert(phead != NULL);
    const LinkedListNode *p = phead->next;
    while (p != NULL)
    {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
}

// 单链表的尾删
void DealNodeAtTail(LinkedListNode *phead)
{
    assert(phead != NULL);
    LinkedListNode *p = phead->next;
    while(p->next->next != NULL)
    {
        p = p->next;
    }
    LinkedListNode *tmp = p->next;
    p->next = NULL;
    free(tmp);
}

void TestForDelAtTail(void )
{
    LinkedListNode *phead = InitLinkedList();
    PrintLinkedList(phead);
    InsertNodeAtHead(phead, 3);
    InsertNodeAtHead(phead, 2);
    InsertNodeAtHead(phead, 1);
    DealNodeAtTail(phead);
    PrintLinkedList(phead);
}

// 链表的第一道题，删除单链表中所有值为val的元素
void RemoveAll(LinkedListNode *phead, LinkedListElemType val)
{
    if(phead == NULL)
    {
        return;
    }
    LinkedListNode *pre = phead;
    LinkedListNode *cur = phead->next;
    LinkedListNode *tmp = NULL;
    while (cur != NULL)
    {
        if (cur->val == val)
        {
            tmp = cur;
            cur = cur->next;
            pre->next = cur;
            free(tmp);
            tmp = NULL;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
}

void TestRemoveAll(void )
{
    LinkedListNode *phead = InitLinkedList();
    InsertNodeAtHead(phead, 1);
    PrintLinkedList(phead);
    RemoveAll(phead, 1);
    PrintLinkedList(phead);
}

#endif /* LinkedListDelAtTail_h */
