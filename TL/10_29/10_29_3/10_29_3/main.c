//
//  main.c
//  10_29_3
//
//  Created by hanoi_ahoj on 2018/10/31.
//  Copyright © 2018 hanoi_ahoj. All rights reserved.
//

#include <stdio.h>

// n^k
int nk(int n, int k)
{
    int ret = 1;
    for(int i=0; i<k; i++)
    {
        ret *= n;
    }
    
    return ret;
}

// 2进制
int f(int a[], int N)
{
    int i=0;
    while(N>0)
    {
        a[++i] = N%2;
        N /= 2;
    }
    
    return i;
}

int main(int argc, const char * argv[])
{
    int k=0, N=0;
    
    scanf("%d%d", &k, &N);
    
    int arr[100] = {0};
    int len = f(arr, N);
    int ans = 0;
    
    for(int i=1; i<=len; i++)
    {
        if(arr[i] == 1)
        {
            ans += nk(k, i-1);
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
