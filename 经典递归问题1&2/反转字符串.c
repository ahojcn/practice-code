// 反转串
// 例如：abc  ->  cba

#include <stdio.h>
#include <string.h>

void ReverseString(char *p)
{
    int length = strlen(p);
    if(length <= 1)
    {
        return;
    }
    else
    {
        char tmp = p[0];
        p[0] = p[length-1];
        p[length-1] = '\0';
        ReverseString(p+1);
        p[length-1] = tmp;
    }
}

int main()
{
	char p[] = "abcd";
    ReverseString(p);
    printf("%s\n", p);
	return 0;
}
