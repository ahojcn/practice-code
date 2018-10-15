//
//  07.c
//  day07
//
//  Created by hanoi_ahoj on 2018/10/15.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include "07.h"

void q1(void)
{
    int n = 0;
    scanf("%d",&n);
    
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=i; j++)
        {
            printf("%d*%d=%d ", j, i, i*j);
        }
        printf("\n");
    }
}

void q2(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

int q3(int year)
{
    if ((year%4==0 && year%100!=0) || year%400==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void InitArr(int arr[], int arr_size)
{
    for (int i=0; i<arr_size; i++)
    {
        arr[i] = i+1;
    }
}
void EmptyArr(int arr[], int arr_size)
{
    for (int i=0; i<arr_size; i++)
    {
        arr[i] = 0;
    }
}
void ReverseArr(int arr[], int arr_size)
{
    for (int i=0,j=arr_size-1; j>i; i++,j--)
    {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
void PrintArr(int arr[], int arr_size)
{
    for (int i=0; i<arr_size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int q5(int n)
{
    int flag = 1;
    for (int i=2; i<n; i++)
    {
        if (n%i == 0)
        {
            flag = 0;
            break;
        }
        else
        {
            flag = 1;
        }
    }
    return flag;
}





