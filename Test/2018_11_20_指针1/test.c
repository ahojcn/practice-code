#include <stdio.h>

int main()
{
    char str1[] = "Hello world!";
    char str2[] = "Hello world!";
    
    char *str3 = "Hello world!";
    char *str4 = "Hello world!";
    
    if(str1 == str2)
    {
        printf("str1 == str2\n");
    }
    else
    {
        printf("str1 != str2\n");
    }
    
    if(str3 == str4)
    {
        printf("str3 == str4\n");
    }
    else
    {
        printf("str3 != str4\n");
    }
    
    printf("&str1[0] = %p\n", &str1[0]);
    printf("&str2[0] = %p\n", &str2[0]);
    
    printf("str3 = %p\n", str3);
    printf("str4 = %p\n", str4);
    
    int arr[5] = {1,2,3,4,5};
    printf("sizeof(arr) -> %d\n", sizeof(arr));
    printf("sizeof(arr+0) -> %d\n", sizeof(arr+0));
    printf("sizeof(&arr) -> %d\n", sizeof(&arr));
    
    printf("arr -> %p\n", arr);
    printf("&arr -> %p\n", &arr);
    printf("arr+1 -> %p\n", arr+1);
    printf("&arr+1 -> %p\n", &arr+1);
    
    
    return 0;
}
