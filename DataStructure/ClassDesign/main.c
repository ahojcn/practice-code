#include "Conversion.h"
#include <string.h>
#include <ctype.h>

typedef enum MenuSelect {
    EXIT = 0,
    NULLDECIMAL = 1,    // 选择，无小数
    DECIMAL = 2,        // 有小数
} MenuSelect;

void ShowAnswer(
        const char *bin,
        const char *oct,
        const char *dec,
        const char *hex
);
void Menu(void );
char *GetInput(void );
void NullDecimal (char *input); // 处理无小数的输入

int main()
{
    while (1) {
        Menu();
        printf("select>");
        MenuSelect ms = EXIT;
        scanf("%d", &ms);
        char *input = NULL;
        switch(ms) {
            case NULLDECIMAL:   // 无符号小数
                input = GetInput();
                NullDecimal(input);
                break;
            case DECIMAL:{
                input = GetInput();
                //
                break;
            }

            case EXIT:
            default:
                exit(0);    // 正常退出
                break;
        }
    }

    return 0;
}

void Menu(void ) {
    printf("##################\n");
    printf("##  1. 无小数\t##\n");
    printf("##  2. 带小数\t##\n");
    printf("##  0. 退出\t\t##\n");
    printf("##################\n");
}

void NullDecimal (char *input) {
    assert(input != NULL);

    char *b = NULL;
    char *o = NULL;
    char *d = NULL;
    char *h = NULL;
    Answer ans;
    // 判断输入的是几进制的数,做相应的转换
    switch(input[strlen(input)-1]) {
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

    ShowAnswer(b, o, d, h);
}

char *GetInput (void) {
    char *input = (char *)malloc(MAXLENGTH);
    printf("input>");
    scanf("%s", input);

    // 将输入的 input 转为大写，如果是大写则不转换
    for (int i = 0; i < strlen(input); ++i) {
        if (islower(input[i])) {
            input[i] = (char)toupper(input[i]);
        }
    }
    return input;
}

void ShowAnswer(const char *bin, const char *oct, const char *dec, const char *hex) {
    assert(bin && oct && dec && hex != NULL);
    printf("-----answer-----\n");
    printf("bin: %s\n", bin);
    printf("oct: %s\n", oct);
    printf("dec: %s\n", dec);
    printf("hex: %s\n", hex);
    printf("-----answer-----\n");
}
