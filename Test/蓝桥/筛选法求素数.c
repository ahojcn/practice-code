//
//  main.c
//  筛法求素数
//
//  Created by hanoi_ahoj on 2018/10/30.
//  Copyright © 2018 hanoi_ahoj. All rights reserved.
//

#include<stdio.h>

int judge (int sum)
{
    int i;
    for(i=2; i*i<=sum; i++)
    {
        if(sum % i == 0)
        {
            return 0;
        }
    }
    
    return 1;
}

int main ()
{
    int sum, count = 0;
    sum = 2;
    
    while(count != 100002)
    {
        if(judge(sum) == 1)
            count ++;
        sum ++;
    }
    
    printf ("%d\n", --sum);
    
    return 0;
}
