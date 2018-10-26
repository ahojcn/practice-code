// 组合问题
// 3个A 2个B可以组成多少 种 排列
// 如：AAABB AABBA等

#include <stdio.h>

// m个A n个B
int f(int m, int n)
{
    if(m == 0 || n == 0)
    {
        return 1;
    }
    // 假设首位置为A，则剩下m-1个A和n个B的组合问题 + 首位置为B...
    return f(m-1, n) + f(m, n-1);
}

int main()
{
    printf("%d\n", f(3, 1));
    return 0;
}
