/*
 1.实现一个函数，可以左旋字符串中的k个字符。
 ABCD左旋一个字符得到BCDA
 ABCD左旋两个字符得到CDAB
 
 2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
 例如：给定s1 =AABCD和s2 = BCDAA，返回1，给定s1=ABCD和s2=ACBD，返回0.
 
 AABCD左旋一个字符得到ABCDA
 AABCD左旋两个字符得到BCDAA
 AABCD右旋一个字符得到DAABC
 */

#include <stdio.h>
#include <string.h>

// 第一题第一种方法
/*
 将第一个第一个字符保存下来，把字符串向前挪一个位置，然后把第一个字符放在后面
 */
void t1_1()
{
    char str[100] = "ABCD";
    int k = 0;
    scanf("%d", &k);
    
    while(k)
    {
        char tmp = str[0];
        int i = 0;
        for(i=0; ; i++)
        {
            if(str[i] == '\0')
            {
                break;
            }
            else
            {
                str[i] = str[i+1];
            }
        }
        str[i-1] = tmp;
        
        k--;
    }
    printf("%s\n", str);
}

// 第一题第二种方法
/*
 将前k个字符串反转，将后面的字符串反转，然后将整个字符串反转
 */
void fun(char str[], int left, int right)
{
    while(left<right)
    {
        char tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        left++;
        right--;
    }
}
void t1_2()
{
    char str[100] = "ABCD";
    int len = strlen(str);
    int k = 0;
    scanf("%d", &k);
    
    while(k>len)    // 这里处理了一下k>字符串长度的情况
    {               // 这样就可以循环下去了
        k -= len;
    }
    
    fun(str, 0, k-1);
    fun(str, k, len-1);
    fun(str, 0, len-1);
    printf("%s\n", str);
}


// 第二题第一种方法
/*
 暴力枚举各种可能，然后比较
 */
void t2_1()
{
    char s1[100] = "AABCD";
    char s2[100] = "BCDAA";
    int flag = 0;
    for(int k = 1; k<strlen(s1); k++)
    {
        flag = 0;
        while(k)
        {
            char tmp = s1[0];
            int i = 0;
            for(i=0; ; i++)
            {
                if(s1[i] == '\0')
                {
                    break;
                }
                else
                {
                    s1[i] = s1[i+1];
                }
            }
            s1[i-1] = tmp;
            k--;
        }/* while */
        
        // 判断s1 s2是否相等
        if(0 == strcmp(s1, s2))
        {
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
            continue;
        }
    }/* for */
    
    if(1 == flag)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
}

// 第二题的第二种方法
/*
 将字符串1与字符串1连接，再判断字符串2是否为连接后的字符串1的子字符串
 */
void t2_2()
{
    char s1[100] = "AABCD";
    char s2[100] = "BCDAA";
    char s1s1[100] = {0};
    
    strcpy(s1s1, s1);
    strcat(s1s1, s1);
    
    if(strstr(s1s1, s2) != NULL)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
}

int main(int argc, const char * argv[])
{
    // 1.
    t1_1();
    t1_2();
    
    // 2.
    t2_1();
    t2_2();
    
    return 0;
}
