//
//  LinkList.c
//  LinkList
//
//  Created by hanoi_ahoj on 2018/12/24.
//  Copyright © 2018 ahoj. All rights reserved.
//

#include "LinkList.h"

void InitLinkList(LinkList **pHead)
{
    assert(pHead != NULL);
    
    (*pHead) = NULL;
}

void ShowLinkList(LinkList **pHead)
{
    assert(pHead != NULL);
    
    while((*pHead) != NULL)
    {
        printf("%d -> ", (*pHead)->data);
        (*pHead) = (*pHead)->next;
    }
    printf("NULL\n");
}

void CreateFromHead(LinkList **pHead, LinkListElemType value)
{
    assert(pHead != NULL);
    
    LinkList *s = (LinkList *)malloc(sizeof(LNode));
    assert(s != NULL);
    s->data = value;
    s->next = (*pHead);
    (*pHead) = s;
}

void CreateFromTail(LinkList **pHead, LinkListElemType value)
{
    assert(pHead != NULL);
    
    LinkList *s = (LinkList *)malloc(sizeof(LNode));
    assert(s != NULL);
    s->data = value;
    s->next = NULL;
    
    LinkList **p = pHead;
    if((*p) == NULL)    // 处理空链表
    {
        (*p) = s;
    }
    else    // 非空链表
    {
        while((*p)->next != NULL)
        {
            (*p) = (*p)->next;
        }
        
        (*p)->next = s;
    }
}
