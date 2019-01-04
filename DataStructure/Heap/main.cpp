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

    return 0;
}