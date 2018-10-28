/*
 3.编程实现：
 一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
 请找出这个数字。（使用位运算）
 */

#include <stdio.h>

int main()
{
    int data[] = {1,1,2,2,3,3,4,4};
    
    for(int i=1; i<sizeof(data)/sizeof(data[0]); i++)
    {
        data[0] = data[0] ^ data[i];
    }
    
    printf("%d\n", data[0]);
    
    return 0;
}
