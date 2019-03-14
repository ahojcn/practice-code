#include "LinkedList.h"

void InitCLinkedList(LinkedList *CL)
{
    assert(CL != NULL);

    *CL = (LinkedList)malloc(sizeof(Node));
    (*CL)->next = *CL;
}

void CreateCLinkedList(LinkedList CL)
{
    assert(CL != NULL);

    Node *s = NULL;
    Node *tail = CL;    // point tail always point the rear of CL

    for (int i = 0; i < DEFAULTSIZE; i++)
    {
        s = (Node *)malloc(sizeof(Node));
        s->data = i+1;
        
        s->next = tail->next;
        tail->next = s;
        tail = tail->next;  // <=> tail = s;
    }
    tail->next = CL;
}

void ShowCLinkedList(LinkedList CL)
{
    assert(CL != NULL);

    Node *p = CL->next;     // work point p
    
    while( p != CL )
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

LinkedList MergeLinkedList(LinkedList LA, LinkedList LB)
{
    assert(LA != NULL);
    assert(LB != NULL);

    Node *pa = LA;
    Node *pb = LB;

    // find tail of LA and LB
    while(pa->next != LA)
    {
        pa = pa->next;
    }
    while(pb->next != LB)
    {
        pb = pb->next;
    }

    pa->next = LB->next;    // LB->next attach to LA->tail
    free(LB);   // free LB (head node)
    pb->next = LA;  // LA: tail -> head

    return LA;
}