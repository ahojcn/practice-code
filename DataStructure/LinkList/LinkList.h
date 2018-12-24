#ifndef LinkList_h
#define LinkList_h

#define LINKLIST_INF 65535

typedef int LinkListElemType;

typedef struct LNode
{
    LinkListElemType data;
    struct LNode *next;
} LinkList, LNode;

/*
 * 无头结点单链表
 */

// 无头结点单链表 初始化
void LinkListInit(LinkList **phead);

void LinkListShow(LinkList **phead);

// 由输入 创建单链表
// 均以 LINKLIST_INF 作为输入结束标志
void LinkListCreateFromTail(LinkList **phead);
void LinkListCreateFromHead(LinkList **phead);

#endif /* LinkList_h */