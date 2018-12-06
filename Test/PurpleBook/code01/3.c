// 输入正整数n，输出 1+2+...+n的值。

#include <stdio.h>

int main()
{
    int n = 0;
    int sum = 0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        sum += i;
    }
    printf("%d\n", sum);
    
    return 0;
}
