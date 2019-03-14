#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int AdjustArr(int a[], int l, int r)
{
    int i = l;
    int j = r;
    int x = a[l];
    while (i < j)
    {
        // 从右向左找 a[j] < x，填入a[i]
        while (i < j && a[j] >= x)
        {
            j--;
        }
        if (i < j)
        {
            a[i] = a[j];
            i++;
        }
        // 从左向右找 a[i]>=x，填入a[j]中
        while (i < j && a[i] < x)
        {
            i++;
        }
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
        QuickSort(a, l, i - 1);
        QuickSort(a, i + 1, r);
    }
}

void ShowArr(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int a[N] = {0};
    int left = 0;
    int right = N - 1;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; i++)
    {
        a[i] = rand() % 100 + 1;
    }
    // ShowArr(a, N);

    QuickSort(a, left, right);

    // ShowArr(a, N);

    return 0;
}
