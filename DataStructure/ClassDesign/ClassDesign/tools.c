#include "tools.h"

void Init(Ans **ppans)
{
    assert(ppans != NULL);
    (*ppans)->org = 0;  // 默认为0
    
    (*ppans)->ans_bin = (char *)malloc(sizeof(char) * MAXLEN);
    (*ppans)->ans_oct = (char *)malloc(sizeof(char) * MAXLEN);
    (*ppans)->ans_dec = (char *)malloc(sizeof(char) * MAXLEN);
    (*ppans)->ans_hex = (char *)malloc(sizeof(char) * MAXLEN);
}

void Destory(Ans **ppans)
{
    assert(ppans != NULL);
    free((*ppans)->ans_bin);
    free((*ppans)->ans_oct);
    free((*ppans)->ans_dec);
    free((*ppans)->ans_hex);
    (*ppans)->ans_bin = NULL;
    (*ppans)->ans_oct = NULL;
    (*ppans)->ans_dec = NULL;
    (*ppans)->ans_hex = NULL;
}

void ShowAns(const Ans *pans)
{
    assert(pans != NULL);
    printf("2>  %s\n", pans->ans_bin);
    printf("8>  %s\n", pans->ans_oct);
    printf("10> %s\n", pans->ans_dec);
    printf("16> %s\n", pans->ans_hex);
}

void DealInput(Ans **ppans)
{
    assert(ppans != NULL);
    char input[MAXLEN] = {0};
    puts("input>");
    scanf("%s", input);
    size_t len = strlen(input);
    switch(input[len-1])
    {
        case BIN:
            (*ppans)->org = 2;
            memcpy((*ppans)->ans_bin, input, len);
            break;
        case OCT:
            (*ppans)->org = 8;
            memcpy((*ppans)->ans_oct, input, len);
            break;
        case DEC:
            (*ppans)->org = 10;
            memcpy((*ppans)->ans_dec, input, len);
            break;
        case HEX:
            (*ppans)->org = 16;
            memcpy((*ppans)->ans_hex, input, len);
            break;
            
        default:
            break;
    }
    
}
