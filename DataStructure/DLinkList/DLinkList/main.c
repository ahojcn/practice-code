//
//  main.c
//  DLinkList
//  带头 双向 循环链表
//  Created by hanoi_ahoj on 2018/12/27.
//  Copyright © 2018 ahoj. All rights reserved.
//

#include <stdio.h>
#include "DLinkList.h"

int main(int argc, const char * argv[])
{
    DListNode *phead = NULL;
    InitDLinkList(&phead);
    InsertFromHead(phead, 11);
    InsertFromHead(phead, 22);
    ShowDLinkList(phead);
    InsertFromTail(phead, 33);
    InsertFromTail(phead, 44);
    ShowDLinkList(phead);
    
    InsertBeforeOneNode(phead, 55);
    ShowDLinkList(phead);
    return 0;
}
