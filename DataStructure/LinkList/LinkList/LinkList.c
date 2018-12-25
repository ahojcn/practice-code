//
//  LinkList.c
//  LinkList
//
//  Created by hanoi_ahoj on 2018/12/24.
//  Copyright © 2018 ahoj. All rights reserved.
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
        p = s;
    }
    else    // 非空链表
    {
        while(p->next != NULL)
        {
            p = p->next;
        }
        
        p->next = s;
    }
}

void DelFromHead(LinkList **pHead)
{
    assert(pHead != NULL);

    LinkList *p = *pHead;
//    printf("Delete : %d\n", p->data);
    *pHead = (*pHead)->next;
    free(p);
}

void DelFromTail(LinkList **pHead)
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

LinkList * SearchValue(LinkList **pHead, LinkListElemType value)
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

LinkList * SearchCount(LinkList **pHead, int i)
{
    assert(pHead != NULL);
    
    LinkList *p = *pHead;
    while(p->next != NULL && i != 0)
    {
        p = p->next;
        i--;
    }
    
    if(i == 0)
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
    LinkList *p = *pHead;
    while(p != NULL && p->data != old_value)
    {
        p = p->next;
    }
    if(p == NULL)
    {
        ret = 0;
    }
    else
    {
        p->data = new_value;
        ret = 1;
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


