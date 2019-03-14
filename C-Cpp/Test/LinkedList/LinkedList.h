//
// Created by hanoi_ahoj on 2018/12/28.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

typedef int SLinkedListElemType;

typedef struct SListNode
{
    SLinkedListElemType val;
    struct SListNode *next;
} SLinkedList;

/*   无头单链表   */
// 初始化  传入第一个节点的指针的地址
void SLinkListInit (SLinkedList **pphead);
// 返回链表长度
int GetSLinkListLnegth (const SLinkedList *phead);
// 打印单链表
void ShowSLinkList(const SLinkedList *phead);
// 头插
void InsertSLinkListFromHead(SLinkedList **pphead, const SLinkedListElemType val);
// 尾插
void InsertSLinkListFromTail(SLinkedList **pphead, const SLinkedListElemType val);
// 头删
void DeleteSLinkListFromHead(SLinkedList **pphead);
// 尾删
void DeleteSLinklistFromTail(SLinkedList **pphead);
// 查找值为e的第一个节点
SLinkedList *SearchSLinkListVal(const SLinkedList **pphead, const SLinkedListElemType e);

#endif //LINKEDLIST_LINKEDLIST_H
