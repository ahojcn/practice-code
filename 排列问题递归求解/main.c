// 求n个元素的全排列
// abc acb bac bca cab cba
#include <stdio.h>

void f(char data[], int length, int cur)
{
	if(cur==length)
		printf("%s\n", data);
	for(int i=cur; i<length; i++)
	{
		{	// 试探
			char tmp = data[i];
			data[i] = data[cur];
			data[cur] = tmp;
		}

		f(data, length, cur+1);

		{	// 回溯
			char tmp = data[i];
			data[i] = data[cur];
			data[cur] = tmp;
		}
	}
}

int main()
{
	char data[] = "abcd";
	int length = sizeof(data)/sizeof(data[0]) - 1;
	//printf("%d\n",length);
	f(data, length, 0);
	return 0;
}
