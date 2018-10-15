//
//  main.c
//  2循环单链表
//
//  Created by hanoi_ahoj on 2018/9/28.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define MAXSIZE 100

typedef struct Node
{
    ElemType data;
    struct Node * next;
}Node, *LinkedList;

void InitLinkedList(LinkedList * CL)
{
    *CL = (LinkedList)malloc(sizeof(Node));
    (*CL)->next = *CL;
}

void CreateLinkedList(LinkedList CL)
{
    Node *rear, *s;
    rear = CL;
    char ch;
    while ((ch=getchar())!='$')
    {
        s=(Node *)malloc(sizeof(Node));
        s->data = ch;
        rear->next = s;
        rear = s;
    }
    rear->next = CL;
}

void ShowLinkedListData(LinkedList *L)
{
    Node *p = (*L)->next;
    while (p != *L)
    {
        printf("%c ",p->data);
        p = p->next;
    }
    printf("\n");
}

int FindData(LinkedList *L, char e)
{
    int i = 1;
    Node *p = (*L)->next;
    
    while (p != *L)
    {
        if (e == p->data)
        {
            return i;
        }
        else
        {
            p = p->next;
            i++;
        }
    }
    
    return i;
}

int main(int argc, const char * argv[])
{
    LinkedList L;
    InitLinkedList(&L);
    
    CreateLinkedList(L);
    ShowLinkedListData(&L);
    
    printf("%d\n",FindData(&L, 'd'));
    
    return 0;
}
