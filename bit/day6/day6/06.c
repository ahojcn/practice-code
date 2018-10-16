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

int N_K_Recursion(int n, int k)
{
    if (k != 0)
    {
        if (0 == n)
        {
            return 0;
        }
        else if (1 == n)
        {
            return 1;
        }
        else
        {
            return N_K_Recursion(n, --k)*n;
        }
    }
    else
    {
        return 1;
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

int MyStrlenRecursion(const char *string)
{
    if (*string != '\0')
    {
        return 1+MyStrlenRecursion(string+1);
    }
    else
    {
        return 0;
    }
}
int MyStrlen(const char *string)
{
    int len = 0;
    while (*string != '\0')
    {
        len++;
        string++;
    }
    return len;
}

int FactorialRecursion(int n)
{
    if (n > 0)
    {
        return FactorialRecursion(n-1) * n;
    }
    else
    {
        return 1;
    }
}
int Factorial(int n)
{
    int sum = 1;
    for (int i = 1; i<=n; i++)
    {
        sum *= i;
    }
    return sum;
}

void ShowdataRecursion(int n)
{
    if (n < 0)
    {
        n = -n;
    }
    if (n != 0)
    {
        ShowdataRecursion(n/10);
        printf("%d ",n%10);
    }
}

