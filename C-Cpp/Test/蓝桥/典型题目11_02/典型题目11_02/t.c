//
//  t1.c
//  典型题目11_02
//
//  Created by hanoi_ahoj on 2018/11/2.
//  Copyright © 2018 hanoi_ahoj. All rights reserved.
//

#include <stdio.h>
#include "t.h"
#define up(c) ((c)>='a'&&(c)<='z' ? (c+'A'-'a') : (c))
#define down(c) ((c)>='A'&&(c)<='Z' ? (c+'a'-'A') : (c))

// 水仙花数
int pow3(int n)
{
    return n*n*n;
}
void t1()
{
    for(int num=153; num<10000; num++)
    {
        int sum = 0;
        int tmp = num;
        while(tmp)
        {
            sum += pow3(tmp%10);
            tmp /= 10;
        }
        
        if(sum == num)
        {
            printf("%d,", num);
        }
        
    }/* for */
    
    printf("\n");
}


// 大写转小写 小写转大写
void t2()
{
    char c = 0;
    while((c=getchar()) != EOF)
    {
        if(c>='a' && c<='z')
        {
            printf("%c", up(c));
            //printf("%c", c + 'A'-'a');
        }
        if(c>='A' && c<='Z')
        {
            printf("%c", down(c));
            //printf("%c", c + 'a'-'A');
        }
    }
    printf("\n");
}


// 统计字符串中 子母 数字 以及其他符号的个数
void t3()
{
    char ch = 0;
    int en = 0;
    int num = 0;
    int ot = 0;
    while((ch=getchar()) != EOF)
    {
        if(ch>='0' && ch<='9')
        {
            num++;
        }
        else if((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z'))
        {
            en++;
        }
        else
        {
            ot++;
        }
    }
    printf("%d, %d, %d\n", en, num, ot);
    
    
}
