#include <stdio.h>

int num[10004];
int main(int argc, const char * argv[])
{
    int n = 0, i = 0;
    int max = 10003, min = -10003, sum = 0;
    
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &num[i]);
    }
    for(i=0; i<n; i++)
    {
        if(num[i] > max)
        {
            max = num[i];
        }
        if(num[i] < min)
        {
            min = num[i];
        }
        sum += num[i];
    }
    printf("%d\n%d\n%d", max, min, sum);
    
    return 0;
}
