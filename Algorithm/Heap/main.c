#include <stdio.h>
#include "Heap.h"

void PrintArr(HeapElemType *arr, int sz)
{
    for (int i = 0; i < sz; ++i)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main()
{
    Heap heap;
    int arr[] = {2,35,22,33,99,17,25};
    int size = sizeof(arr) / sizeof(arr[0]);
    PrintArr(arr, size);
    CreateHeap(arr, size);
    PrintArr(arr, size);
    return 0;
}