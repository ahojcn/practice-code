//#include <stdio.h>

//int main()
//{
//    int i = 0;
//    int arr[10] = {0};
//    printf("&i = %p\n", &i);
//    for(i=0; i<10; i++)
//    {
//        arr[i] = 0;
//        //printf("test!\n");
//        printf("&arr[%d] = %p\n", i, &arr[i]);
//    }
//
//    return 0;
//}


//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char *str1 = "abc";
//    char str2[10] = "1234567890";
//
//    // 将str1中的字符拷贝到str2中
//    strcpy(str2, str1);
//    printf("str2 : %s\n", str2);
//
//    return 0;
//}


#include <stdio.h>

int main(int argc, const char * argv[])
{
    int num = 1;
    
    int test = 20;
    
    const int *p = &num;
    
    //*p = 30;
    p = &test;
    
    printf("%d\n", num);
    
    printf("*p = %d\n", *p);
    
    return 0;
}



