
//
// Created by hanoi_ahoj on 2019/1/2.
//

#include <stdio.h>

void fun(int a, int power)
{
    int tmp = a;
    int count = 0;
    char arr[100] = {0};
    while (tmp)
    {
        arr[count] = tmp % power;
        
        tmp /= power;
        
        arr[count] += '0';
        if (arr[count] > '9')
        {
            arr[count] += 7;
        }
        
        count ++;
    }
    
    printf("%s\n", arr);
}

int main()
{
    int a = 15;
    fun(a, 8);
    return 0;
}
