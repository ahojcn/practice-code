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
// 清空链表，只留一个头节点
void ClearDLinkList(DListNode **pphead);
// 销毁整个链表
void DestoryDLinkList(DListNode **pphead);

// 打印
void ShowDLinkList(const DListNode *phead);
// 求链表长度
// 不算头节点
int GetDLinkListLength(const DListNode *phead);

/*   增   */
// 头插
void InsertFromHead(DListNode *phead, DLinkListElemType value);
// 尾插
void InsertFromTail(DListNode *phead, DLinkListElemType value);
// 任意节点前插入一个新节点
// 参数：指向这个节点的指针，插入新节点的val = value
void InsertBeforeOneNode(DListNode *cur, DLinkListElemType value);

/*   删   */
// 头删
void DelFromHead(DListNode *phead);
// 尾删
void DelFromTail(DListNode *phead);
// 删除pos指针指向的节点
// 不能删除头节点
void DelPosNode(DListNode *pos);

/*   查   */
DListNode *SearchValue(const DListNode *phead, DLinkListElemType value);
DListNode *SearchIndex(const DListNode *phead, int index);

/*   改   */
void UpdateAValue(DListNode *phead, DLinkListElemType old_val, DLinkListElemType new_val);
void UpdataAllValue(DListNode *phead, DLinkListElemType old_val, DLinkListElemType new_val);

#endif /* DLinkList_h */
