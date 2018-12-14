
#ifndef SqList_h
#define SqList_h

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAXSIZE 20

typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

typedef enum
{
    OK = 1,
    ERROR = 0,
    TRUE = 1,
    FALSE = 0,
}Status;

/*   Options   */
Status InitList(SqList* L);
Status ListEmpty(SqList L);
Status ClearList(SqList* L);
Status GetElem(SqList L, int i, ElemType* e);
int LocateElem(SqList L, ElemType e);
Status ListInsert(SqList* L, int i, ElemType e);
Status ListDelete(SqList* L, int i, ElemType* e);
int ListLength(SqList L);
void ListShow(SqList L);

#endif /* SqList_h */
