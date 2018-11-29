//
//  main.c
//  1
//
//  Created by hanoi_ahoj on 2018/10/31.
//  Copyright © 2018 hanoi_ahoj. All rights reserved.
//

#include <stdio.h>
#include <assert.h>

int main()
{
    double x,y;
    double count=0;
    freopen("a.txt", "r", stdin); //stdin是标准输入 一般指键盘输入到缓冲区的东西

    while(scanf("%lf%lf",&x,&y) != EOF)
    {
        count += x*y/100;
    }
    printf("%lf\n", count);
    
    
    return 0;
}
