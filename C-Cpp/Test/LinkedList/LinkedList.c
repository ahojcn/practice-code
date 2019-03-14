//
// Created by hanoi_ahoj on 2018/12/28.
//

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

static SLinkedList *SLinkListBuyNode(SLinkedListElemType new_val);

SLinkedList *SLinkListBuyNode(SLinkedListElemType new_val) {
    SLinkedList *s = (SLinkedList *) malloc(sizeof(SLinkedList));
    assert(s != NULL);
    s->next = NULL;
    s->val = new_val;
    return s;
}

void SLinkListInit(SLinkedList **pphead) {
    assert(pphead != NULL);
    (*pphead) = NULL;
}

int GetSLinkListLnegth (const SLinkedList *phead) {
    int len = 0;
    const SLinkedList *cur = phead;
    while(cur != NULL) {
        len++;
        cur = cur->next;
    }
    return len;
}

void ShowSLinkList(const SLinkedList *phead){
    if(phead == NULL) {
        printf("NULL\n");
    } else {
        const SLinkedList *cur = phead;
        while (cur != NULL) {
            printf("%d -> ", cur->val);
            cur = cur->next;
        }
        printf("NULL\n");
    }
}

void InsertSLinkListFromHead (SLinkedList **pphead, const SLinkedListElemType val) {
    assert(pphead != NULL);
    SLinkedList *s = SLinkListBuyNode(val);
    s->next = (*pphead);
    (*pphead) = s;
}

void InsertSLinkListFromTail (SLinkedList **pphead, const SLinkedListElemType val) {
    assert(pphead != NULL);
    if((*pphead) == NULL) {
        InsertSLinkListFromHead(pphead, val);
    } else {
        // find tail
        SLinkedList *p = (*pphead);
        while (p->next != NULL) {
            p = p->next;
        }
        SLinkedList *s = SLinkListBuyNode(val);
        p->next = s;
    }
}

void DeleteSLinkListFromHead (SLinkedList **pphead) {
    assert(pphead != NULL);
    SLinkedList *tmp = (*pphead);
    (*pphead) = (*pphead)->next;
    free(tmp);
}

void DeleteSLinklistFromTail(SLinkedList **pphead) {
    assert(pphead != NULL);
    SLinkedList *p = (*pphead);
    while (p->next->next != NULL){
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}

SLinkedList *SearchSLinkListVal(const SLinkedList **pphead, const SLinkedListElemType e){
    assert(pphead != NULL);
    const SLinkedList *p = (*pphead);
    const SLinkedList *ret = NULL;
    while (p != NULL) {
        p = p->next;
        if (p->val == e){
            ret = p;
            break;
        }
    }
    return ret;
}
