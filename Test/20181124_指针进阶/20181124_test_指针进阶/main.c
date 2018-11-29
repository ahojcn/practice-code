#include <stdio.h>

//void test(const char *str)
//{
//    printf("%s\n", str);
//}
//
//int main()
//{
//    // 函数指针pf
//    void (*pf)(const char *) = test;
//    
//    // 函数指针的数组pfarr
//    void (*pfarr[5])(const char *str);
//    pfarr[0] = test;
//    
//    // 指向函数指针数组pfarr的指针ppfarr
//    void (*(*ppfarr)[10])(const char *) = &pfarr;
//    
//    return 0;
//}

//int add(int a, int b)
//{
//    return a+b;
//}
//
//int sub(int a, int b)
//{
//    return a-b;
//}
//
//int mul(int a, int b)
//{
//    return a*b;
//}
//
//int diiv(int a, int b)
//{
//    return a/b;
//}
//
//int main()
//{
//    int x, y;
//    int input = 1;
//    int ret = 0;
//    int (*p[5])(int x, int y) = {0, add, sub, mul, diiv};   // 转移表
//    while(input)
//    {
//        printf("=========\n");
//        printf("( 1. +  )\n");
//        printf("( 2. -  )\n");
//        printf("( 3. *  )\n");
//        printf("( 4. \\  )\n");
//        printf("=========\n");
//        printf("choice>");
//        scanf("%d", &input);
//        if((input<=4 && input>=1))
//        {
//            printf("a b >");
//            scanf("%d%d", &x, &y);
//            ret = (*p[input])(x,y);
//        }
//        else
//        {
//            printf("error!");
//        }
//        printf("ret = %d\n", ret);
//    }
//
//    return 0;
//}


//int main()
//{
//    int x, y;
//    int input = 1;
//    int ret = 0;
//    while(input)
//    {
//        printf("=========\n");
//        printf("( 1. +  )\n");
//        printf("( 2. -  )\n");
//        printf("( 3. *  )\n");
//        printf("( 4. \\  )\n");
//        printf("=========\n");
//        printf("choice>");
//        scanf("%d", &input);
//        switch(input)
//        {
//            case 1:
//                printf("<(a b)>");
//                scanf("%d%d", &x, &y);
//                ret = add(x, y);
//                break;
//            case 2:
//                printf("<(a b)>");
//                scanf("%d%d", &x, &y);
//                ret = sub(x, y);
//            case 3:
//                printf("<(a b)>");
//                scanf("%d%d", &x, &y);
//                ret = mul(x, y);
//            case 4:
//                printf("<(a b)>");
//                scanf("%d%d", &x, &y);
//                ret = diiv(x, y);
//            default:
//                printf("error!\n");
//                break;
//        }
//        printf("ret = %d\n", ret);
//    }
//
//    return 0;
//}




//typedef void(*pfun_t)(int);
//pfun_t signal(int, pfun_t);


//void test()
//{
//    printf("test()\n");
//}
//int main()
//{
//    void (*pf1)();
//    void *pf2();
//    return 0;
//}


//int test()
//{
//    printf("ahoj\n");
//    return 0;
//}
//int main()
//{
//    printf("test    %p\n", test);
//    printf("&test   %p\n", &test);
//    test();
//
//    return 0;
//}


//void test(int **p)
//{
//    printf("%d\n", **p);
//}
//
//int main()
//{
//    int n = 10;
//    int *p = &n;
//    int **pp = &p;
//    test(&p);
//    test(pp);
//
//    return 0;
//}

//void print(int *p, int size)
//{
//    for(int i=0; i<size; i++)
//    {
//        printf("%d\n", *(p+i));
//    }
//}
//
//int main()
//{
//    int arr[10] = {1,2,3,4,5,6,7,8,9};
//    int *p = arr;
//    int size = sizeof(arr)/sizeof(arr[0]);
//    print(p, size);
//
//    return 0;
//}







//void test(int arr[3][5]){;} // ok
//void test(int arr[][]){;}   // error!
//void test(int arr[][5]){;}  // ok
//void test(int *arr){;}  // error!
//
//void test(int* arr[5]){;} // error!
//void test(int (*arr)[5]){;} // OK!
//void test(int **arr){;} // error!
//
//int main()
//{
//    int arr[3][5] = {0};
//    test(arr);
//
//    return 0;
//}





//void test11(int arr[])  // ok
//{
//    ;
//}
//void test12(int arr[10])    // ok
//{
//    ;
//}
//void test13(int *arr)   // ok
//{
//    ;
//}
//
//void test21(int *arr[20])   // ok
//{
//    ;
//}
//void test22(int **arr)  // ok
//{
//    ;
//}
//
//
//int main()
//{
//    int arr1[10] = {0};
//    int *arr2[20] = {0};  //// 数组指针
//    test11(arr1);
//    test12(arr1);
//    test13(arr1);
//
//    test21(arr2);
//    test22(arr2);
//
//    return 0;
//}







//void init_arr(int (*arr)[5], int row, int col)
//{
//    for(int i=0; i<row; i++)
//    {
//        for(int j=0; j<col; j++)
//        {
//            //arr[i][j] = i+j;
//            (*(arr + i))[j] = i+j;
//        }
//    }
//}
//
//void disp_arr(int (*arr)[5], int row, int col)
//{
//    for(int i=0; i<row; i++)
//    {
//        for(int j=0; j<col; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int main()
//{
//    int arr[3][5] = {0};
//
//    init_arr(arr, 3, 5);
//    disp_arr(arr, 3, 5);
//
//    return 0;
//}








//int main(int argc, const char * argv[])
//{
//    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
//    int (*p)[10] = &arr;
//
//    return 0;
//}
