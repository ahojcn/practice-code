//
//  main.c
//  铺地砖问题
//
//  Created by hanoi_ahoj on 2018/10/31.
//  Copyright © 2018 hanoi_ahoj. All rights reserved.
//

#include <stdio.h>

int digui(int n)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }
    
    return digui(n-1) + digui(n-2);
}

int main(int argc, const char * argv[])
{
    int N = 4;
    
    printf("%d\n", digui(N));
    
    return 0;
}
