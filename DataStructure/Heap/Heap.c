//
// Created by hanoi_ahoj on 2019/1/4.
//

#include "Heap.h"
#include <stdio.h>
#include <assert.h>

void AdjustDown(HeapElemType *arr, int sz, HeapElemType root)
{
    assert(arr != NULL);
    int left = root * 2 + 1;
    int right = root * 2 + 2;
    while (left <= sz)
    {
        int min = left;
        if (right < sz && arr[right] > arr[left])
        {
            min = right;
        }

        // 比较 array[min]	array[root]
        if (arr[root] >= arr[min])
        {
            break;
        }

        // 交换值
        int t = arr[root];
        arr[root] = arr[min];
        arr[min] = t;

        // 需要继续向下调整，以 min 作为结点
        root = min;

        left = root * 2 + 1;
    }
}

void CreateHeap(HeapElemType *arr, int sz)
{
    assert(arr != NULL);
    for (int i = (sz-2)/2; i >= 0; --i)
    {
        AdjustDown(arr, sz, i);
    }
}