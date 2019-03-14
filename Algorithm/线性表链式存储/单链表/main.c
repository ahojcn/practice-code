/*
 * 线性表的链式存储 —— 单链表
 * ahoj 20181215
 * 涉及到位置的地方均已0开始编号
 */

#include "List.h"

int main(int argc, const char *argv[])
{
    // TEST
    LinkList L = NULL;
    Node *p = NULL;
    InitList(&L);

    CreateFromHead(L);
    ShowList(L);

    CreateFromTail(L);
    ShowList(L);

    p = GetNode(L, 3);
    printf("%d\n", p->data);

    printf("%d\n", Locate(L, 0)->data);

    printf("ListLength:%d\n", ListLength(L));

    InsertList(L, 0, 666);
    ShowList(L);

    DeleteList(L, 0);
    ShowList(L);

    DestoryList(&L);
    ShowList(L);

    return 0;
}
