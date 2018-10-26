// 整数划分问题
// n = 6
/*
 6
 5+1
 4+2,4+1+1
 3+3,3+2+1,3+1+1+1
 2+2+2,2+2+1+1,2+1+1+1+1
 1+1+1+1+1+1
 */

#include <stdio.h>

#define MAXSIZE 1024

// arr->缓冲，cur->当前位置
void f(int n, int arr[], int cur)
{
    if(n<=0)
    {
        for(int i=0; i<cur; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i=n; i>0; i--)
    {
        if(cur>0 && i>arr[cur-1])
        {
            continue;
        }
        arr[cur] = i;
        f(n-i, arr, cur+1);
    }
}

int main()
{
    int arr[MAXSIZE] = {0};
    f(6, arr, 0);
    return 0;
}
