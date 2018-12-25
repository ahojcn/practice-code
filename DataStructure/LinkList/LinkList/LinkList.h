//
//  LinkList.h
//  LinkList
//  无头节点 单链表
//  Created by ahoj on 2018/12/24.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define LinkList_INF

typedef int LinkListElemType;

typedef struct LNode
{
    LinkListElemType data;
    struct LNode *next;
} LinkList, LNode;

// 初始化
void InitLinkList(LinkList **pHead);
// 销毁
void DestoryLinkList(LinkList **pHead);

// 打印
void ShowLinkList(LinkList **pHead);
// 单链表长度
int GetLinkListLength(LinkList **pHead);

/*   增   */
// 尾插
void InsertFromTail(LinkList **pHead, LinkListElemType value);
// 头插
void InsertFromHead(LinkList **pHead, LinkListElemType value);
// 中间插
// 新建节点插入从前往后数第index个节点，从0开始数
void InsertInMid(LinkList **pHead, int index, LinkListElemType value);

/*   删   */
// 头删
void DelFromHead(LinkList **pHead);
// 尾删
void DelFromTail(LinkList **pHead);

/*   查   */
// 在链表中查找data域等于value的节点
// 找到返回指向这个节点的指针，否则返回NULL
LinkList * SearchValue(LinkList **pHead, LinkListElemType value);
// 在链表中查找 第i个 节点（0开始计数）
// 找到返回这个节点，否则额返回NUll
LinkList * SearchCount(LinkList **pHead, int i);

/*   改   */
// 修改链表中第一个值为old_value的节点data为new_value
// 如果存在则修改并返回1，不存在则不修改返回0
int UpdateFirstData(LinkList **pHead, LinkListElemType old_value, LinkListElemType new_value);
// 修改链表中所有值为old_value的节点data为new_value
// 如果没有old_value返回0，有则返回修改的数量
int UpdateAllData(LinkList **pHead, LinkListElemType old_value, LinkListElemType new_value);

#endif /* LinkList_h */



