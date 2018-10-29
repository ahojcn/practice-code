/*
 1.
 调整数组使奇数全部都位于偶数前面。
 题目：
 输入一个整数数组，实现一个函数，
 来调整该数组中数字的顺序使得
 数组中所有的奇数位于数组的前半部分，
 所有偶数位于数组的后半部分。
 */

/*
 思路：
 left从数组的第一个元素开始，right从最后一个开始，
 当left<right 循环执行以下操作：
     left是奇数->left++
     right是偶数->right++
     left是偶数，right是奇数，将两个数交换
 */

/*
 2.
 //杨氏矩阵
 有一个二维数组.
 数组的每行从左到右是递增的，每列从上到下是递增的.
 在这样的数组中查找一个数字是否存在。
 时间复杂度小于O(N);
 
 数组：
 1 2 3
 2 3 4
 3 4 5
 
 1 3 4
 2 4 5
 4 5 6
 
 1 2 3
 4 5 6
 7 8 9
 */

/*
 要查找的数字为5
 思路：
 1 2 3
 2 3 4
 3 4 5
 从右上角的那个数字3开始，如果右上角的数字等于要查找的，返回1
 右上角数字 < 要查找的值：删除这一行
 右上角数字 > 要查找的值：删除这一列
 
 2 3 4
 3 4 5
 
 4<5
 
 3 4 5  找到了
 */

#include <stdio.h>
#define MAXSIZE 5

void t1(void );

int t2(int arr[][3], int row, int col, int value);

int main(int argc, const char * argv[])
{
    //t1();
    
    int arr[][3] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    if(t2(arr, 3, 3, 1))
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    return 0;
}

void t_1()
{
    int arr[MAXSIZE] = {0};
    
    for(int i=0; i<MAXSIZE; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int left=0, right=MAXSIZE-1;
    while(left < right)
    {
        if(arr[left]%2==0)
        {
            if(arr[right]%2!=0)
            {
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
            }
            else
            {
                right--;
            }
        }
        else
        {
            left++;
        }
    }
    
    for(int i=0; i<MAXSIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int t2(int arr[][3], int row, int col, int value)
{
    int ret = 0;
    
    // i,j为右上角坐标
    int i = 0;
    int j = col-1;
    while(i<row && j>=0)
    {
        if(value == arr[i][j])
        {
            ret = 1;
            break;
        }
        else if(arr[i][j] > value)
        {
            --j;
        }
        else
        {
            ++i;
        }
    }
    
    return ret;
}
