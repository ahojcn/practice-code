//
// Created by hanoi_ahoj on 2019/1/4.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#define MAXSIZE 1 * 100

typedef int HeapElemType;

typedef struct HeapNode
{
    HeapElemType arr[MAXSIZE];
    int size;
} Heap;

// 向下调整
void AdjustDown(HeapElemType *arr, int sz, HeapElemType root);

void CreateHeap(HeapElemType *arr, int sz);

#endif //HEAP_HEAP_H
