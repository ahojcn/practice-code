#include <stdio.h>

//int main(int argc, const char * argv[])
//{
//    int a[5] = {1,2,3,4,5};
//    int *p = (int *)(&a+1); // p指向5后面的那个地址
//    printf("%d,%d\n", *(a+1), *(p-1));  //2,5
//
//    return 0;
//}

//struct test
//{
//    int num;
//    char *pcName;
//    short sdate;
//    char cha[2];
//    short ba[4];
//}*p;
//
//int main()
//{
//    struct test t;
//    printf("%d\n", sizeof(t));
//
//    return 0;
//}

//
//int main()
//{
//    int a[4] = {1,2,3,4};
//    int *p1 = (int *)(&a+1);
//    int *p2 = (int *)((int)a+1);
//    printf("%x,%x\n", p1[-1], *p2);
//
//    return 0;
//}

//
//int main()
//{
//    int a[3][2] = { (0,1), (2,3), (4,5) };
//    int *p = a[0];
//    printf("%d\n", p[0]);
//
//    return 0;
//}

//int main()
//{
//    int a[5][5];
//    int (*p)[4];
//    p = a;
//    printf("%p,%d\n", &p[4][2]-&a[4][2], &p[4][2]-&a[4][2]);
//
//    return 0;
//}

//int main()
//{
//    int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//    int *p1 = (int *)(&aa + 1);
//    int *p2 = (int *)(*(aa + 1));
//    printf("%d,%d\n", *(p1-1), *(p2-1));
//
//    return 0;
//}

//int main()
//{
//    char *a[] = {"work", "at", "360"};
//    char **pa = a;
//    pa++;
//    printf("%s\n", *pa);
//
//    return 0;
//}

int main()
{
    char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
    int **cp[] = { c+3, c+2, c+1, c };
    char ***cpp = cp;
    printf("%s\n", **++cpp);
    printf("%s\n", *--*++cpp+3);
    printf("%s\n", *cpp[-2]+3);
    printf("%s\n", cpp[-1][-1]+1);
    
    return 0;
}
