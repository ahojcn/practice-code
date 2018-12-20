#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int partition(int a[], int l, int r)
{
    int i = l, j = r;
    int x = a[l];

    while (i < j)
    {
        // 从右向左找 a[j]<x
        while (i<j && a[j]>=x)
            j--;
        if (i < j)
        {
            a[i] = a[j];
            i++;
        }

        // 从左向右找 a[i]>=x
        while (i<j && a[i]<x)
            i++;
        if (i < j)
        {
            a[j] = a[i];
            j--;
        }

    }

    a[i] = x;
    return i;
}

void quick_sort(int a[], int l, int r)
{
    if(l < r)
    {
        int i = partition(a, l, r);
        quick_sort(a, l, i-1);
        quick_sort(a, i+1, r);
    }
}

void prt_arr(int a[], int len)
{
    for(int i=0; i<len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int arr[N] = {0};
    srand((unsigned int)time(NULL));
    for(int i = 0; i<N; i++)
    {
        arr[i] = rand()%100+1;
    }

    prt_arr(arr, N);

    quick_sort(arr, 0, N-1);

    prt_arr(arr, N);

    return 0;
}
