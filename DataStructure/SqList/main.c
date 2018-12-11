/*
 线性表的顺序存储
 */

#include <stdio.h>
#include "SqList.h"

int main(int argc, const char * argv[])
{
    SqList S;
    InitSqList(&S);
    DisplaySqList(&S);
    
    ElemType e;
    if(GetElem(&S, 1, &e) == OK)
    {
        printf("e = %d\n", e);
    }
    else
    {
        printf("error!\n");
    }
    
    
    
    return 0;
}
