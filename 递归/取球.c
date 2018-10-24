//
//  main.c
//  递归问题之组合问题
//
//  Created by hanoi_ahoj on 2018/10/23.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

// 在n个球中，任意取m个(不放回)，求有多少种取法

#include <stdio.h>

int f(int n, int m)
{
    if (n<m)    // 3个球取4个出来 显然是0种取法
    {
        return 0;
    }
    if (m==0)   // 3个球取0个出来 有1种取法
    {
        return 1;
    }
    if (n==m)   // 3个球取3个出来 有1种取法
    {
        return 1;
    }
    return f(n-1, m-1) + f(n-1, m);
}

int main(int argc, const char * argv[])
{
    int k = f(5, 3);
    printf("%d\n", k);
    
    return 0;
}
