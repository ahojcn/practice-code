/*
 1.一个数组中只有两个数字是出现一次，
 其他所有数字都出现了两次。
 找出这两个数字，编程实现。
 */
#include "Header.h"

void t1()
{
    int num1,num2;
    int arr[] = { 0, 0, 1, 1, 2, 22, 33, 33, 4, 4 };
    int size = sizeof(arr)/sizeof(arr[0]);
    qsort(arr, size, sizeof(int), cmp_int);

    find_num(arr, size, &num1, &num2);
    
    printf("1: %d,%d\n", num1, num2);
    
}

int cmp_int(const void *x, const void *y)
{
    int _x = *(int *)x;
    int _y = *(int *)y;
    
    if(_x > _y)
    {
        return 1;
    }
    else if(_x == _y)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void find_num(int arr[], int size, int *num1, int *num2)
{
    int count = 0;
    for(int i=0; i<size; i+=2)
    {
        if(arr[i] == arr[i+1])
        {
            continue;
        }
        else
        {
            if(0 == count)
            {
                *num1 = arr[i];
                i += 1;
            }
            else
            {
                *num2 = arr[i];
                i += 1;
            }
            count++;
        }
    }
}


