// 输入华氏摄氏度f，输出对应的摄氏温度c
// 保留三位小数。    c=5(f-32)/9

#include <stdio.h>

int main()
{
    double f=0, c=0;
    scanf("%lf", &f);
    c=5*(f-32)/9;
    printf("%.3lf\n", c);
    
    return 0;
}
