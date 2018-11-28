#include <stdio.h>

/* 入门训练 A+B问题 */

int main()
{
    int A = 0;
    int B = 0;

    scanf("%d %d", &A, &B);

    printf("%d", A+B);

    return 0;
}



/* 数列求和 */

//int main()
//{
//    long long int n = -1;
//    scanf("%lld", &n);
//
//    long long sum = (n+1)*n/2;
//
//    printf("%lld\n", sum);
//
//    return 0;
//}


///* 圆的面积 */
//#define PI 3.14159265358979323
//int main()
//{
//    int r = 0;
//    scanf("%d", &r);
//
//    double s = PI*r*r;
//    printf("%.7f\n", s);
//
//    return 0;
//}






/* 斐波那契数列 */

//int main()
//{
//    int n = -1;
//    int tmp;
//    int m = 10007;
//    int a1,a2;
//    int i;
//    scanf("%d", &n);
//
//    a1 = a2 = 1;
//
//    for(i=1; i<n; i++)
//    {
//        tmp = a2;
//        a2 = (a1+a2)%m;
//        a1 = tmp;
//    }
//    printf("%d\n",a1);
//
//}


// run time error!
//int f(int n)
//{
//    if(n == 1)
//    {
//        return 1;
//    }
//    if(n == 2)
//    {
//        return 1;
//    }
//    return f(n-1) + f(n-2);
//}
//
//int main(int argc, const char * argv[])
//{
//    int n = -1;
//    scanf("%d", &n);
//    int x = f(n);
//    printf("%d\n", x);
//
//    return 0;
//}
