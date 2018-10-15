//
//  LinkedList.c
//  单链表上的基本运算
//
//  Created by hanoi_ahoj on 2018/10/10.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include "LinkedList.h"

// 初始化单链表
void InitLinkedList(LinkedList *L)
{
    (*L) = (LinkedList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

// 头插法 建立单链表
void CreateFromHead(LinkedList L)
{
    Node *s;
    for (int i=8; i>=0; i-=2)
    {
        s = (LinkedList)malloc(sizeof(Node));
        s->next = NULL;
        s->data = i;
        s->next = L->next;
        L->next = s;
    }
}

// 尾插法 建立单链表
void CreateFromTail(LinkedList L)
{
    // 尾插法 插入新节点
    Node *s;
    Node *p = L;
    for (int i=1; i<10; i+=2)
    {
        s = (LinkedList)malloc(sizeof(Node));
        s->next = NULL;
        s->data = i;
        p->next = s;
        p = p->next;
    }
}

// 按序号查找
Node *Get(LinkedList L, int i)
{
    int count = 1;
    Node *p = L;
    
    if (i < 0)
    {
        return NULL;
    }
    
    while (p != NULL && count <= i)
    {
        count ++;
        p = p->next;
    }
    return p;
}

// 按值查找
Node *Locate(LinkedList L, ElemType key)
{
    Node *p = L;
    while (p != NULL && p->data != key)
    {
        p = p->next;
    }
    return p;
}

// 求单链表长度
int LinkedListLength(LinkedList L)
{
    int len = 0;
    Node *p = L;
    while (p->next != NULL)
    {
        len++;
        p = p->next;
    }
    
    return len;
}

// 插入
void InsertLinkedList(LinkedList L, int i, ElemType e)
{
    Node *s;
    Node *p = L;
    int count = 1;
    s = (LinkedList)malloc(sizeof(Node));
    s->data = e;
    while (p != NULL && count < i)
    {
        count ++;
        p = p->next;
    }
    
    // insert
    s->next = p->next;
    p->next = s;
}

// 删除
void DeleteLinkedList(LinkedList L, int i)
{
    Node *s;
    Node *p = L;
    int count = 1;
    while (p != NULL && count < i)
    {
        count ++;
        p = p->next;
    }
    
    s = p;
    p->next = p->next->next;
    free(s);
}

// 输出单链表的内容
void ShowData(LinkedList L)
{
    Node *p = L->next;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

// 合并两个有序(升序)的单链表
/*LinkedList MergeLinkedList(LinkedList LA, LinkedList LB)
{
    Node *p = LA->next;
    Node *q = LB->next;
    LinkedList LC = LA;
    LC->next = NULL;
    Node *r = LC;
    
    while (p != NULL && q != NULL)
    {
        if (p->data <= q->data)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        {
            r->next = q;
            r = q;
            q = q->next;
        }
    }
    
    if (p != NULL)
    {
        r->next = p;
    }
    else
    {
        r->next = q;
    }
    
    free(q);
    
    return LC;
}*/

LinkedList MergeLinkedList(LinkedList LA, LinkedList LB)
{
    Node *pA = LA->next;
    Node *pB = LB->next;
    LinkedList LC = LA;
    Node *r = LC;
    LC->next = NULL;
    
    while (pA != NULL && pB != NULL)
    {
        if (pA->data <= pB->data)
        {
            r->next = pA;
            r = pA;
            pA = pA->next;
        }
        else
        {
            r->next = pB;
            r = pB;
            pB = pB->next;
        }
    }
    
    if (pA != NULL)
    {
        r->next = pA;
    }
    else
    {
        r->next = pB;
    }
    
    free(LB);
    
    return LC;
}
