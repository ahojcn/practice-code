//
// Created by hanoi_ahoj on 2019/1/5.
//

#include <stdio.h>
#include <stdlib.h>

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */

typedef struct Node{
    int val;
    struct Node *next;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate()
{
    MyLinkedList *p_head = (MyLinkedList *) malloc(sizeof(MyLinkedList));
    p_head->next = NULL;
    p_head->val = 0;
    return p_head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index)
{
    if (index < 0)
        return -1;
    MyLinkedList *temp = obj->next;
    while (temp) {
        if (index == 0)
            return temp->val;
        temp = temp->next;
        index--;
    }
    return -1;
}

/** Add a node of value val before the first element of the linked list.
 * After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
    MyLinkedList *p = obj;
    MyLinkedList *new_node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    new_node->val = val;

    new_node->next = p->next;
    p->next = new_node;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
    MyLinkedList *p = obj;
    while (p->next != NULL)
    {
        p = p->next;
    }
    MyLinkedList *new_node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    new_node->val = val;
    new_node->next = NULL;
    p->next = new_node;
}

/** Add a node of value val before the index-th node in the linked list.
 * If index equals to the length of linked list, the node will be appended to the end of linked list.
 * If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
    MyLinkedList *p = obj->next;
    MyLinkedList *pre = NULL;
    if (index == 0)
    {
//        myLinkedListAddAtHead(obj, val);
        return;
    }
    while (index && p != NULL)
    {
        pre = p;
        index--;
        p = p->next;
    }
    if (index == 0 && p != NULL)    // 在p的前面插入
    {
        MyLinkedList *new_node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
        new_node->val = val;
        new_node->next = p;
        pre->next = new_node;
        return;
    }
    if (index == 0)     // 到了结尾
    {
//        printf("%p!!!\n", p);
        myLinkedListAddAtTail(obj, val);
    }
    else
    {
        return;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
    if (index == 0)
        return;
    MyLinkedList *pre = NULL;
    MyLinkedList *cur = obj;
    while (index && cur != NULL)
    {
        pre = cur;
        index--;
        cur = cur->next;
    }
    if (cur != NULL && index == 0)
    {
        pre->next = cur->next;
        free(cur);
    }
    else
    {
        return;
    }
}

void myLinkedListFree(MyLinkedList* obj)
{
    MyLinkedList *cur = obj->next;
    MyLinkedList *tmp = cur;
    while (cur != NULL)
    {
        free(tmp);
        cur = cur->next;
        tmp = cur;
    }
    obj = NULL;
}

void PrintLinkedList(const MyLinkedList *obj)
{
    MyLinkedList *p = obj->next;
    while (p != NULL)
    {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
}

int main()
{
    /*
     * ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
        [[],            [1],        [3],        [1,2],      [1],    [1],            [1]]
     * */
    MyLinkedList* obj = myLinkedListCreate();
//    int param_1 = myLinkedListGet(obj, 0);
    myLinkedListAddAtHead(obj, 1);
    myLinkedListAddAtTail(obj, 3);
    myLinkedListAddAtIndex(obj, 1, 2);
    PrintLinkedList(obj);
    printf("--%d--\n", myLinkedListGet(obj, 1));
    myLinkedListDeleteAtIndex(obj, 1);
    printf("--%d--\n", myLinkedListGet(obj, 1));
//    myLinkedListDeleteAtIndex(obj, 2);
//    myLinkedListAddAtHead(obj, val);
//    myLinkedListAddAtTail(obj, val);
//    myLinkedListAddAtIndex(obj, index, val);
//    myLinkedListDeleteAtIndex(obj, index);
//    myLinkedListFree(obj);
    return 0;
}