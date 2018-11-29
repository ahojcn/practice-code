//
//  main.c
//  10_29_1
//
//  Created by hanoi_ahoj on 2018/10/29.
//  Copyright © 2018 hanoi_ahoj. All rights reserved.
//

#include <stdio.h>

// 3个还鞋 2个借鞋一共多少种排法
//int fun1(int m, int n)
//{
//    if(m==0 || n==0)
//    {
//        return 1;
//    }
//    return fun1(m-1, n) + fun1(m, n-1);
//}

// 计算体育组那没有些，也就是为0时候的个数
// m权值 1     n权值 -1
int fun2(int m, int n)
{
    if(m<n || m==0) // 如果还鞋的人 < 借鞋的人
    {
        return 0;
    }
    else if(n == 0) // 如果借鞋的人有0个，只有一种排法
    {
        return 1;
    }
    else    // 一个人还了鞋后，剩下m-1个还鞋的和n个借鞋的
    {       // 一个人借了鞋后，剩下m个还鞋的和n-1个借鞋的
        return fun2(m-1, n) + fun2(m, n-1);
    }
    
    return 0;
}

int main(int argc, const char * argv[])
{
    printf("%d\n", fun2(3, 2));
    
    return 0;
}
