#include "mystring.h"

char * mystrcpy(char * dest, const char * src)
{
	assert(dest && src);

	char *tmp = dest;
	while (*tmp++ = *src++)
		;

	return dest;
}

char * mystrcat(char * s1, const char * s2)
{
	assert(s1 && s2);

	char *tmp = s1;
	while (*tmp++)
		;
	tmp--;

	while (*tmp++ = *s2++)
		;

	return s1;
}

// 在s1中查找s2第一次出现的位置，并返回这个地址
// 如果没有找到，返回NULL
char * mystrstr(const char * s1, const char * s2)
{
	assert(s1 && s2);

	while (*s1)
	{
		if (*s1 == *s2)
		{
			char *tmp1 = s1;
			char *tmp2 = s2;
			int flag = 1;
			while (*tmp2)
			{
				if (*tmp2++ != *tmp1++)
				{
					flag = 0;
				}
			}
			if (flag)
			{
				return s1;
			}
		}
		else
		{
			s1++;
		}
	}

	return NULL;
}

char * mystrchr(const char * s1, const int c)
{
	assert(s1);
	assert(c >= 0);
	
	while (*s1)
	{
		if (*s1 == c)
		{
			return s1;
		}
		else
		{
			s1++;
		}
	}

	return NULL;
}

int mystrcmp(const char * s1, const char * s2)
{
	while (*s1 && *s2)
	{
		if (*s1 > *s2)
		{
			return 1;
		}
		else if (*s1 < *s2)
		{
			return -1;
		}
		else 
		{
			return 0;
		}
	}
}

void * mymemcpy(void * dest, const void * src, int n)
{
	if (NULL == dest || NULL == src || n <= 0)
	{
		return NULL;
	}

	void *ret = dest;

	while (n--)
	{
		*((char *)dest)++ = *((char *)src)++;
	}

	return ret;
}

void * mymemmove(void * dest, const void * src, int len)
{
	if (NULL == dest || NULL == src || len <= 0)
	{
		return NULL;
	}

	void *ret = dest;

	if (src < dest)
	{
		while (len--)
		{
			*((char*)dest)++ = *((char*)src)++;
		}
	}
	else
	{
		(char*)dest += len - 1;
		(char*)src += len - 1;
		while (len--)
		{
			*((char*)dest)++ = *((char*)src);
		}
	}

	return ret;
}

