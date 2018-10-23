
#include "07.h"

int main(int argc, const char * argv[])
{
    //q1();
    
    /*
    int x = 0, y = 0;
    scanf("%d%d", &x, &y);
    q2(&x, &y);
    printf("%d %d", x, y);
     */
    
    /*
    int year = 0;
    scanf("%d",&year);
    if (q3(year))
    {
        printf("%d年是闰年",year);
    }
    else
    {
        printf("%d年不是闰年",year);
    }
    */
    
    /*
    int arr[10] = {0};
    EmptyArr(arr, sizeof(arr)/sizeof(arr[0]));
    PrintArr(arr, sizeof(arr)/sizeof(arr[0]));
    InitArr(arr, sizeof(arr)/sizeof(arr[0]));
    PrintArr(arr, sizeof(arr)/sizeof(arr[0]));
    ReverseArr(arr, sizeof(arr)/sizeof(arr[0]));
    PrintArr(arr, sizeof(arr)/sizeof(arr[0]));
    */
    
    int n = -1;
    scanf("%d",&n);
    if (q5(n))
    {
        printf("%d是素数",n);
    }
    else
    {
        printf("%d不是素数",n);
    }
    
    
    return 0;
}
