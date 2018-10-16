//
//  06.h
//  day6
//
//  Created by hanoi_ahoj on 2018/10/15.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#ifndef _6_h
#define _6_h

#include <stdio.h>

/*
 q1.
 递归和非递归分别实现求第n个斐波那契数。
 */
int FibonacciNumber(int n);
int FibonacciNumberRecursion(int n);

/*
 q2.
 编写一个函数实现n^k，使用递归实现。
 */
int N_K_Recursion(int n, int k);

/*
 q3.
 一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19
 */
int DigitSum(int n);

/*
 q4.
 编写一个函数reverse_string(char * string)（递归实现）
 实现：将参数字符串中的字符反向排列。
 要求：不能使用C函数库中的字符串操作函数。
 */
void ReverseString(char *string);

/*
 q5.
 递归和非递归分别实现strlen.
 */
int MyStrlenRecursion(const char *string);
int MyStrlen(const char *string);

/*
 q6.
 递归和非递归分别实现求n的阶乘
 */
int FactorialRecursion(int n);
int Factorial(int n);

/*
 q7.
 递归方式实现打印一个整数的每一位
 */
void ShowdataRecursion(int n);


#endif /* _6_h */
