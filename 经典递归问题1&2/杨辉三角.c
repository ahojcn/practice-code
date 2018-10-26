// 杨辉三角
// 计算第m层第n个元素

/*
 1
 1 1
 1 2 1
 1 3 3 1
 1 4 6 4 1
 1 5 10 10 5 1
 */

#include <stdio.h>

int f(int m, int n)
{
    if(n == 0)
    {
        return 1;
    }
    if(m == n)
    {
        return 1;
    }
    return f(m-1, n) + f(m-1, n-1);
}

int main()
{
    int leval = 5;  // 第5行 0-5共6个元素
    for(int i=0; i<=leval; i++)
    {
        printf("%d ", f(leval, i));
    }
    printf("\n");
    return 0;
}
