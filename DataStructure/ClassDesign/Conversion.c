//
// Created by hanoi_ahoj on 2018/12/30.
//

#include "Conversion.h"

int AllToDec (const char *str, const int power) {
    assert(str != NULL);
    size_t len = strlen(str)-1;
    size_t mi = len-1;  // mi = len-1    // mi从0开始计算
    int ret = 0;
    for (int i = 0; i < len; ++i) {
        int t = str[i] - '0';   // 字符串转为数字

        if (t > 9){
            t = t - 7;    // 处理 ABCDEF 16进制的字母
        }

        ret += t*pow(power, mi); // t * power^mi
        mi--;
    }
    return ret;
}

char *DecToAll (const int dec, const int power) {
    // 才用除power取余，将余数压栈，最终将结果弹栈并转为字符串
    Stack s;
    StackInit(&s);
    int cp = dec;   //  临时的变量cp用来除2取余，不改变dec
    while (cp != 0) {
        int yushu = cp % power; //  取余
        StackPush(&s, yushu);   //  压栈
//        printf("%d ", yushu);
        cp = cp / power;        //  除power
    }
//    printf("<-raw\n");

    char *ret = (char *)malloc(MAXLENGTH);
    int i = 0;
    while (!StackEmpty(&s)) {
        int t = StackGetTop(&s);
        StackPop(&s);
        if (t > 9) {
            t = t + 7;  // 将 数字转换为 ABCDEF等字母
        }
        ret[i] = t + '0';
        i++;
    }
    ret[i] = '\0';
//    puts(ret);
    return ret;
}