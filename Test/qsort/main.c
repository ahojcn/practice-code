//
//  qsort
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int CmpInt(const void *x, const void *y)
{
    int _x = *(int *)x;
    int _y = *(int *)y;
    if(_x > _y)
    {
        return 1;
    }
    else if(_x == _y)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int CmpStr(const void *x, const void *y)
{
    assert(x && y);
    char **_x = (char **)x;
    char **_y = (char **)y;
    return strcmp(*_x, *_y);
}

void DisplayInt(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void DisplayStr(char **str, int num)
{
    for(int i=0; i<num; i++)
    {
        printf("%s ", *(str + i));
    }
    printf("\n");
}

void swap(void *x, void *y, int size)
{
    for (int i = 0; i < size; i++)
    {
        *((char*)x + i) ^= *((char*)y + i);
        *((char*)y + i) ^= *((char*)x + i);
        *((char*)x + i) ^= *((char*)y + i);
    }
}

void MyQsort_PopSort(
                     void *base,
                     int cnt,
                     int size,
                     int (*cmp)(const void*, const void*)
                     )
{
    for(int i=0; i<cnt; i++)
    {
        for(int j=0; j<cnt-i-1; j++)
        {
            if(cmp( (char*)base+j*size, (char*)base+(j+1)*size) > 0)
            {
                swap(
                     (char*)base+j*size,
                     (char*)base+(j+1)*size,
                     size);
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int arr[] = { 1,7,8,-2,-111,-0,0,123,321,123,-123 };
    int size = sizeof(arr)/sizeof(arr[0]);
    DisplayInt(arr, size);
    //qsort(arr, size, sizeof(int), CmpInt);
    //DisplayInt(arr, size);
    
    char *str[] = {"d", "cc", "aaa", "bbbb"};
    int num = sizeof(str)/sizeof(str[1]);
    DisplayStr(str, num);
    //qsort(str, num, sizeof(char*), CmpStr);
    //DisplayStr(str, num);
    
    printf("--------------------\n");
    
    MyQsort_PopSort(arr, size, sizeof(int), CmpInt);
    DisplayInt(arr, size);
    
    MyQsort_PopSort(str, num, sizeof(char*), CmpStr);
    DisplayStr(str, num);
    
    return 0;
}
