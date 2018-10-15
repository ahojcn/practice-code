//
//  main.c
//  3约瑟夫环
//
//  Created by hanoi_ahoj on 2018/9/28.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct Node
{
    ElemType number;
    ElemType password;
    struct Node* next;
}Node, *LinkedList;

void InitLinkedList(LinkedList * L)
{
    *L = (LinkedList)malloc(sizeof(Node));
    (*L)->next = *L;
}

void ShowLinkedListData(LinkedList *L)
{
    Node *p = (*L)->next;
    while (p != *L)
    {
        printf("%d ",p->number);
        printf("%d ",p->password);
        printf("\n");
        p = p->next;
    }
}

void CreateJoeph(LinkedList *L,int len, int m[])
{
    Node *rear, *s;
    rear = *L;
    for (int i=0; i<len; i++)
    {
        s=(Node *)malloc(sizeof(Node));
        s->number = i+1;
        s->password = m[i];
        rear->next = s;
        rear = s;
    }
    rear->next = (*L)->next;
}

void GAME(LinkedList *L, int len, int begain)
{
    Node *p;
    Node *q;
    p = (*L)->next;
    for (int i=1; i<=len; i++)
    {
        for (int i=1; i<begain; i++)
        {
            p = p->next;
        }
        begain = p->password;
        printf("%d ",p->number);
        p->number = p->next->number;
        p->password = p->next->password;
        q = p->next;
        p->next = p->next->next;
        free(q);
    }
}

int main(int argc, const char * argv[])
{
    LinkedList L;
    InitLinkedList(&L);
    
    int begain = 20;
    int len = 7;
    int pwd[7] = {3,1,7,2,4,8,4};
    CreateJoeph(&L, len, pwd);
    //ShowLinkedListData(&L);
    GAME(&L, len, begain);
    
    
    
    return 0;
}
