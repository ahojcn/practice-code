#include <stdio.h>
#define T1_MIN 100
#define T1_MAX 200
#define T3_MIN 1000
#define T3_MAX 2000

//输出100～200之间的素数
void t_1()
{
    for (int i=T1_MIN; i<=T1_MAX; i++)
    {
        int flag = 1;
        for (int j=2; j<i; j++)
        {
            if (i%j == 0)
            {
                flag = 0;
            }
        }
        if (flag)
        {
            printf("%d,",i);
        }
    }
}

//打印9*9乘法口诀表
void t_2()
{
    for (int i=1; i<=9; i++)
    {
        for (int j=1; j<=i; j++)
        {
            printf("%d*%d=%d ",i,j,i*j);
        }
        printf("\n");
    }
}

//1000～2000 输出闰年
void t_3()
{
    for (int i=T3_MIN; i<=T3_MAX; i++)
    {
        if ((i%4==0&&i%100!=0) || i%400==0)
        {
            printf("%d,",i);
        }
    }
}

int main()
{
    printf("1.100～200之间的素数\n");
    t_1();
    printf("\n");
    
    printf("2.9*9乘法口诀表\n");
    t_2();
    printf("\n");
    
    printf("3.1000～2000闰年\n");
    t_3();
    printf("\n");
    return 0;
}
