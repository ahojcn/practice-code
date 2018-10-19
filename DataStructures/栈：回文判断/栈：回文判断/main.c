//
//  main.c
//  栈：回文判断
//
//  Created by hanoi_ahoj on 2018/10/18.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include "Seq.h"

int main(int argc, const char * argv[])
{
    SeqStack S;
    Init(&S);
    char str[MAXSIZE] = {0};
    scanf("%s", str);
    
    int len = 0;
    int half = 0;
    while (str[len]!='\0')
    {
        len++;
    }
    
    half = len/2;
    
    int i = 0;
    for (i=0; i<half; i++)
    {
        Push(&S, str[i]);
    }
    if (len%2!=0)
    {
        i++;
    }
    
    // 判断
    int flag = 0;
    while (str[i]!='\0')
    {
        char e = 0;
        Pop(&S, &e);
        if (e == str[i])
        {
            if (S.top == -1)
            {
                flag = 1;
            }
            i++;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    
    if (flag)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    
    return 0;
}
