#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

/* 约瑟夫环 */
int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[1000] = {0};
    
    
    return 0;
}


/* 5 铺地砖问题 */
//int digui(int );
//int main()
//{
//    int N = 0;
//    scanf("%d", &N);
//
//    printf("%d\n", digui(N));
//
//    return 0;
//}
//int digui(int N)
//{
//    if(N == 1)
//    {
//        return 1;
//    }
//    if(N == 2)
//    {
//        return 2;
//    }
//    return digui(N-1) + digui(N-2);
//}



// /* 4 */
/* k=3,N=100 */
// N=11(1011)->1*3^3+0*3^2+1*3^1+1*3^0=31
//int main()
//{
//    int k,N,sum=0,i=0;
//    scanf("%d%d", &k, &N);
//    while(N != 0)
//    {
//        sum += (N&1)*pow(k, i++);
//        N >>= 1;
//    }
//    printf("%d\n", sum);
//
//    return 0;
//}





// /* 输入字符串统计字母，数字以及其他符号的数目 */
//int main()
//{
//    // /* (1) */
//#define N 100
//    char buf[N] = {0};
//    fgets(buf, N, stdin);
//    int cnt[3] = {0};   // cnt[0]->字母  cnt[1]->数字  cnt[2]->其他字符
//    for(int i=0; i<strlen(buf)-1; i++)  // 这里的strlen(buf)-1 是减去\n字符
//    {
//        if( isalpha(buf[i]) )
//        {
//            cnt[0]++;
//            continue;
//        }
//        else if( isdigit(buf[i]) )
//        {
//            cnt[1]++;
//            continue;
//        }
//        else
//        {
//            cnt[2]++;
//        }
//    }
//
//    printf("%d %d %d\n", cnt[0], cnt[1], cnt[2]);
//
//
//    return 0;
//}








/*
 输入一串字符串，大写转小写，小写转大写
 */
//int main()
//{
//    /* (2) */
//#define N 100
//    char buf[N] = {0};
//    fgets(buf, N, stdin);
//    for(int i=0; i<strlen(buf); i++)
//    {
//        if( isupper(buf[i]) )
//        {
//            buf[i] = tolower(buf[i]);
//            continue;
//        }
//        if( islower(buf[i]) )
//        {
//            buf[i] = toupper(buf[i]);
//            continue;
//        }
//    }
//    for(int i=0; i<strlen(buf); i++)
//    {
//        printf("%c", buf[i]);
//    }
//    printf("\n");
//
//
//   /* (1) */
//    char c = 0;
//    while((c=getchar()) != '\n')
//    {
//        if( isupper(c) )
//        {
//            printf("%c", tolower(c));
//        }
//        if( islower(c) )
//        {
//            printf("%c", toupper(c));
//        }
//    }
//    return 0;
//}








/*
 水仙花数
 */
//int fun3(int n)
//{
//    return n*n*n;
//}
//
//int main(int argc, const char * argv[])
//{
//    //水仙花数
//    int n = 0, m = 0;
//    scanf("%d%d", &m, &n);
//    for(int i=m; i<n; i++)
//    {
//        int sum = 0;
//        int tmp = i;
//        int cnt = 0;
//        while(tmp)
//        {
//            tmp /= 10;
//            cnt++;
//        }
//        tmp = i;
//        while(tmp)
//        {
//            sum += pow(tmp%10, cnt);
//            tmp /= 10;
//        }
//        if(sum == i)
//        {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}
