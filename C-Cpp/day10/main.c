// 1.
//写一个函数返回参数二进制中 1 的个数
//比如： 15       0000 1111 4个1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//    // 返回 1的位数
//}

// 2.
/*
 获取一个数二进制序列中所有的偶数位和奇数位，
 分别输出二进制序列。
 */

/*
 3. 输出一个整数的每一位。
 
 4.编程实现：
 两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
 输入例子:
 1999 2299
 输出例子:7
 */

#include <stdio.h>

int count_one_bits(unsigned int value)
{
    /* 1 */ // 缺点：负数没办法求
//    int cnt = 0;
//    while (value)
//    {
//        if (value%2 == 1)
//        {
//            cnt++;
//        }
//        value /= 2;
//    }
//    return cnt;
    
    /* 2 */ // 缺点：循环次数多
//    int cnt = 0;
//    for (int i=0; i<32; i++)
//    {
//        if ((value>>i) & 1)
//        {
//            cnt++;
//        }
//    }
//    return cnt;
    
    /* 3 */ // 难想到的一种方法
    int cnt = 0;
    while (value)
    {
        cnt++;
        value = value & (value - 1);
    }
    return cnt;
}

void t_2()
{
    int number = 11;
    int arr[32] = {0};
    int cnt = 0;
    int i = 0;
    while (number)
    {
        arr[i++] = number%2;
        number/=2;
        cnt++;
    }
    printf("odd:");     //奇数
    for (int j=cnt; j>=0; j-=2)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");
    printf("even:");    //偶数
    for (int j=cnt-1; j>=0; j-=2)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");
}


// 1234
// 1 234
// 1 2 34
// 1 2 3 4
void t_3(int n)
{
    if (n < 0)
    {
        n = -n;
    }
    if (n != 0)
    {
        t_3(n/10);
        printf("%d ",n%10);
    }
}

int t_4(int m, int n)
{
    // 相同为0 相异为1
    int tmp = m^n;
    
    return count_one_bits(tmp);
}

int main(int argc, const char * argv[])
{
    printf("1. %d\n", count_one_bits(15));
    
    t_2();
    
    t_3(1234);
    
    printf("\n4. %d\n", t_4(1, 3));
    return 0;
}
