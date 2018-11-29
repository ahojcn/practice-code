// 5000 的阶乘

#include <stdio.h>
#include <time.h>

int main(int argc, const char * argv[])
{
    int a[20000] = {0};
    a[1] = 1;
    int n = 0;
    scanf("%d", &n);
    int i=0, j=0;
    int len = 1;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=len; j++)
        {
            a[j] *= i;
        }
        
        for(j=1; j<=len; j++)
        {
            if(a[j]<10)
            {
                continue;
            }
            int pos = j;
            while(pos<=len)
            {
                if(a[len]>9)
                {
                    len++;
                }
                a[pos+1] += a[pos]/10;
                a[pos] %= 10;
                pos++;
            }/* while */
            
        }/* for j */
        
    }/* for i */
    
    for(i=len; i>0; i--)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    //printf("time used = %.2f\n", (double)clock()/CLOCKS_PER_SEC);
    
    return 0;
}
