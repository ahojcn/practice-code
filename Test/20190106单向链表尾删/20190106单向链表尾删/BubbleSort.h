//
//  BubbleSort.h
//  20190106单向链表尾删
//
//  Created by hanoi_ahoj on 2019/1/7.
//  Copyright © 2019 ahoj. All rights reserved.
//

#ifndef BubbleSort_h
#define BubbleSort_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int *arr, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int flag = 1;   // 假设已经有序
        
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                flag = 0;   // 发生交换就说明没有序
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }   // for j
        
        if(flag == 1)
        {
            break;
        }
    }   // for i
}

void PrintArr(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void TestBubbleSort(void )
{
    srand((unsigned int)time(NULL));
    int arr[10] = {0};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand() % 50 + 1;
    }
    
    puts("befor sort:");
    PrintArr(arr, size);
    
    BubbleSort(arr, size);
    
    puts("after sort:");
    PrintArr(arr, size);
}

#endif /* BubbleSort_h */
