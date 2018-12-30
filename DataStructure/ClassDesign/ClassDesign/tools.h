#ifndef tools_h
#define tools_h

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAXLEN 20

typedef enum
{
    BIN = 'B',
    OCT = 'O',
    DEC = 'D',
    HEX = 'H',
} DataType;

typedef struct Ans
{
    int org;    // org代表的是输入的是哪个形式的数
    // org = 0(默认) / 2 / 8 / 10 / 16
    char *ans_bin;
    char *ans_oct;
    char *ans_dec;
    char *ans_hex;
} Ans;

// 初始化
void Init(Ans **ppans);
// 处理输入数据
void DealInput(Ans **ppans);
// 打印答案
void ShowAns(const Ans *pans);
// 销毁
void Destory(Ans **ppans);

#endif /* tools_h */
