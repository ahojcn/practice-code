/*
 4.
 有一个字符数组的内容为:"student a am i",
 请你将数组的内容改为"i am a student".
 要求：
 不能使用库函数。
 只能开辟有限个空间（空间个数和字符串的长度无关）。
 */

/*
 这个代码比较挫～
 以下代码的思路是：
 cur从字符串的最后一个往前走，每碰到一个空格就将走过的字符串赋给数组指针，并将这个空格变为'\0'
 最终的数组里就存的是所有字符串，打印即可。
 */

#include <stdio.h>
#include <assert.h>
#define MAX 10
// 求字符串长度
int my_strlen(const char *src)
{
    int count = 0;
    assert(src != NULL);
    
    while(*src != '\0')
    {
        src++;
        count++;
    }
    
    return count;
}

//字符串处理函数
int fun(char *arr[], char *src)
{
    char *head=NULL, *tail=NULL, *cur=NULL;
    int len = my_strlen(src);
    cur = &src[len-1];  // cur指向最有一个字符 i
    int i = 0;  // 计数
    while(cur != src)   // 当cur没有走到头时继续循环
    {
        if(*cur == ' ')
        {
            head = cur+1;
            tail = cur;
            arr[i++] = head;
            tail[0] = '\0';
        }
        else
        {
            cur--;
        }
    }
    
    // 循环出来后 cur就走到头了，还需要把第一个单词的首地址放在数组里
    arr[i] = cur;
    
    return i;   // 返回计数器的值，一共有几个单词
}


// 以下是第二种我在网上看到的比较棒的方法～来实现下子
/*
 1. 将整个字符串全部反转过来
 student a am i    ->    i ma a tneduts
 2. 然后开始反转单个单词
 i am a student
 */

void reverse(char *left, char *right)
{
    assert(left != NULL);
    assert(right != NULL);
    
    while(left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

char* fun2(char *src)
{
    char *ret = src;
    // 1. student a am i    ->    i ma a tneduts
    int len = my_strlen(ret);
    reverse(ret, ret+len-1);
    
    char *left=NULL, *right=NULL, *cur=ret;
    
    for(int i=0; i<len; i++)
    {
        left = cur;
        while((*cur!=' ') && (*cur!='\0'))
        {
            cur++;
        }
        // 碰到了空格
        right = cur-1;
        // 反转left->right之间的单词
        reverse(left, right);
        if(*cur == ' ')
        {
            cur++;
        }
    }
    
    return ret;
}



int main()
{
    char str[] = "student a am i";
    
    // 2
    printf("%s\n", fun2(str));
    
    
    // 1
    char *arr[MAX] = {0};
    
    int i = fun(arr, str);
    
    for(int j=0; j<=i; j++)
    {
        printf("%s ", arr[j]);
    }
    printf("\n");
    
    
    return 0;
}


