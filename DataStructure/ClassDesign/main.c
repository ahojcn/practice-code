#include "Conversion.h"
#include <string.h>
#include <ctype.h>

void ShowAns(const Answer *ans);

int main()
{
    Answer ans; // 最终的结果将存在Ans中

    char input[MAXLENGTH] = {0};
    scanf("%s", input);
    size_t input_len = strlen(input);

    // 将输入的 input 转为大写，如果是大写则不转换
    for (int i = 0; i < input_len; ++i) {
        if (islower(input[i])) {
            input[i] = (char)toupper(input[i]);
        }
    }

    char *b = NULL;
    char *o = NULL;
    char *d = NULL;
    char *h = NULL;
    // 判断输入的是几进制的数,做相应的转换
    switch(input[input_len-1]) {
        case BIN:   // 输入为2进制 -> 转10进制 -> 转8、16进制
            ans.a_input_num_type = BIN;
            int bin_dec = AllToDec(input, 2);
//            printf("%d\n", bin_dec);
            b = DecToAll(bin_dec, 2);
            o = DecToAll(bin_dec, 8);
            d = DecToAll(bin_dec, 10);
            h = DecToAll(bin_dec, 16);
            break;

        case OCT:   // 输入为8进制  -> 转10进制 -> 转2、16进制
            ans.a_input_num_type = OCT;
            int oct_dec = AllToDec(input, 8);
//            printf("%d\n", oct_dec);
            b = DecToAll(oct_dec, 2);
            o = DecToAll(oct_dec, 8);
            d = DecToAll(oct_dec, 10);
            h = DecToAll(oct_dec, 16);
            break;

        case DEC:   // 输入为10进制  -> 转2、8、16进制
            ans.a_input_num_type = DEC;
            int dec_dec = AllToDec(input, 10);
//            printf("%d\n", dec_dec);
            b = DecToAll(dec_dec, 2);
            o = DecToAll(dec_dec, 8);
            d = DecToAll(dec_dec, 10);
            h = DecToAll(dec_dec, 16);
            break;

        case HEX:   // 输入为16进制 -> 转10进制 -> 转2、8进制
            ans.a_input_num_type = HEX;
            int hex_dec = AllToDec(input, 16);
//            printf("---%d\n", hex_dec);
            b = DecToAll(hex_dec, 2);
            o = DecToAll(hex_dec, 8);
            d = DecToAll(hex_dec, 10);
            h = DecToAll(hex_dec, 16);
            break;

        default:
            exit(1001); // 输入格式错误，退出程序
            break;
    }

    printf("bin:%s\n", b);
    printf("oct:%s\n", o);
    printf("dec:%s\n", d);
    printf("hex:%s\n", h);

    return 0;
}

