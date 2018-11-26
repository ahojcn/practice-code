#include <stdio.h>
#include <string.h>

// 二维数组
int main()
{
    int a[3][4] = {0};
    printf("-------\n");
    printf("%p -> a[0][0] -> %d\n", &a[0][0], a[0][0]);
    printf("%p -> a[3][4] -> %d\n", &a[3][4], a[3][4]);
    printf("&a[3][4] - &a[0][0] = %d\n", &a[3][4]-&a[0][0]);//一共有多少个元素
    printf("3 行 4 列\n");
    printf("-------\n");
    printf("%d\n", sizeof(a));//48，16个元素，每个元素占4个字节
    printf("%d\n", sizeof(a[0][0]));//4，第一个元素的大小
    printf("%d\n", sizeof(a[0]));//16，第一行元素的大小
    printf("%d\n", sizeof(a[0]+1));//8，a[0]是数组名，+1即为下一个元素的地址，a[0]+1 <=> a[0][1]
//    printf("%p\n", a[0]+1);
    printf("%d\n", sizeof(*(a[0]+1)));//4，a[0][1]的大小(int)
    printf("%d\n", sizeof(a+1));//8，第二个元素的地址，即&a[1]
    printf("%d\n", sizeof(*(a+1)));//16，第二行元素，相当于sizeof(a[1])
    printf("%d\n", sizeof(&a[0]+1));//8，第二行数组的地址，相当于a+1
    printf("%d\n", sizeof(*(&a[0]+1)));//16，相当于a[1]
    printf("%d\n", sizeof(*a));//16，相当于a[0]
    printf("%d\n", sizeof(a[3]));//16，虽然越界了，但是还是当前数组的类型
    
    
    return 0;
}

// 常量字符
//int main()
//{
//    char *p = "abcdef";
//    printf("--------\n");
//    printf("%p -> p[0] -> %c\n", &p[0], p[0]);
//    printf("%p -> p[1] -> %c\n", &p[1], p[1]);
//    printf("%p -> p[2] -> %c\n", &p[2], p[2]);
//    printf("%p -> p[3] -> %c\n", &p[3], p[3]);
//    printf("%p -> p[4] -> %c\n", &p[4], p[4]);
//    printf("%p -> p[5] -> %c\n", &p[5], p[5]);
//    printf("--------\n");
//    printf("%d\n", sizeof(p));//8，字符常量的地址
//    printf("%d\n", sizeof(p+1));//8，b字符的地址地址
////    printf("%c\n", *(p+1));
//    printf("%d\n", sizeof(*p));//1，首元素的大小
//    printf("%d\n", sizeof(p[0]));//1，首元素的大小
//    printf("%d\n", sizeof(&p));//8，字符常量的地址
//    printf("%d\n", sizeof(&p+1));//8，这个并不是字符b的地址，是\0后面元素的地址
//    printf("%d\n", sizeof(&p[0]+1));//8，字符b的地址大小
//    printf("---------\n");
//    printf("%d\n", strlen(p));//6，字符串长度
//    printf("%d\n", strlen(p+1));//5，从b开始往后数字符串的长度
////    printf("%d\n", strlen(*p));//ERROR!需要传入一个char *
////    printf("%d\n", strlen(p[0]));//ERROR!和上面一样
//    printf("%d\n", strlen(&p));//这个值是不确定的，p不是数组，传入后会从p的地址往后一个字节一个字节的找，遇到\0停下
//    printf("%d\n", strlen(&p+1));//不确定
//    printf("%d\n", strlen(&p[0]+1));//5，从字符b开始往后数
//
//
//    return 0;
//}



// 字符串
//int main()
//{
//    char a[] = "abcdef";
//        printf("----------\n");
//        printf("%p\t->\ta[0]\t->%c\n", &a[0], a[0]);
//        printf("%p\t->\ta[1]\t->%c\n", &a[1], a[1]);
//        printf("%p\t->\ta[2]\t->%c\n", &a[2], a[2]);
//        printf("%p\t->\ta[3]\t->%c\n", &a[3], a[3]);
//        printf("%p\t->\ta[4]\t->%c\n", &a[4], a[4]);
//        printf("%p\t->\ta[5]\t->%c\n", &a[5], a[5]);
//        printf("----------\n");
//        printf("sizeof(a)\t->\t%d\n", sizeof(a));//7，字符数组长度，算\0
//        printf("sizeof(a+0)\t->\t%d\n", sizeof(a+0));//8，第一个元素的地址
//        printf("sizeof(*a)\t->\t%d\n", sizeof(*a));//1，第一个元素的大小
//        printf("sizeof(a[1])\t->\t%d\n", sizeof(a[1]));//1
//        printf("sizeof(&a)\t->\t%d\n", sizeof(&a));//8，地址
//        printf("sizeof(&a+1)\t->\t%d\n", sizeof(&a+1));//8，地址（是'\0'后面的那个字符的地址）
//        printf("sizeof(&a[0]+1)\t->\t%d\n", sizeof(&a[0]+1));//8，是a[1]的地址
//        printf("----------------\n");
//        printf("strlen(a)\t->\t%d\n", strlen(a));//6，字符串长度，不算\0
//        printf("strlen(a+0)\t->\t%d\n", strlen(a+0));//6
////        printf("strlen(*a)\t->\t%d\n", strlen(*a));//ERROR！
////        printf("strlen(a[1])\t->\t%d\n", strlen(a[1]));//ERROR！
//        printf("strlen(&a[1])\t->\t%d\n", strlen(&a[1]));//5
//        printf("strlen(&a)\t->\t%d\n", strlen(&a));//6
//        printf("strlen(&a+1)\t->\t%d\n", strlen(&a+1));//0
//        printf("strlen(&a[0]+1)\t->\t%d\n", strlen(&a[0]+1));//5
//
//    return 0;
//}



