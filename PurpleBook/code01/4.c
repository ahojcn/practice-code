// sin   cos
// 输入正整数n（n<360）
// 输出n度的正弦，余弦值。

#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("sin%d = %.3lf\n", n, sin(n*PI/180));
    printf("cos%d = %.3lf\n", n, cos(n*PI/180));
    
    return 0;
}
