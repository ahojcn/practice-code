//
//  main.c
//  10_29_4
//
//  Created by hanoi_ahoj on 2018/10/31.
//  Copyright © 2018 hanoi_ahoj. All rights reserved.
//

#include <stdio.h>

int dfs(int n)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }
    return dfs(n-1) + dfs(n-2);
}

int main(int argc, const char * argv[])
{
    printf("%d\n", dfs(4));
    
    
    return 0;
}
