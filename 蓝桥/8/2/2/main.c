//
//  main.c
//  2
//
//  Created by hanoi_ahoj on 2018/10/31.
//  Copyright © 2018 hanoi_ahoj. All rights reserved.
//

#include <stdio.h>

int isPrime(int n)
{
    for(int i=n-1; i>2; i--)
    {
        if(n%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    for(int start=1; start<1000; start++)
    {
        for(int gongcha=1; gongcha<1000; gongcha++)
        {
            int len = 10;
            int prime = start;
            while(len--)
            {
                if(!isPrime(prime))
                {
                    break;
                }
                
                prime = prime + gongcha;
                
                if(len == 0)
                {
                    printf("%d\n", gongcha);
                    return 0;
                }
                
            }
        }
    }
    
    return 0;
}




//
//int isPrime(int n)
//{
//    for (int i = 2; i <= n - 1; i++)
//    {
//        if (n * 1.0 / i - n / i == 0)
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//int main()
//{
//    for (int start = 1; start <= 100000; start++)   // 暴力开始的地方
//    {
//        for (int tol = 1; tol <= 10000; tol++)  // 公差 1-10000
//        {
//            int countTol = 10;  // 设置长度为10
//            int primeTemp = start;  //
//            while (countTol--)  // 公差一直减
//            {
//                if (!isPrime(primeTemp))    // 如果这个数不是素数就退出公差计算这层循环
//                {
//                    break;
//                }
//
//                primeTemp += tol;   // 素数 = 素数+公差
//
//                if (countTol == 0)  // 如果公差减为0，则找到了，打印并退出
//                {
//                    printf("start: %d\ntol: %d", start, tol);
//                    printf("\n");
//                    return 0;
//                }
//            }
//        }
//    }
//
//    return 0;
//}
