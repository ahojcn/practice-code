//
//  1.c
//  算法练习5
//
//  Created by hanoi_ahoj on 2018/10/30.
//  Copyright © 2018 hanoi_ahoj. All rights reserved.
//

#include <stdio.h>

// 辗转相除递归法
int gcd(int a, int b);
// a的n次幂
int f(int a, int n);
// 一个数a的n次幂对p取模
int ff(int a, int n, int p);

int main(int argc, const char * argv[])
{
    /****** 最大公约数 ******/
    int a = 3, b = 15;
    // 暴力
    for(int i=a; i>=1; i--)
    {
        if(a%i==0 && b%i==0)
        {
            printf("%d\n", i);
            break;
        }
    }
    // 辗转相除法 这里假设a是较小的那个，b是较大的那个
    while(1)
    {
        if(a == 0)
        {
            printf("%d\n", b);
            break;
        }
        int tmp = a;
        a = b % a;
        b = tmp;
    }
    // 辗转相除递归法
    printf("%d\n", gcd(a,b));
    
    
    /****** 最小公倍数 ******/
    // 最小公倍数 = a*b / gcd(a,b)
    a = 15;
    b = 20;
    printf("--\n%d\n", (a*b)/gcd(a, b));
    
    
    /****** 一个数a的n次幂 ******/
    printf("--\n%d\n", f(2, 3));
    // 这个 f 对小数字是有用的
    
    /****** 一个数a的n次幂对p取模 ******/
    printf("--\n%d\n", ff(3, 50, 17));
    
    
    return 0;
}

// 辗转相除递归法
int gcd(int a, int b)
{
    if(a==0)
    {
        return b;
    }
    return gcd(b%a, a);
}

// a的n次幂
int f(int a, int n)
{
    int ret = 1;
    for(int i=0; i<n; i++)
    {
        ret = ret*a;
    }
    return ret;
}

// 一个数a的n次幂对p取模
int ff(int a, int n, int p)
{
    int ret = 1;
    for(int i=0; i<n; i++)
    {
        ret = (ret * a)%p;
    }
    return ret%p;
}

