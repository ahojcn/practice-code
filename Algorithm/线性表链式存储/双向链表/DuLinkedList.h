#ifndef DuLinkedList_h
#define DuLinkedList_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


#define LENGTH 10

typedef int ElemType;

typedef struct DulNode
{
    ElemType data;
    struct DulNode *prior;
    struct DulNode *next;
} DulNode, *DuLinkedList;

void InitDuLinkedList(DuLinkedList *DL);
void CreateFromTail(DuLinkedList DL);
void ShowDuLinkedList(DuLinkedList DL);

#endif /* DuLinkedList_h */