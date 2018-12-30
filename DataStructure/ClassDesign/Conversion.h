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
} NumType;

typedef struct Answer {
    NumType a_input_num_type;   // 输入的是几进制数
    char a_bin[MAXLENGTH];
    char a_oct[MAXLENGTH];
    char a_dec[MAXLENGTH];
    char a_hex[MAXLENGTH];
} Answer;

// 2/8/16 -> 10，返回十进制数
int AllToDec(const char *str, const int power);
// 10->2，返回字符串
char *DecToAll (const int dec, const int power);

#endif //CLASSDESIGN_CONVERSION_H
