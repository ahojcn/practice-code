// 输入三个整数，输出他们的平均值
// 要求保留三位小数
#include <stdio.h>

int main()
{
    int x=0, y=0, z=0;
    double ave = 0;
    scanf("%d%d%d", &x, &y, &z);
    ave = (x+y+z)/3;
    printf("%.3lf\n", ave);
    
    return 0;
}
