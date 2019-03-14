#include "DuLinkedList.h"

void InitDuLinkedList(DuLinkedList *DL)
{
    assert(DL != NULL);
    *DL = (DuLinkedList)malloc(sizeof(DulNode));
    (*DL)->prior = *DL;
    (*DL)->next = *DL;
}

void CreateFromTail(DuLinkedList DL)
{
    assert(DL != NULL);
    DulNode *s = NULL;
    DulNode *p = DL;

    for (int i = 0; i < LENGTH; i++)
    {
        s = (DulNode *)malloc(sizeof(DulNode));
        s->data = i+1;
        p->next = s;
        s->prior = p;
        s->next = NULL;
        p = s;
    }
    p->next = NULL;
}

void ShowDuLinkedList(DuLinkedList DL)
{
    assert(DL != NULL);

    DulNode *p = DL->next;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}