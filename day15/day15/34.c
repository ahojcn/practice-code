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
