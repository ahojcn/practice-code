//
//  main.c
//  单链表上的基本运算
//
//  Created by hanoi_ahoj on 2018/10/10.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"

int main(int argc, const char * argv[])
{
    LinkedList LA;
    InitLinkedList(&LA);
    CreateFromHead(LA);
    ShowData(LA);
    
    LinkedList LB;
    InitLinkedList(&LB);
    CreateFromTail(LB);
    ShowData(LB);
    
    LinkedList LC;
    InitLinkedList(&LC);
    LC = MergeLinkedList(LA, LB);
    ShowData(LC);
    
    
    /*
    Node *p;
    p = Get(LB, 2);
    printf("%d\n",p->data);
    
    p = Locate(LB, 1);
    printf("%d\n",p->data);
    
    printf("%d\n",LinkedListLength(LB));
    
    InsertLinkedList(LB, 1, 10);
    ShowData(LB);
    
    DeleteLinkedList(LB, 2);
    ShowData(LB);
     */
    
    return 0;
}
