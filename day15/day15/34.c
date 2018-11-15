/*
 3.模拟实现strcpy
 4.模拟实现strcat
 */

#include <stdio.h>
#include "Header.h"
#include <string.h>

char* my_strcpy(char *dest, const char *src)
{
    assert(src);
    assert(dest);
    
    char *ret = dest;
    
    while( (*dest++ = *src++) )
    {
        ;
    }
    
    return ret;
}

char *my_strcat(char *s1, const char *s2)
{
    assert(s1);
    assert(s2);
    
    char *tmp = s1;
    
    while( *s1 )
    {
        s1++;
    }
    
    while( (*s1++ = *s2++) )
    {
        ;
    }
    
    return tmp;
}

