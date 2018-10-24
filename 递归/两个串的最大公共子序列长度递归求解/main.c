// 求两个串的最大公共子序列长度
// 可解但效率不高

#include <stdio.h>

int MAX(int a, int b)
{
    return a>b?a:b;
}

int f(char s1[], char s2[], int len1, int len2)
{
	if(len1 == 0 || len2 == 0)
	{
		return 0;
	}
	if(s1[0] == s2[0])
	{
		return f(++s1, ++s2, --len1, --len2);
	}
	else
	{
        int a = f(++s1, s2, len1, len2);
        int b = f(s1, ++s2, len1, len2);
        return MAX(a, b);
	}
}

int main()
{
	char s1[] = "abc";
	char s2[] = "xbacd";
	int len1 = sizeof(s1)/sizeof(s1[0]) - 1;
	int len2 = sizeof(s2)/sizeof(s2[0]) - 1;

	int ret = f(s1, s2, len1, len2);
	printf("%d\n", ret);
	return 0;
}
