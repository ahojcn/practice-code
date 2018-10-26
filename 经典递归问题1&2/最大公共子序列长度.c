// 求两个串的最大公共子序列的长度。递归求解
// 可解!

#include <stdio.h>
#include <string.h>

int MAX(int a, int b)
{
    return a>b?a:b;
}

int f(char *s1, char *s2)
{
    if (strlen(s1)*strlen(s2) == 0)
    {
        return 0;
    }
    if (s1[0] == s2[0])
    {
        return f(s1+1, s2+1) + 1;
    }
    else
    {
        return MAX(f(s1+1, s2), f(s1, s2+1));
    }
}

int main(int argc, const char * argv[])
{
    char *s1 = "abc";
    char *s2 = "xbacd";
    
    int ret = f(s1, s2);
    printf("%d\n", ret);
    
    return 0;
}
