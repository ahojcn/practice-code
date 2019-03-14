#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int int_cmp(const void *p1, const void *p2)
{
//    return (*(int *)p1 < *(int *)p2); //这样只对正整数有效
    int x = *(int *)p1;
    int y = *(int *)p2;
    if(x < y)
        return -1;
    else if(x == y)
        return 0;
    else
        return 1;
}

int dou_cmp(const void *p1, const void *p2)
{
    int x = *(double *)p1;
    int y = *(double *)p2;
    if(x > y)
    {
        return 1;
    }
    else if(x < y)
    {
        return -1;
    }
    else
        return 0;
}

int CmpStr(const void *x, const void *y)
{
    assert(x && y);
    char **_x = (char **)x;
    char **_y = (char **)y;
    return strcmp(*_x, *_y);
}

void swap(void *p1, void *p2, int size)
{
    for(int i=0; i<size; i++)
    {
        char tmp = *((char *)p1+i);
        *((char *)p1+i) = *((char *)p2+i);
        *((char *)p2+i) = tmp;
    }
}

void
myqsort(void *base,
        int len,
        int width,
        int (*cmp)(void *p1, void *p2))
{
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len-1-i; j++)
        {
            if( cmp((char *)base+j*width,(char *)base+(j+1)*width) > 0 )
            {
                swap((char *)base+j*width,
                     (char *)base+(j+1)*width,
                     sizeof(int));
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int arr[] = {11,33,22,-11,-22,-300,32,0};
    
    qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(int), int_cmp);
    
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    double darr[] = {1.2,1.3,-0.005,3.0001,3.0000002};
    qsort(darr, sizeof(darr)/sizeof(darr[0]), sizeof(double), dou_cmp);
    
    for(int i=0; i<sizeof(darr)/sizeof(darr[0]); i++)
    {
        printf("%lf ", darr[i]);
    }
    printf("\n");
    
    return 0;
}
