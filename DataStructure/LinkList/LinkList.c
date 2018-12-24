#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void LinkListInit(LinkList **phead)
{
    assert(phead != NULL);
    (*phead) = NULL;
}

void LinkListShow(LinkList **phead)
{
    assert(phead != NULL);

    LinkList *p = *phead;

    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void LinkListCreateFromTail(LinkList **phead)
{
    assert(phead != NULL);

    
}