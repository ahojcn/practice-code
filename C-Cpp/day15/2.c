/*
 2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
 给20元，可以多少汽水。
 编程实现。
 */

#include "Header.h"

void t2()
{
    int money = 20;
    int cola = 0;
    int count = 0;
    
    while(money)
    {
        money -= 2;
        cola += 1;
        count += 1;
        if(cola%2 == 0)
        {
            cola -= 1;
            count++;
        }
    }
    
    printf("2: %d\n", count);
    
}
