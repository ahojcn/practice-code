/*
 1.模拟实现strncpy
 2.模拟实现strncat
 3.模拟实现strncmp
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>

char * my_stpncpy(char * dst, const char * src, size_t len);

char * my_strncat(char * s1, const char * s2, size_t n);

int my_strncmp(const char * s1, const char * s2, size_t n);

int main()
{
    const char * src = "abcdefg123";
    char dst[20] = "12345";
//    printf("%s\n", my_stpncpy(dst, src, 3));
//    printf("%s\n", strncpy(dst, src, 3));
//    printf("%s\n", strncat(dst, src, 3));
//    printf("%s\n", my_strncat(dst, src, 3));
    const char * s1 = "azc";
    const char * s2 = "aapp";
//    printf("%d\n", my_strncmp(s1, s2, 2));
    printf("%d\n", strncmp(s1, s2, 2));
    
    return 0;
}

char * my_stpncpy(char * dst, const char * src, size_t len)
{
    assert(dst);
    assert(src);
    assert(len>0);
    
    char * tmp = dst;
    int i = 0;
    for(i=0; i<len; i++)
    {
        *tmp++ = *src++;
    }
    
    return dst;
}

char * my_strncat(char * s1, const char * s2, size_t n)
{
    assert(s1);
    assert(s2);
    assert(n>=0);
    
    char * tmp = s1;
    while(*tmp != '\0')
    {
        tmp++;
    }
    while(n--)
    {
        *tmp++ = *s2++;
    }
    
    return s1;
}

int my_strncmp(const char * s1, const char * s2, size_t n)
{
    assert(s1);
    assert(s2);
    assert(n>0);
    
    int ret = 0;
    
    while(n--)
    {
        ret = (*s1++)-(*s2++);
    }
    
    return ret;
}

