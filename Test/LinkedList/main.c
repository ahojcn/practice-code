//
// Created by hanoi_ahoj on 2018/12/28.
//

#include <stdio.h>
#include "LinkedList.h"

int main()
{
    SLinkedList *sl = NULL;
    SLinkListInit(&sl);
    ShowSLinkList(sl);
    printf("len : %d\n", GetSLinkListLnegth(sl));

    InsertSLinkListFromTail(&sl, 2);
    InsertSLinkListFromHead(&sl, 1);
    InsertSLinkListFromTail(&sl, 3);
    ShowSLinkList(sl);
    printf("len : %d\n", GetSLinkListLnegth(sl));
    DeleteSLinkListFromHead(&sl);
    DeleteSLinklistFromTail(&sl);
    ShowSLinkList(sl);
    printf("len : %d\n", GetSLinkListLnegth(sl));

    return 0;
}