#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 10

typedef int ListElemType;

typedef struct List
{
    ListElemType *arr;
    int total;
} List;

// 顺序表初始化
void ListInit(List *l);
// 打印
void PrintList(const List *l);

// 顺序表头插
void ListInsertAtHead(List *l, ListElemType e);

int main(int argc, char const *argv[])
{
    List l;
    ListInit(&l);
    PrintList(&l);
    ListInsertAtHead(&l, 1);
    ListInsertAtHead(&l, 2);
    ListInsertAtHead(&l, 3);
    PrintList(&l);
    
    return 0;
}

void ListInit(List *l)
{
    l->arr = (ListElemType *)malloc(sizeof(int) * MAXSIZE);
    assert(l->arr != NULL);
    l->total = 0;
}

void PrintList(const List *l)
{
    for (int i = 0; i < l->total; ++i)
    {
        printf("%d ", l->arr[i]);
    }
    printf("\n");
}

void ListInsertAtHead(List *l, ListElemType e)
{
    // move
    for (int i = l->total - 1; i >= 0; --i)
    {
        l->arr[i+1] = l->arr[i];
    }
    // insert
    l->arr[0] = e;
    l->total++;
}
