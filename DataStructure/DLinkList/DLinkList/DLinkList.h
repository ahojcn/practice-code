//
//  DLinkList.h
//  DLinkList
//  带头 双向 循环链表
//  Created by hanoi_ahoj on 2018/12/27.
//  Copyright © 2018 ahoj. All rights reserved.
//

#ifndef DLinkList_h
#define DLinkList_h

typedef int DLinkListElemType;

typedef struct DListNode
{
    DLinkListElemType val;
    struct DListNode *next;
    struct DListNode *prev;
} DListNode;

// 初始化
void InitDLinkList(DListNode **pphead);

// 打印
void ShowDLinkList(const DListNode *phead);

/*   增   */
// 头插
void InsertFromHead(DListNode *phead, DLinkListElemType value);
// 尾插
void InsertFromTail(DListNode *phead, DLinkListElemType value);
// 任意节点前插入一个新节点
// 参数：指向这个节点的指针，插入新节点的val = value
void InsertBeforeOneNode(DListNode *cur, DLinkListElemType value);

#endif /* DLinkList_h */
