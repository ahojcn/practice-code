//
//  main.c
//  10_29_2
//
//  Created by hanoi_ahoj on 2018/10/29.
//  Copyright © 2018 hanoi_ahoj. All rights reserved.
//

#include <stdio.h>

int count = 0;

void fun(int taijie, int bushu)
{
    if(taijie < 0)
    {
        return;
    }
    if(taijie == 0)
    {
        if(bushu%2 == 0)
        {
            count++;
        }
        return;
    }
    
    fun(taijie-1, bushu+1);
    fun(taijie-2, bushu+1);
}

int main(int argc, const char * argv[])
{
    fun(39, 0);
    
    printf("%d\n", count);
    
    return 0;
}
