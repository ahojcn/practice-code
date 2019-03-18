#include <stdio.h>
#include <string.h>
#include <math.h>

/*
 在屏幕上输出以下图案：
       *
      ***
     *****
    *******
   *********
  ***********
 *************
  ***********
   *********
    *******
     *****
      ***
       *
*/

void t_1()
{
    char str[] = "             ";  //
    
    int i = 0,j = 0;
    for ( i=(strlen(str)/2),j=(strlen(str)/2); i>=0 && j<=strlen(str); i--,j++ )
    {
        str[i] = '*';
        str[j] = '*';
        printf("%s\n",str);
    }
    for ( i=0,j=(strlen(str)-1); i<(strlen(str)/2) && j>=(strlen(str)/2); i++,j-- )
    {
        str[i] = ' ';
        str[j] = ' ';
        printf("%s\n",str);
    }
    
    
    int line = 0;
    i = 0;
    scanf("%d", &line);//7
    //1. 打印上半部分
    for(i=0; i<line; i++)
    {
        //打印一行
        //1. 打印空格
        int j = 0;
        for(j=0; j<line-1-i; j++)
        {
            printf(" ");
        }
        //2. 打印*
        for(j=0; j<2*i+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    //2. 打印下半部分
    for(i=0; i<line-1; i++)
    {
        //打印一行
        //1. 打印空格
        int j = 0;
        for(j=0; j<i+1; j++)
        {
            printf(" ");
        }
        //2. 打印*
        for(j=0; j<2*(line-1-i)-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    
}

/*
 2.求出0～999之间的所有“水仙花数”并输出。“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3?，则153是一个“水仙花数”。
 在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），是指一N位数，其各个数之N次方和等于该数。
 例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
 153 = 1^3 + 5^3 + 3^3。
 370 = 3^3 + 7^3 + 0^3。
 371 = 3^3 + 7^3 + 1^3。
 407 = 4^3 + 0^3 + 7^3。
 */
void t_2()
{
    /*
    for (int i=100; i<=999; i++)
    {
        int t = pow(i%10,3) + pow(i/10%10,3) + pow(i/100,3);
        if (t == i)
        {
            printf("%d ",i);
        }
    }*/
    for (int i=0; i<=999; i++)
    {
        // 1.确定位数
        int cnt = 1;
        int sum = 0;
        int temp = i;
        while(temp > 9)
        {
            cnt++;
            temp /= 10;
        }
        // 2.计算次方和
        temp  = i;
        while(temp)
        {
            sum += pow(temp%10,cnt);
            temp /= 10;
        }
        // 3.判断打印
        if (sum == i)
        {
            printf("%d,",i);
        }
    }
    
}

/*
 3.
 求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，例如：2+22+222+2222+22222
 */
int fun_3(int x,int n)  // n->几位数
{
    int sum = 0;
    for ( int i=0; i<n; i++ )
    {
        sum += x*pow(10,i);
    }
    return sum;
}

void t_3()
{
    int n=2;
    int sn=0;
    for (int i=1; i<=5; i++)
    {
        sn += fun_3(n,i);
        //printf("%d\n",fun_3(n,i));
    }
    printf("%d\n",sn);
}

/*
 4.编写一个程序，它从标准输入读取C源代码，并验证所有的花括号都正确的成对出现。
 */
void t_4()
{
    char ch[1024] = {0};
    scanf("%s",ch);
    int flag_left = 0;
    int flag_right = 0;
    
    for (int i=0; i<=strlen(ch); i++)
    {
        if (ch[i]=='{')
        {
            flag_left++;
        }
        if (ch[i]=='}')
        {
            flag_right++;
        }
    }
    if (flag_left == flag_right)
    {
        printf("成对出现，有%d对\n",flag_left);
    }
    else
    {
        printf("未成对出现\n'{'有%d个\n'}'有%d个\n",flag_left,flag_right);
    }
}

int main()
{
    // 1.
    t_1();
    
    // 2.
    t_2();
    printf("\n");
    
    // 3.
    t_3();
    
    // 4.
    t_4();
    
    return 0;
}

