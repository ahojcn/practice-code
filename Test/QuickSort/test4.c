#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int AdjustArr(int a[], int l, int r)
{
    int i = l, j = r;
    int x = a[l];
    while (i < j)
    {
        // r -> l
        while (i < j && a[j] >= x)
            j--;
        if (i < j)
        {
            a[i] = a[j];
            i ++;
        }

        // l -> r
        while (i < j && a[i] < x)
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

void QuickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int i = AdjustArr(a, l, r);
        QuickSort(a, i+1, r);
        QuickSort(a, l, i-1);
    }
}

void ShowArr(int a[], int len)
{
    for (int i=0; i<len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{

    int a[N] = {0};
    srand((unsigned int)time(NULL));
    for (int i=0; i<N; i++)
    {
        a[i] = rand()%N+1;
    }
    ShowArr(a, N);

    QuickSort(a, 0, N-1);

    ShowArr(a, N);

    return 0;
}

