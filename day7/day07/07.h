//
//  07.h
//  day07
//
//  Created by hanoi_ahoj on 2018/10/15.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#ifndef _7_h
#define _7_h
#include <stdio.h>

/*
 q1.
 实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
 输入9，输出9*9口诀表，输出12，输出12*12的乘法口诀表。
 */
void q1(void);

/*
 q2.
 使用函数实现两个数的交换。
 */
void q2(int *x, int *y);

/*
 q3.
 实现一个函数判断year是不是润年。
 如果是：返回 1
 如果否：返回 0
 */
int q3(int year);

/*
 q4.
 创建一个数组，
 实现函数init（）初始化数组、
 实现empty（）清空数组、
 实现reverse（）函数完成数组元素的逆置。
 要求：自己设计函数的参数，返回值。
 */
void InitArr(int arr[], int arr_size);
void EmptyArr(int arr[], int arr_size);
void ReverseArr(int arr[], int arr_size);
void PrintArr(int arr[], int arr_size);

/*
 q5.
 实现一个函数，判断一个数是不是素数。
 如果是：返回 1
 如果否：返回 0
 */
int q5(int n);


#endif /* _7_h */
