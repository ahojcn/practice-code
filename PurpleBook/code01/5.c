/*
 一件衣服95元，若消费满300元，可打八五折。
 输入：够买衣服件数
 输出：需要支付的金额(元)，保留两位小数
 */

#include <stdio.h>
#define DISCOUNT 0.85

int main()
{
    int n = 0;
    double pay = 0;
    scanf("%d", &n);
    if(n*95 >= 300)
    {
        pay = n*95*DISCOUNT;
        printf("%.2lf\n", pay);
    }
    else
    {
        pay = n*95;
        printf("%.2lf\n", pay);
    }
    
    return 0;
}
