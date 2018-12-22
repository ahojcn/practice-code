#include "SeqList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 判断空、满
// full / empty -> true
bool SeqListIsFull(SeqList *sl)
{
    return (sl->size == sl->cap) ? true : false;
}

bool SeqListIsEmpty(SeqList *sl)
{
    return (sl->size == 0) ? true : false;
}

// Log function
static void SeqListLog(const char *leval, const char *msg)
{
    printf("%s:%s\n", leval, msg);
}

void SeqListShowArr(const SeqList *sl)
{
    assert(sl != NULL);
    assert(sl->arr != NULL);

    for (int i = 0; i < sl->size; i++)
    {
        printf("%d ", sl->arr[i]);
    }
    printf("\n");
}

int SeqListGetSize(const SeqList *sl)
{
    assert(sl != NULL);

    return sl->size;
}

int SeqListGetCap(const SeqList *sl)
{
    assert(sl != NULL);

    return sl->cap;
}

void SeqListInit(SeqList *sl)
{
    assert(sl != NULL);

    sl->size = 0;
    sl->cap = INIT_SIZE;
    sl->arr = (SeqElemType *)malloc(sizeof(SeqElemType) * INIT_SIZE);
    assert(sl->arr != NULL);
}

void SeqListInc(SeqList *sl)
{
    assert(sl != NULL);

    int new_size = sl->cap * INC_SIZE;
    SeqElemType *tmp = (SeqElemType *)malloc(sizeof(SeqElemType) * new_size);
    assert(tmp != NULL);

    // copy old -> new
    memcpy(tmp, sl->arr, sizeof(SeqElemType) * sl->size);

    // free old
    free(sl->arr);

    sl->arr = tmp;
    sl->cap = new_size;
}

void SeqListDestory(SeqList *sl)
{
    assert(sl != NULL);
    assert(sl->arr != NULL);

    free(sl->arr);
    sl->arr = NULL;
    sl->cap = 0;
    sl->size = 0;
}

void SeqListAddFromTail(SeqList *sl, SeqElemType value)
{
    assert(sl != NULL);

    if (SeqListIsFull(sl))
    {
        SeqListInc(sl);
    }

    sl->arr[sl->size] = value;
    sl->size++;
}

void SeqListAddFromFront(SeqList *sl, SeqElemType value)
{
    assert(sl != NULL);

    if (SeqListIsEmpty(sl))
    {
        SeqListAddFromTail(sl, value);
        return;
    }
    if (SeqListIsFull(sl))
    {
        SeqListInc(sl);
    }

    // move
    for (int i = sl->size; i > 0; i--)
    {
        sl->arr[i] = sl->arr[i - 1];
    }
    // insert value -> arr[0]
    sl->arr[0] = value;
    sl->size++;
}

void SeqListInsert(SeqList *sl, SeqElemType value, int index)
{
    assert(sl != NULL);
    if (index < 0 || index > sl->size + 1)
    {
        SeqListLog("WARNING", "illegal index to insert!");
        return;
    }

    if (index == 0)
    {
        SeqListAddFromFront(sl, value);
    }
    else if (index == sl->size)
    {
        SeqListAddFromTail(sl, value);
    }
    else
    {
        if (SeqListIsFull(sl))
        {
            SeqListInc(sl);
        }
        // move
        for (int i = sl->size; i >= index; i--)
        {
            sl->arr[i] = sl->arr[i - 1];
        }
        // insert
        sl->arr[index] = value;
        sl->size ++;
    }
}
