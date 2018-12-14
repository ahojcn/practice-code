/*
 * 线性表的顺序存储相关操作
 * ahoj 20181214
 */

#include "SqList.h"

int main(int argc, const char * argv[])
{
    SqList L;
    ElemType e = 111;
    InitList(&L);
    
    for(int i=0; i<10; i++)
    {
        L.data[i] = rand()%30;
        L.length ++;
    }
    
    ListInsert(&L, 10, e);
    ListShow(L);
    printf("length = %d\n", L.length);

    ListShow(L);
    printf("length = %d\n", L.length);
    ListDelete(&L, 1, &e);
    ListShow(L);
    printf("length = %d\n", L.length);
    
    return 0;
}
