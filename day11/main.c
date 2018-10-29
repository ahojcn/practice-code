
#include <stdio.h>

void t_1(void);
void t_2(void);
void t_3(void);

int main(int argc, const char * argv[])
{
    t_1();
    t_2();
    t_3();
    return 0;
}

/*
 1.
 5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
 A选手说：B第二，我第三；
 B选手说：我第二，E第四；
 C选手说：我第一，D第二；
 D选手说：C最后，我第三；
 E选手说：我第四，A第一；
 比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
 */
void t_1()
{
    int a=0, b=0, c=0, d=0, e=0;
    for (a=1; a<=5; a++)
    {
        for (b=1; b<=5; b++)
        {
            for (c=1; c<=5; c++)
            {
                for (d=1; d<=5; d++)
                {
                    for (e=1; e<=5; e++)
                    {
                        if ((a==3 && b!=2) || (a!=3 && b==2))
                        {
                            if ((b==2 && e!=4) || (b!=2 && e==4))
                            {
                                if ((c==1 && d!=2) || (c!=1 && d==2))
                                {
                                    if ((c==5 && d!=3) || (c!=5 && d==3))
                                    {
                                        if ((e==4 && a!=1) || (e!=4 && a==1))
                                        {
                                            if (a*b*c*d*e == 120)
                                            {
                                                printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

/*
 2.
 日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
 嫌疑犯的一个。以下为4个嫌疑犯的供词。
 A说：不是我。
 B说：是C。
 C说：是D。
 D说：C在胡说
 已知3个人说了真话，1个人说的是假话。
 现在请根据这些信息，写一个程序来确定到底谁是凶手。
 */
void t_2()
{
    int murder;
    for (murder='A'; murder<='D'; murder++)
    {
        if (((murder!='A')+(murder=='C')+(murder=='D')+(murder!='D')) == 3)    //三真一假，在if语句的，括号里为真结果为1，要是假结果为0。因此if括号  后面若成立，必定为三真一假，即必定等于3.
        {
            printf("murder is %c\n",murder);     //由于最终要输出凶手，为一个字符，%c可用输出字符
        }
        
    }
}

/*
 3.在屏幕上打印杨辉三角。
 1
 1 1
 1 2 1
 1 3 3 1
 */
void t_3()
{
    int n=4,i,j;
    int a[31][31];
    for(i=0;i<30;i++)
    {
        a[i][0]=1;
        a[i][i]=1;
    }
    for(i=2;i<30;i++)
    {
        for(j=1;j<i;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    for (int i=0; i<n; i++)
    {
        int j=0;
        for (j=0; j<i; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("%d\n", a[i][j]);
    }
}
