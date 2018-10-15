//
//  main.c
//  blog数组的增删改查练习
//
//  Created by hanoi_ahoj on 2018/10/3.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include "head.h"

int main(int argc, const char * argv[])
{
    SeqList L;
    InitSeqList(&L);
    ShowAllSeqListData(&L);
    
    AddOneData(&L, 6);
    ShowAllSeqListData(&L);
    
    InsertOneData(&L, 1, 10);
    ShowAllSeqListData(&L);
    
    DelOneData(&L, 1);
    ShowAllSeqListData(&L);
    
    ChangeOneData(&L, 1, 10);
    ShowAllSeqListData(&L);
    
    ChangeData(&L, 10, 1);
    ShowAllSeqListData(&L);
    
    printf("%d\n",FileData1(&L, 1));
    
    printf("%d\n",FindData2(&L, 6));
    
    return 0;
}

