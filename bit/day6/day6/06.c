//
//  06.c
//  day6
//
//  Created by hanoi_ahoj on 2018/10/15.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include "06.h"

int FibonacciNumber(int n)
{
    if (n<=2)
    {
        return 1;
    }
    else
    {
        int a = 1;
        int b = 1;
        int c = 0;
        for (int i=0; i<n-2; i++)
        {
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
}
int FibonacciNumberRecursion(int n)
{
    if (n<=2)
    {
        return 1;
    }
    else
    {
        return FibonacciNumberRecursion(n-1) + FibonacciNumberRecursion(n-2);
    }
}

int FactorialRecursion(int n)
{
    if (n<2)
    {
        return 1;
    }
    else
    {
        return FactorialRecursion(n-1)*n;
    }
}

int DigitSum(int n)
{
    int sum = 0;
    if (n<=0)
    {
        return sum;
    }
    else
    {
        sum = n%10;
        n = n/10;
        return sum + DigitSum(n);
    }
}

int right = 0;
int left = 0;
int cnt = 0;
void ReverseString(char *string)
{
    int length = -1;
    char *p = string;
    while (*p != '\0')
    {
        p++;
        length++;
    }
    right = length - cnt;
    cnt++;
    char temp = *(string+left);
    *(string+left) = *(string+right);
    *(string+right) = temp;
    left++;
    if (left < right)
    {
        ReverseString(string);
    }
}




