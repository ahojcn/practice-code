// 李白打酒

#include <stdio.h>

char c[16] = {0};
int sum = 0;

void fun(int now, int n, int d, int h)
{// now：斗中酒  n：遇到的店/花  d：店个数  h：花个数
    
    if(now<0 || n>16 || (now==0&&n<16))
    {
        return ;
    }
    if(now == 0)
    {
        if(n==16 && d==5 && h==10)
        {
            sum++;
            printf("sum:%d ", sum);
            printf("%s\n", c);
        }
    }
    
    c[n-1] = 'a';
    fun(now*2, n+1, d+1, h);
    c[n-1] = 'b';
    fun(now-1, n+1, d, h+1);
}

int main(int argc, const char * argv[])
{
    c[15] = '\0';
    
    fun(2, 1, 0, 0);
    
    return 0;
}
