/*
 4.
 有一个字符数组的内容为:"student a am i",
 请你将数组的内容改为"i am a student".
 要求：
 不能使用库函数。
 只能开辟有限个空间（空间个数和字符串的长度无关）。
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int my_strlen(const char *str)
{
    assert(str != NULL);
    
    int count = 0;
    while(*str++ != '\0')
    {
        count++;
    }
    
    return count;
}

char* fun(char *str_final, const char *str_src)
{
    assert(str_src != NULL);
    
    int str_len_src = my_strlen(str_src);
    char *tmp = (char *)malloc(sizeof(char)*str_len_src);
    for(int i=str_len_src-1; i>=0; i--)
    {
        
    }
    
    return str_final;
}

int main()
{
    char *str_src = "student a am i";
    char *str_final = NULL;
    
    printf("%s\n", fun(str_final, str_src));
    
    return 0;
}

