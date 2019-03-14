/*
 输入：年份
 输出：闰年yes 否则no
 */

#include <stdio.h>

int main()
{
    int year = 0;
    scanf("%d", &year);
    if((year%4==0 && year%100!=0) || year%400==0)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    
    return 0;
}
