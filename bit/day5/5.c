/*
 1.完成猜数字游戏。
 2.写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回-1.（折半查找）
 3.编写代码模拟三次密码输入的场景。
 最多能输入三次密码，密码正确，提示“登录成功”,密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。
 4.编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 1.猜数字游戏
void t_1()
{
    while(1)
    {
        printf("******************\n");
        printf("****猜数字游戏****\n");
        printf("****  1.play  ****\n");
        printf("****  0.exit  ****\n");
        printf("******************\n>");
        int chose = 0;
        scanf("%d",&chose);
        switch (chose)
        {
            case 1:
            {
                int n = (rand()%100+1);
                printf("我已经准备好了一个1～100的随机数，猜猜它是\n>");
                int input = 0;
                while (1)
                {
                    scanf("%d",&input);
                    if (input > n)
                    {
                        printf("大了\n>");
                    }
                    else if(input < n)
                    {
                        printf("小了\n>");
                    }
                    else
                    {
                        printf("666\n");
                    }
                }
                break;
            }
            case 0:
            {
                printf("Bye!\n");
                exit(0);
            }
            default:
            {
                printf("选择有误，请重新选择:\n");
                break;
            }
        }
    }
}

int binary_search(int arr[], int key, int left, int right)
{
    while (left<right)
    {
        int mid = left+(right-left)/2;
        if(key > arr[mid])
        {
            left = mid+1;
        }
        else if(key < arr[mid])
        {
            right = mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

// 2.写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回-1.（折半查找）
void t_2()
{
    int arr[10] = { 0 };
    for (int i=0; i<10; i++)
    {
        arr[i] = i;
    }
    int left = 0;
    int right = sizeof(arr)/sizeof(arr[0])-1;
    int ans = binary_search(arr, 3, left, right);
    if (ans == -1)
    {
        printf("抱歉,没有你要找的数\n");
    }
    else
        printf("找到了,你要找的数字下标为%d\n",ans);
}

//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”,密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。
void t_3()
{
    char * password = (char *)malloc(20);
    password = "ahoj";
    char * input = (char *)malloc(20);
    int cnt = 3;
    while (cnt!=0)
    {
        printf("please input password:>");
        --cnt;
        scanf("%s",input);
        if (0 == strcmp(password, input))
        {
            printf("OK!\n");
            break;
        }
        else
        {
            printf("wrong password!\n");
        }
    }
}

//4.编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。
void t_4()
{
    // A~Z  65~90
    // a~z  97~122
    // 0~9  48~57
    char ch;
    while ((ch=getchar()) != '$')
    {
        if ( ch>=65 && ch<=90 )
        {
            printf("%c\n",ch+32);
        }
        else if( ch>=97 && ch<=122 )
        {
            printf("%c\n",ch-32);
        }
        else if( ch>=48 && ch<=57 )
        {
            ;
        }
    }
}

int main()
{
    while(1)
    {
        printf("1.猜数字\n2.折半查找\n3.密码输入\n4.大小写转换\n0.exit\n");
        int n = -1;
        scanf("%d",&n);
        switch (n)
        {
            case 1:
                srand((unsigned)time(NULL));
                t_1();
                break;
            case 2:
                t_2();
                break;
            case 3:
                t_3();
                break;
            case 4:
                t_4();
                break;
            case 0:
                exit(0);
                break;
                
            default:
                printf("error!\n");
                break;
        }
    }
    
    return 0;
}





