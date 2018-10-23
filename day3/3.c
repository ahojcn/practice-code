/*
 1. 将数组A中的内容和数组B中的内容进行交换。（数组一样大）
 2. 计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值。
 3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。
 */

#include <stdio.h>

//1. 将数组A中的内容和数组B中的内容进行交换。（数组一样大）
void t_1()
{
    int A[10] = { 20,21,22,23,24,25,26,27,28,29 };
    int B[10] = { 10,11,12,13,14,15,16,17,18,19 };
    
    for (int i=0; i<10; i++)
    {
        A[i] = A[i]^B[i];
        B[i] = A[i]^B[i];
        A[i] = A[i]^B[i];
    }
    
    printf("now A[10]:\n");
    for (int i=0; i<10; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    
    printf("now B[10]:\n");
    for (int i=0; i<10; i++)
    {
        printf("%d ",B[i]);
    }
    printf("\n");
}

//2. 计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值。
void t_2()
{
    float up = 1;
    float down = 1;
    float sum = 0;
    int sign = 1;
    for ( down = 1; down<=100; down++)
    {
        sum += (up/down)*sign;
        sign = -sign;
    }
    printf("%f\n",sum);
}

//3. 编写程序数一下 1 到 100 的所有整数中出现多少次数字9。
void t_3()
{
    int cnt = 0;
    for (int i=1; i<=100; i++)
    {
        if ( 9 == i%10 )
        {
            cnt++;
        }
        if ( 9 == i/10 )
        {
            cnt++;
        }
    }
    printf("%d\n",cnt);
}

int main()
{
    printf("1.将数组A中的内容和数组B中的内容进行交换。（数组一样大）\n");
    t_1();
    
    printf("2.计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值。\n");
    t_2();
    
    printf("3.编写程序数一下 1 到 100 的所有整数中出现多少次数字9。\n");
    t_3();
    
    return 0;
}










