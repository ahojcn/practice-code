#include <stdio.h>

void init_arr(int (*arr)[5], int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            //arr[i][j] = i+j;
            (*(arr + i))[j] = i+j;
        }
    }
}

void disp_arr(int (*arr)[5], int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[3][5] = {0};
    
    init_arr(arr, 3, 5);
    disp_arr(arr, 3, 5);
    
    return 0;
}








//int main(int argc, const char * argv[])
//{
//    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
//    int (*p)[10] = &arr;
//
//    return 0;
//}
