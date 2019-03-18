/*
 1.编写函数：
 unsigned int reverse_bit(unsigned int value);
 这个函数的返回值value的二进制位模式从左到右翻转后的值。
 
 如：
 在32位机器上25这个值包含下列各位：
 00000000000000000000000000011001
 翻转后：（2550136832）
 10011000000000000000000000000000
 程序结果返回：
 2550136832
 */

#include <stdio.h>
#include <math.h>

unsigned int reverse_bit(unsigned int value)
{
    int ret = 0;
    int tmp = 0;
    for(int i=0; i<32; i++)
    {
        tmp = ((value>>i)&1)*pow(2,31-i);
        ret += tmp;
    }
    
    return ret;
}

int main()
{
    printf("%u\n", reverse_bit(25));
    return 0;
}

