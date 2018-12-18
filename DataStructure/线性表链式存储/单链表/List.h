
#ifndef List_h
#define List_h

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define TEST_SIZE 10

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

void InitList(LinkList *L);
void ShowList(LinkList L);
void CreateFromHead(LinkList L);
void CreateFromTail(LinkList L);
LinkList GetNode(LinkList L, int i);
LinkList Locate(LinkList L, ElemType e);
int ListLength(LinkList L);
void InsertList(LinkList L, int i, ElemType e);
void DeleteList(LinkList L, int i);
void DestoryList(LinkList *L);
LinkList MerageList(LinkList L1, LinkList L2);

#endif /* List_h */
