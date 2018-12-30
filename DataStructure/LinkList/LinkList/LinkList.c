//
//  LinkList.h
//  LinkList
//  无头节点 单链表
//  Created by ahoj on 2018/12/24.
//

#include "LinkList.h"

static LinkList *GetOneLNode(LinkListElemType value)
{
    LinkList *s = (LinkList *)malloc(sizeof(LNode));
    assert(s != NULL);
    s->data = value;
    s->next = NULL;
    return s;
}

int GetLinkListLength(LinkList **pHead)
{
    assert(pHead != NULL);
    
    int len = 0;
    LinkList *p = *pHead;
    while(p != NULL)
    {
        p = p->next;
        len++;
    }
    
    return len;
}

LinkList * GetTailNode(LinkList **pHead)
{
    assert(pHead != NULL);
    
    LinkList *p = *pHead;
    
    while(p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

void InitLinkList(LinkList **pHead)
{
    assert(pHead != NULL);
    
    (*pHead) = NULL;
}

void DestoryLinkList(LinkList **pHead)
{
    assert(pHead != NULL);
    
    LinkList **p = pHead;
    LinkList **tmp = p;
    while((*p) != NULL)
    {
        tmp = p;
        free(*tmp);
        (*p) = (*p)->next;
    }
//    ShowLinkList(pHead);
}

void ShowLinkList(LinkList **pHead)
{
    assert(pHead != NULL);
    
    LinkList *p = *pHead;
    while(p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void InsertFromHead(LinkList **pHead, LinkListElemType value)
{
    assert(pHead != NULL);
    
    LinkList *s = GetOneLNode(value);
    s->next = (*pHead);
    (*pHead) = s;
}

void InsertFromTail(LinkList **pHead, LinkListElemType value)
{
    assert(pHead != NULL);
    
    LinkList *s = GetOneLNode(value);
    
    LinkList *p = *pHead;
    if(p == NULL)    // 处理空链表
    {
        InsertFromHead(pHead, value);
    }
    else    // 非空链表
    {
        p = GetTailNode(&p);
        p->next = s;
    }
}

void DelOneNodeHead(LinkList **pHead)
{
    assert(pHead != NULL);

    LinkList *p = *pHead;
//    printf("Delete : %d\n", p->data);
    *pHead = (*pHead)->next;
    free(p);
}

void DelOneNodeTail(LinkList **pHead)
{
    assert(pHead != NULL);
    
    LinkList *p = *pHead;
    
    while(p->next->next != NULL)
    {
        p = p->next;
    }
//    printf("Delete : %d\n", p->data);
    free(p->next);
    p->next = NULL;
//    printf("--%d--\n", p->data);
}

LinkList * GetNodeFirstValue(LinkList **pHead, LinkListElemType value)
{
    assert(pHead != NULL);
    
    LinkList *p = *pHead;
    while(p->next != NULL && p->data != value)
    {
        p = p->next;
    }
    
    if(p->data == value)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}

LinkList * GetNodeCountPre(LinkList **pHead, int i)
{
    assert(pHead != NULL);
    
    LinkList *p = *pHead;
    while(p->next != NULL && i != 1)
    {
        p = p->next;
        i--;
    }
    if(i == 1)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}

int UpdateFirstData(LinkList **pHead, LinkListElemType old_value, LinkListElemType new_value)
{
    assert(pHead != NULL);
    
    int ret = 0;    // 默认不存在
    LinkList *p = GetNodeFirstValue(pHead, old_value);
    if(p == NULL)
    {
        ret = 0;
    }
    else
    {
        ret = 1;
        p->data = new_value;
    }
    
    return ret;
}

int UpdateAllData(LinkList **pHead, LinkListElemType old_value, LinkListElemType new_value)
{
    assert(pHead != NULL);
    
    int ret = 0;
    while(UpdateFirstData(pHead, old_value, new_value))
    {
        ret++;
    }
    return ret;
}

void InsertInMid(LinkList **pHead, int index, LinkListElemType value)
{
    assert(pHead != NULL);
    int ll_len = GetLinkListLength(pHead);  //链表长度
    assert(index >= 0 && index <= ll_len);
    
    LinkList *p = *pHead;
    if(ll_len == 0 || index == 0)
    {
        InsertFromHead(pHead, value);
    }
    else if(ll_len == index)
    {
        InsertFromTail(pHead, value);
    }
    else
    {
        LinkList *s = GetOneLNode(value);
        // 找到前一个节点
        p = GetNodeCountPre(pHead, index);
        // attach
        s->data = value;
        s->next = p->next;
        p->next = s;
    }
}

void CreateLinkListByKeyBorad(LinkList **pHead)
{
    assert(pHead != NULL);
    
    LinkListElemType input = LinkList_INF;
    while(scanf("%d", &input) && input != LinkList_INF)
    {
        InsertFromTail(pHead, input);
    }
}

void DelOneNodeIndex(LinkList **pHead, int index)
{
    assert(pHead != NULL);
    int ll_len = GetLinkListLength(pHead);
    assert(index >= 0 && index <= ll_len);
    
    if(index == 0)
    {
        DelOneNodeHead(pHead);
    }
    else if(index == ll_len)
    {
        DelOneNodeTail(pHead);
    }
    else
    {
        LinkList *p = GetNodeCountPre(pHead, index);
        LinkList *s = p->next;
        p->next = s->next;
        free(s);
    }
}

LinkList *ReverseLinkList_1(LinkList **head)
{
    if ((*head) == NULL)
    {
        return NULL;
    }
    
    LinkList *ret = NULL;
    LinkList *cur = *head;
    while(cur != NULL)
    {
        // 头删 头插
        LinkList *tmp = cur->next;
        cur->next = ret;
        ret = cur;
        cur = tmp;
    }
    return ret;
}

LinkList *ReverseLinkList_2(LinkList **head)
{
    if ((*head) == NULL)
    {
        return NULL;
    }
    
    LinkList *prev = NULL;
    LinkList *cur = *head;
    while(cur != NULL)
    {
        LinkList *tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    return prev;
}

// TODO: 测试这个函数
LinkList *MerageOrderedLinkList(LinkList **headA, LinkList **headB)
{
    if((*headA) == NULL)
    {
        return *headB;
    }
    if((*headB) == NULL)
    {
        return *headA;
    }
    
    LinkList *curA = *headA;
    LinkList *curB = *headB;
    LinkList *tmpA = curA->next;
    LinkList *tmpB = curB->next;
    while(curA != NULL && curB != NULL)
    {
        if(curA->data <= curB->data)
        {
            curA->next = curB;
            curB->next = tmpA;
            curA = tmpA;
        }
        else
        {
            curB->next = curA;
            curA->next = tmpB;
            curB = tmpB;
        }
    }
    puts("A:");
    ShowLinkList(&curA);
    puts("B:");
    ShowLinkList(&curB);
    
//    if(curA != NULL)
//    {
//        curA
//    }
    return NULL;
}
