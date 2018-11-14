/*
 1.一个数组中只有两个数字是出现一次，
 其他所有数字都出现了两次。
 找出这两个数字，编程实现。
 2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
 给20元，可以多少汽水。
 编程实现。
 3.模拟实现strcpy
 4.模拟实现strcat
 */
#include <stdio.h>
#include "Header.h"

int main(int argc, const char * argv[])
{
    // 1.
    int arr[10] = {1,2,3,4,5,5,4,9,10,13};
    FindNum(arr, sizeof(arr)/sizeof(arr[0]));
    
    
    
    
    return 0;
}
