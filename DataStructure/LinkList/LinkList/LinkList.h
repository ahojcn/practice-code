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

// 打印
void ShowLinkList(LinkList **pHead);

/*   增   */
// 尾插
void CreateFromTail(LinkList **pHead, LinkListElemType value);
// 头插
void CreateFromHead(LinkList **pHead, LinkListElemType value);

/*   删   */

#endif /* LinkList_h */
