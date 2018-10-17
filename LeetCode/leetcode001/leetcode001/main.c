//
//  main.c
//  leetcode001
//
//  Created by hanoi_ahoj on 2018/10/17.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

/*
 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
 */
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target);

int main(int argc, const char * argv[])
{
    int nums[10] = {3,2,3};
    int target = 6;
    twoSum(nums, sizeof(nums)/sizeof(nums[0]), target);
    return 0;
}

int* twoSum(int* nums, int numsSize, int target)
{
    int *ret = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i<numsSize; i++)
    {
        for (int j = i+1; j<numsSize; j++)
        {
            if (nums[j] == target - nums[i])
            {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return 0;
}
