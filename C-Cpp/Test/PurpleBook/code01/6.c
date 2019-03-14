/*
 三角形
 输入：三角形3条边的长度值(均为正整数)
 输出：如果可以构成三角形，输出yes，如果否，输出not a triangle
 */

#include <stdio.h>

int main()
{
    int x=0, y=0, z=0;
    scanf("%d%d%d", &x, &y, &z);
    if((x+y<z) || (x+z<y) || (y+z<x))
    {
        printf("not a triangle\n");
    }
    else
    {
        printf("yes\n");
    }
    
    return 0;
}
