#include "SeqList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

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
void SeqListLog(const char *leval, const char *msg)
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
    if (index < 0 || index > sl->size)
    {
        SeqListLog("WARNING", "illegal index to insert!");
        printf("pos:%d is illegal\n", index);
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
        sl->size++;
    }
}

void SeqListDelFromTail(SeqList *sl)
{
    assert(sl != NULL);
    if (SeqListIsEmpty(sl))
    {
        SeqListLog("WARNING", "the seqlist is empty!");
        return;
    }

    sl->size--;
}

void SeqListDelFromHead(SeqList *sl)
{
    assert(sl != NULL);
    if (SeqListIsEmpty(sl))
    {
        SeqListLog("WARNING", "the seqlist is empty!");
        return;
    }

    // move to cover
    for (int i = 0; i < sl->size; i++)
    {
        sl->arr[i] = sl->arr[i + 1];
    }
    sl->size--;
}

int SeqListDelFirstOne(SeqList *sl, SeqElemType value)
{
    assert(sl != NULL);

    int ret = -1;
    int pos = -1;

    for (int i = 0; i < sl->size; i++)
    {
        if (sl->arr[i] == value)
        {
            ret = -1;
            pos = i;
            break;
        }
    }

    if (-1 != pos)
    {
        for (int i = pos; i < sl->size; i++)
        {
            sl->arr[i] = sl->arr[i + 1];
        }
        sl->size--;
    }

    return ret;
}

int SeqListDelAllValue(SeqList *sl, SeqElemType value)
{
    assert(sl != NULL);

    if (SeqListIsEmpty(sl))
    {
        return 0;
    }
    SeqElemType *tmp_arr = (SeqElemType *)malloc(sizeof(SeqElemType) * sl->cap);
    int ret = 0;
    for (int i = 0, j = 0; i < sl->size; i++)
    {
        if (sl->arr[i] != value)
        {
            tmp_arr[j] = sl->arr[i];
            j++;
        }
        else
        {
            ret++;
        }
    }

    if (0 == ret)
    {
        free(tmp_arr);
    }
    else
    {
        free(sl->arr);
        sl->arr = tmp_arr;
        sl->size -= ret;
    }

    return ret;
}

// O(n)
int SeqListFindValue(SeqList *sl, SeqElemType value)
{
    assert(sl != NULL);

    int ret = -1;

    for (int i = 0; i < sl->size; i++)
    {
        if (sl->arr[i] == value)
        {
            ret = i;
        }
    }

    return ret;
}

int SeqListBinFindValue(SeqList *sl, SeqElemType value)
{
    assert(sl != NULL);

    int ret = -1;
    int l = 0, r = sl->size;
    while (l < r)
    {
        // printf("l -> %d, r -> %d\n", l, r);  //// TEST
        int mid = (r + l) / 2;
        if (value > sl->arr[mid])
        {
            l = mid + 1;
        }
        else if (value < sl->arr[mid])
        {
            r = mid;
        }
        else
        {
            ret = mid;
            break;
        }
    }

    return ret;
}

void SeqListBobSort(SeqList *sl)
{
    assert(sl != NULL);

    int flag = 0;
    for (int i = 0; i < sl->size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < sl->size - 1; j++)
        {
            if (sl->arr[j] > sl->arr[j + 1])
            {
                flag = 1;
                SeqElemType tmp = sl->arr[j];
                sl->arr[j] = sl->arr[j + 1];
                sl->arr[j + 1] = tmp;
            }
        }

        if (flag == 0)
            break;
    }
}

static int SeqElemTypeCmp(const void *a, const void *b)
{
    return *(SeqElemType *)b - *(SeqElemType *)a;
}

void SeqListQSort(SeqList *sl)
{
    assert(sl != NULL);
    qsort(sl->arr, sl->size, sizeof(int), SeqElemTypeCmp);
}

SeqElemType SeqListSearchIndex(SeqList *sl, int index)
{
    assert(sl != NULL);
    assert(index >= 0 && index < sl->size);

    return sl->arr[index];
}

void SeqListUpdateValue(SeqList *sl, int index, SeqElemType value)
{
    assert(sl != NULL);
    if (index < 0 || index > sl->size)
    {
        SeqListLog("ERROR", "修改位置不合法");
        return;
    }

    sl->arr[index] = value;
}

static int SeqListAdjustArr(SeqElemType *arr, int l, int r)
{
    int i = l, j = r;
    int x = arr[i]; // 挖坑 arr[i]
    while (i < j)
    {
        // 从后向前找小于 x 的数填充arr[i]
        while (i < j && arr[j] >= x)
        {
            j--;
        }
        // printf("i = %d, j = %d, arr[i] = %d, arr[j] = %d\n", i,j,arr[i],arr[j]);
        if (i < j)
        {
            arr[i] = arr[j];
            i++;
        }
        // 从前向后找大于等于x的数填arr[j]
        while (i < j && arr[i] < x)
        {
            i++;
        }
        if (i < j)
        {
            arr[j] = arr[i];
            j--;
        }
    }
    // 退出时， i == j，将x填入这个坑中
    arr[i] = x;

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    return i;
}

static void SeqListQuickSortFun(SeqElemType *arr, int l, int r)
{
    if (l < r)
    {
        int i = SeqListAdjustArr(arr, l, r);
        SeqListQuickSortFun(arr, l, i - 1);
        SeqListQuickSortFun(arr, i + 1, r);
    }
}

void SeqListQuickSort(SeqList *sl)
{
    assert(sl != NULL);
    assert(sl->arr != NULL);
    SeqListQuickSortFun(sl->arr, 0, sl->size);
}

void SeqListUpdateOneValue(SeqList *sl, SeqElemType old_value, SeqElemType new_value)
{
    assert(sl != NULL);
    assert(sl->arr != NULL);

    int pos = SeqListFindValue(sl, old_value);

    sl->arr[pos] = new_value;
}

void SeqListUpdateAllOldValue(SeqList *sl, SeqElemType old_value, SeqElemType new_value)
{
    assert(sl != NULL);
    assert(sl->arr != NULL);
    
    for (int i = 0; i < sl->size; i++)
    {
        if (sl->arr[i] == old_value)
        {
            sl->arr[i] = new_value;
        }
    }
}