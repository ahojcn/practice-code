#include <iostream>

using namespace std;

#define SIZE 200

int main()
{

    int m, n;

    int cmn(int m, int n);

    cout << "编写用动态规划法求组合数 Cmn 的算法" << endl;
    cout << "please enter the m,n（m>=n）:";
    cin >> m >> n;
    cout << cmn(m, n) << endl;
    return 0;
}

int cmn(int m, int n)
{
    int a[SIZE];
    int i, j;
    a[0] = 1;
    for (i = 1; i <= m; i++)
    {
        for (a[i] = 1, j = i - 1; j >= 1; j--)
        { a[j] += a[j - 1]; }
    }
    return a[n];
}







//int job[6][2] = {
//        { 3,  8 },
//        { 12, 10 },
//        { 5,  9 },
//        { 2,  6 },
//        { 9,  3 },
//        { 11, 1 }
//};
//int x[6], bestx[6], f1 = 0, bestf, f2[7] = { 0 };
//
//void test(int i);
//
//void swap(int a, int b);
//
//int main(void)
//{
//    int i, j;
//    bestf = 32767;
//    for (i = 0; i < 6; i++)
//    {
//        x[i] = i;
//    }
//    test(0);
//    for (i = 0; i < 6; i++)
//    {
//        printf("%d ", bestx[i]);
//    }
//    printf("\nbestf=%d\n", bestf);
//    return 0;
//}
//
//void test(int i)
//{
//    int j;
//    if (i == 6)
//    {
//        for (
//                j = 0;
//                j < 6; j++)
//        {
//            bestx[j] = x[j];
//        }
//        bestf = f2[i];
//    }
//    else
//    {
//        for (
//                j = i;
//                j < 6; j++)
//        {
//            f1 = f1 + job[x[j]][0];
//            if (f2[i] > f1)
//                f2[i + 1] = f2[i] + job[x[j]][1];
//            else
//                f2[i + 1] = f1 + job[x[j]][1];
//            if (f2[i + 1] < bestf)
//            {
//                swap(i, j
//                );
//                test(i + 1);
//                swap(i, j
//                );
//            }
//            f1 = f1 - job[x[j]][0];
//        }
//    }
//}
//
//void swap(int i, int j)
//{
//    int temp;
//    temp = x[i];
//    x[i] = x[j];
//    x[j] = temp;
//}










//#define N 6
//#define M 7
//#define MID 5
//
///*
// * 用分治法取出一个范围内的最大值以及该值的下标
// */
//void getMax(int a[M][4],int left, int right,int *max, int *j)
//{
//    int lmax,rmax,lj,rj,mid;
//
//    if(left < 0) {
//        left= 0;
//    }
//    if(right > M - 1) {
//        right= M - 1;
//    }
//
//    if(left == right) {
//        *max= a[left][1];
//        *j= left;
//
//    }else if(left == right - 1) {
//        *max= a[left][1] >= a[right][1] ? a[left][1] : a[right][1];
//        *j= a[left][1] >= a[right][1] ? left : right;
//
//    }else {
//        mid= (left + right) / 2;
//        getMax(a,left, mid, &lmax, &lj);
//        getMax(a,mid + 1, right, &rmax, &rj);
//
//        *max= lmax >= rmax ? lmax : rmax;
//        *j= lmax >= rmax ? lj : rj;
//
//    }
//}
//
//int main()
//{
//    int data[N][M][4];
//    cout << "从底到顶输入每行的数据：\n";
//    int i, j;
//    for(i = 0; i < N; i++) {
//        for(j = 0; j < M; j++) {
//            scanf("%d",&data[i][j][0]);
//            data[i][j][1]= data[i][j][0];
//            data[i][j][2]= data[i][j][3] = 0;
//        }
//    }
//
//    for(i = N - 2; i >= 0; i--) {
//        for(j = 0; j < M; j++) {
//            int maxdata, maxdataj;
//            getMax(data[i+ 1], j - MID/2, j + MID/2, &maxdata, &maxdataj);
//
//            data[i][j][1]+= data[i + 1][maxdataj][1];
//            data[i][j][2]= maxdataj;
//        }
//    }
//
//    int maxdata,maxdataj;
//    getMax(data[i+ 1], MID - 2, MID + 2, &maxdata, &maxdataj);
//    cout << "最大和为：" << maxdata;
//    data[0][maxdataj][3]= 1;
//    for(i = 1; i < N; i++) {
//        maxdataj= data[i - 1][maxdataj][2];
//        data[i][maxdataj][3]= 1;
//    }
//
//    for(i = N - 1; i >= 0; i--) {
//        for(j = 0; j < M; j++) {
//            printf("%d\t",data[i][j][3]);
//        }
//        printf("\n");
//    }
//    for(i = 0; i < N/2; i++) {
//        printf("\t");
//    }
//    printf("人\n");
//    return 0;
//}








/**
 * 4.13
 */

