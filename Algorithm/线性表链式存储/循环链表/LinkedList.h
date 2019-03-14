
#if !defined(_LINKEDLIST_H_)
#define _LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ElemType int
#define DEFAULTSIZE 5

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkedList;

void InitCLinkedList(LinkedList *CL);
void CreateCLinkedList(LinkedList CL);  // create from tail
void ShowCLinkedList(LinkedList CL);
LinkedList MergeLinkedList(LinkedList LA, LinkedList LB);


#endif // _LINKEDLIST_H_