
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

// TODO: 销毁
void Destory(Ans **ppans);

int main()
{
    Ans *ans;
    Init(&ans);
    DealInput(&ans);
    ShowAns(ans);
    
    return 0;
}

void Init(Ans **ppans)
{
    assert(ppans != NULL);
    (*ppans)->org = 0;  // 默认为0
    (*ppans)->ans_bin = (char *)malloc(sizeof(char) * MAXLEN);
    (*ppans)->ans_oct = (char *)malloc(sizeof(char) * MAXLEN);
    (*ppans)->ans_dec = (char *)malloc(sizeof(char) * MAXLEN);
    (*ppans)->ans_hex = (char *)malloc(sizeof(char) * MAXLEN);
}

void ShowAns(const Ans *pans)
{
    assert(pans != NULL);
    printf("%s\n", pans->ans_bin);
    printf("%s\n", pans->ans_oct);
    printf("%s\n", pans->ans_dec);
    printf("%s\n", pans->ans_hex);
}

void DealInput(Ans **ppans)
{
    assert(ppans != NULL);
    char input[MAXLEN] = {0};
    scanf("%s", input);
    size_t len = strlen(input);
    switch(input[len-1])
    {
        case BIN:
            memcpy((*ppans)->ans_bin, input, len);
            break;
        case OCT:
            memcpy((*ppans)->ans_oct, input, len);
            break;
        case DEC:
            memcpy((*ppans)->ans_dec, input, len);
            break;
        case HEX:
            memcpy((*ppans)->ans_hex, input, len);
            break;
            
        default:
            break;
    }
}