// 字符数组
//int main()
//{
//    char a[] = {'a', 'b', 'c', 'd', 'e', 'f'};
//    printf("----------\n");
//    printf("%p\t->\ta[0]\t->%c\n", &a[0], a[0]);
//    printf("%p\t->\ta[1]\t->%c\n", &a[1], a[1]);
//    printf("%p\t->\ta[2]\t->%c\n", &a[2], a[2]);
//    printf("%p\t->\ta[3]\t->%c\n", &a[3], a[3]);
//    printf("%p\t->\ta[4]\t->%c\n", &a[4], a[4]);
//    printf("%p\t->\ta[5]\t->%c\n", &a[5], a[5]);
//    printf("----------\n");
//    printf("sizeof(a)\t->\t%d\n", sizeof(a));//a表示整个数组，6
//    printf("sizeof(a+0)\t->\t%d\n", sizeof(a+0));//表示&a[0]，8
////    printf("%p\n", a+0);
//    printf("sizeof(*a)\t->\t%d\n", sizeof(*a));//*a表示a[0]，1
////    printf("%c\n", *a);
//    printf("sizeof(a[1])\t->\t%d\n", sizeof(a[1]));//a[1]，1
//    printf("sizeof(&a)\t->\t%d\n", sizeof(&a));//数组的地址，8
////    printf("%p\n", &a);
//    printf("sizeof(&a+1)\t->\t%d\n", sizeof(&a+1));//字符f（a[5]）后面的那个元素的地址，跨越了一个a的长度，8
////    printf("%p\n", &a+1);
//    printf("sizeof(&a[0]+1)\t->\t%d\n", sizeof(&a[0]+1));//字符b的地址，8
////    printf("%c\n", *(&a[0]+1));
//    printf("----------------\n");
//    printf("strlen(a)\t->\t%d\n", strlen(a));//这个不确定是多少，strlen是以\0为标志计算的，不知道a数组完后是否为'\0'
//    printf("strlen(a+0)\t->\t%d\n", strlen(a+0));
////    printf("strlen(*a)\t->\t%d\n", strlen(*a));//ERROR!strlen()的参数类型为char*的
////    printf("strlen(a[1])\t->\t%d\n", strlen(a[1]));//ERROR!strlen()的参数类型为char*的，做如下行的修改
//    printf("strlen(a[1])\t->\t%d\n", strlen(&a[1]));//OK
//    printf("strlen(&a)\t->\t%d\n", strlen(&a));//6
//    printf("strlen(&a+1)\t->\t%d\n", strlen(&a+1));//这个是不确定的
//    printf("strlen(&a[0]+1)\t->\t%d\n", strlen(&a[0]+1));//5
//
//    return 0;
//}



/*
int main(int argc, const char * argv[])
{
    // 一维数组
    int a[] = {1,2,3,4};
    printf("----------\n");
    printf("%p\t->\ta[0]\t->\t%d\n", &a[0], a[0]);
    printf("%p\t->\ta[1]\t->\t%d\n", &a[1], a[1]);
    printf("%p\t->\ta[2]\t->\t%d\n", &a[2], a[2]);
    printf("%p\t->\ta[3]\t->\t%d\n", &a[3], a[3]);
    printf("----------\n");
    printf("sizeof(a)\t->\t%lu\n", sizeof(a));//a代表整个数组，16
    printf("sizeof(a+0)\t->\t%lu\n", sizeof(a+0));//a+0代表的是数组首元素的地址，&a[0]，这里32位输出4，64位输出8。
//    printf("a+0\t->\t%p\n", a + 0);
//    printf("a\t->\t%p\n", a);
    printf("sizeof(*a)\t->\t%lu\n", sizeof(*a));//*a是数组第一个元素，4
//    printf("*a\t->\t%d\n", *a);
    printf("sizeof(a+1)\t->\t%lu\n", sizeof(a+1));//a+1代表数组第二个元素的地址，&a[1]，8
//    printf("%p\n", a+1);
    printf("sizeof(a[1])\t->\t%lu\n", sizeof(a[1]));//a[1]的大小，4
    printf("sizeof(&a)\t->\t%lu\n", sizeof(&a));//数组的地址，8
//    printf("%p\n", &a);
    printf("sizeof(*&a)\t->\t%lu\n", sizeof(*&a));//*和&抵消，相当于a代表整个数组，16
    printf("sizeof(&a+1)\t->\t%lu\n", sizeof(&a+1));//这个是个地址，跨过了16个字节，8
//    printf("%p\n", &a+1);
    printf("sizeof(&a[0])\t->\t%lu\n", sizeof(&a[0]));//8
    printf("sizeof(&a[0]+1\t->\t%lu\n", sizeof(&a[0]+1));//&a[1]
//    printf("%p\n", &a[0]+1);
    
    
    return 0;
}
*/