/*const int N = 1000, M = 1000;
int xx, yy, dp[N][M], a[N][M], path[N][M], road[N];

int max5(int i, int a, int b, int &t)
{
    int j, Max = 0x80000000;
    for (j = a; j <= b; ++j)
    {
        if (xx <= j && j <= yy && dp[i][j] > Max)
            Max = dp[i][j], t = j;
    }
    return Max;
}

int main()
{
    int n, m, i, j;
    cin >> n >> m;
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            dp[i][j] = a[i][j];
        }
    }
    int s = m / 2 + 1;
    xx = s - 2;
    yy = s + 2;
    if (xx <= 0) xx = 1, yy = m;
    int x = s - 4, y = s + 4;
    if (x <= 0) x = 1, y = m;
    int t = 0;
    for (i = n - 1; i > 0; --i)
    {
        for (j = x; j <= y; ++j)
        {
            dp[i][j] += max5(i + 1, j - 2, j + 2, t);
            path[i][j] = t;
        }
        xx = x, yy = y;
        x -= 2, y += 2;
        if (x <= 0) x = 1, y = m;
    }
    int Max = dp[1][x];
    t = x;
    for (i = x + 1; i <= y; ++i)
    {
        if (dp[1][i] > Max) Max = dp[1][i], t = i;
    }
    for (i = 1; i <= n; ++i)
    {
        road[i] = a[i][t], t = path[i][t];
    }
    printf("max:%d\n", Max);
    printf("path:");
    for (i = n; i > 0; --i)
    {
        printf("%d ", road[i]);
    }

    return 0;
}*/









/**
 * 4.11 最佳浏览路线问题
 */
/*
int n, m, a[501], maxn, b[101][20001];

int main()
{
    //scanf("%d%d", &n, &m);
    int i, j;
    cin >> n >> m;
    m--;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            //scanf("%d", &b[i][j]);
            cin >> b[i][j];
        }
    }
    for (i = 1; i <= m; i++)
    {
        int m1 = -100;
        for (j = 1; j <= n; j++)
        {
            if (b[j][i] > m1) m1 = b[j][i];
        }
        a[i] = a[i - 1] + m1;
        if (a[i] < 0)
            a[i] = 0;//清0.
        else if (a[i] > maxn)
            maxn = a[i];
    }
    cout << maxn << endl;
    return 0;
}*/










/**
 * 4.9 求一组数中最大的两个和最小的两个数，分治算法
 */
/*
#define N 10

void max_min(int *a,int m,int n,int *min1,int *min2,int *max1,int *max2)
{
    int lmin1,lmin2,lmax1,lmax2;
    int rmin1,rmin2,rmax1,rmax2;
    int mid;

    if(m==n)//分治子数组中只有一个数
    {
        *min1=*min2=*max1=*max2=a[m];
    }

    else//分治子数组中不止一个数
    if(m==n-1)//分治子数组中仅有2个数
    {
        if(a[m]<a[n])
        {
            *min1=a[m];
            *min2=a[n];
            *max1=a[n];
            *max2=a[m];
        }
        else
        {
            *min1=a[n];
            *min2=a[m];
            *max1=a[m];
            *max2=a[n];
        }
    }
    else//分治子数组中有超过2个数
    {
        mid=(m+n)/2;
        max_min(a,m,mid,&lmin1,&lmin2,&lmax1,&lmax2);
        max_min(a,mid+1,n,&rmin1,&rmin2,&rmax1,&rmax2);
        if(lmin1<rmin1)//左子数组最小数<右子数组最小数
        {
            if(lmin2<rmin1)
            {
                *min1=lmin1;
                *min2=lmin2;
            }
            else
            {
                *min1=lmin1;
                *min2=rmin1;
            }
        }
        else//右子数组最小数<左子数组最小数
        if(rmin2<lmin1)
        {
            *min1=rmin1;
            *min2=rmin2;
        }
        else
        {
            *min1=rmin1;
            *min2=lmin1;
        }
        if(lmax1>rmax1)//左子数组最大数>右子数组最大数
        {
            if(lmax2>rmax1)
            {
                *max1=lmax1;
                *max2=lmax2;
            }
            else
            {
                *max1=lmax1;
                *max2=rmax1;
            }
        }
        else//右子数组最大数>左子数组最大数
        if(rmax2>lmax1)
        {
            *max1=rmax1;
            *max2=rmax2;
        }
        else
        {
            *max1=rmax1;
            *max2=lmax1;
        }
    }
}

int main()
{
    int a[N]={2,3,4,5,34,7,9,6,43,21};
    int min1,min2;
    int max1,max2;
    max_min(a,0,N-1,&min1,&min2,&max1,&max2);
    printf("min1=%d min2=%d --- max1=%d max2=%d\n",min1,min2,max1,max2);
    return 0;
}*/









/**
 * 4.6
 * 百马百担问题
 */
/*void fun()
{
    int da = 0,zhong = 0,xiao = 0;
    for (da = 1; da <= 100/3; da++)
    {
        for (zhong = 1; zhong <= 100/2; zhong++)
        {
            for (xiao = 1; xiao <= 100; xiao++)
            {
                if (da * 3 + zhong * 2 + xiao == 100)
                {
                    cout << "大马：" << da << " 中马：" << zhong << " 小马：" << xiao << endl;
                }
            }
        }
    }
}

int main()
{
    fun();
    return 0;
}*/










/**
 * 4.2题
 * 猴子吃桃问题
 * @return 第一天摘了多少个桃子
 */
/*
int fun()
{
    int ret = 2;
    int day = 10;
    while (day != 0)
    {
        ret += 2;
        ret *= 2;
        day--;
    }
    return ret;
}

int main()
{
    cout << fun() << endl;
    return 0;
}*/

