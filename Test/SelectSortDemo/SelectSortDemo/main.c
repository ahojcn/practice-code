#include <stdio.h>

void SelectSort(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                <#statements#>
            }
        }
    }
}

int main()
{
    int arr[10] = {13,2,3,22,55};
    
    // 选择排序
    SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
    
    return 0;
}
