/*
 2.不使用（a+b）/2这种方式，求两个数的平均值。
 */

#include <stdio.h>

int main()
{
    int a=10, b=20;
    printf("1: %d\n", (a+b)>>1);
    
    // 小 + (大-小)/2
    // 大 - (大-小)/2
    printf("2: %d\n", ( (a>b?a:b)-((a>b?a:b)-(a>b?b:a))/2 ));
    
    // 用a和b相同的部分加上a和b不同的地方，a和b相同的部分为（a&b），a和b不同的部分为（a^b），不同的部分除以二就是（a^b>>1）
    printf("3. %d\n", ((a&b)+(a^b)) >> 1 );
    
    
    return 0;
}
