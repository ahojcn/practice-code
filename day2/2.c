/*
 作业：
 1. 给定两个整形变量的值，将两个值的内容进行交换。
 2. 不允许创建临时变量，交换两个数的内容（附加题）
 3. 求10 个整数中最大值。
 4. 将三个数按从大到小输出。
 5. 求两个的最大公约数
 */

#include <stdio.h>

void t_1()
{
    int a = 1,b = 11;
    int temp;
    printf("a = %d,b = %d\n",a,b);
    temp = a;
    a = b;
    b = temp;
    printf("a = %d,b = %d\n",a,b);
}

void t_2()
{
    int x = 2,y = 22;
    printf("x = %d,y = %d\n",x,y);
    x=x^y;
    y=x^y;
    x=x^y;
    printf("x = %d,y = %d\n",x,y);
}

void t_3()
{
    int arr[10] = {1,60,20,31,55,27,99,1001,0,60};
    int max = arr[0];
    for (int i=0; i<10; i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
    }
    printf("max = %d\n",max);
}

void t_4()
{
    int arr[3] = {101,202,55};
    for (int i=0; i<2; i++)
    {
        int temp;
        if (arr[i] < arr[i+1])
        {
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    
    printf("%d > %d > %d\n",arr[0],arr[1],arr[2]);
}

void t_5()
{
    int a = 15, b = 9;
    int max_num = -1;   //error
    int i=2;
    while (i<=a && i<=b)
    {
        if (a%i==0 && b%i==0)
        {
            max_num = i;
        }
        i++;
    }
    printf("%d,%d的最大公约数是%d\n",a,b,max_num);
    
}

int main()
{
    printf("1.给定两个整形变量的值，将两个值的内容进行交换\n");
    t_1();
    
    printf("2.不允许创建临时变量，交换两个数的内容（附加题）\n");
    t_2();
    
    printf("3.求10个整数中最大值\n");
    t_3();
    
    printf("4.将三个数按从大到小输出\n");
    t_4();
    
    printf("5.求两个的最大公约数\n");
    t_5();
    
    return 0;
}
