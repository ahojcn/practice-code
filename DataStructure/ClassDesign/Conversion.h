//
// Created by hanoi_ahoj on 2018/12/30.
//

#ifndef CLASSDESIGN_CONVERSION_H
#define CLASSDESIGN_CONVERSION_H

#include "Stack.h"
#include <math.h>
#include <string.h>

typedef enum NumType {
    BIN = 'B',
    OCT = 'O',
    DEC = 'D',
    HEX = 'H',
    POINT = '.',
} NumType;

typedef struct Answer {
    NumType a_input_num_type;   // 输入的是几进制数
    char *a_bin;
    char *a_oct;
    char *a_dec;
    char *a_hex;
} Answer;

/*   正数转换   */
// 2/8/16 -> 10，返回十进制数
int AllToDec(const char *str, const int power);
// 10->2/8/16，返回字符串
char *DecToAll (const int dec, const int power);

/*   小数转换   */
// 每一位乘以 power^[-1~POWER]的权位，相加
float DECIMAL_AllToDec(const char *str, const int power);
// 乘POWER取整，返回字符串
char *DECIMAL_DecToAll(const float dec, const int power);

#endif //CLASSDESIGN_CONVERSION_H
