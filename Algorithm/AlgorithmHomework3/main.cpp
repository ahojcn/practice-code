/*
 * 算法第三章作业
 *    刘景亮
 */
#include <iostream>
#include <math.h>

using namespace std;

/*
 * 3. 顺时针打印趣味矩阵
 */
void Q3()
{
    int arr[100][100] = { 0 };
    int n = 5;
    int count = 1;
    cout << "输入一个数 n : ";
    cin >> n;
    for (int i = 0; i < n / 2; ++i)
    {
        // 上
        for (int j = i; j < n - i; ++j)
        {
            arr[i][j] = count++;
        }
        // 右
        for (int j = i + 1; j <= n - i - 1; ++j)
        {
            arr[j][n - i - 1] = count++;
        }
        // 下
        for (int j = n - i - 2; j >= i; --j)
        {
            arr[n - i - 1][j] = count++;
        }
        // 左
        for (int j = n - i - 2; j >= i + 1; --j)
        {
            arr[j][i] = count++;
//            cout << j << "," << i << endl;
        }
    }
    if (n % 2 == 1)
    {
//        cout << "---" << (n+1)/2 << endl;
        arr[2][2] = n * n;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

/*
 * 7. 计算 ackermann 函数 ack(m, n) 的递归函数
 */
int ack(int m, int n)
{
    if (m < 0 || n < 0)
    {
        return 0;
    }
    if (m == 0)
    {
        return n + 1;
    }
    if (n == 0)
    {
        return ack(m - 1, 1);
    }
    return ack(m - 1, ack(m, n - 1));
}

/*
 * 11. 求 1*2*3*...*n 所得结果的末尾有多少个 0 (100 < n < 10000).
 */
void countZero()
{
    int i = 0;
    cout << "输入 n (1000 < n < 10000) : ";
    cin >> i;
    int n = i;
    int count = 0;
    while (n >= 5)
    {
        if (n % 5 == 0)
        {
            int ret = n;
            while (ret % 5 == 0)
            {
                count++;
                ret = ret / 5;
            }
        }
        n--;
    }
    cout << i << "! 的末尾有 " << count << " 个 0." << endl;
}

/*
 * 13. 推断竞赛名次
 */
void Q13()
{
    cout << "ABCDE五个人可能的名次为 : " << endl;
    int a, b, c, d, e;
    for (a = 1; a <= 5; ++a)
    {
        for (b = 1; b <= 5; b++)
        {
            for (c = 1; c <= 5; c++)
            {
                for (d = 1; d <= 5; d++)
                {
                    for (int e = 1; e <= 5; e++)
                    {
                        if ((b == 3 || c == 5)
                            && (d == 2 || e == 4)
                            && (b == 1 || e == 4)
                            && (c == 1 || b == 2)
                            && (d == 2 || a == 3)
                            && (
                                    a != b && a != c && a != d && a != e
                                    && b != c && b != d && b != e
                                    && c != d && c != e
                                    && d != e
                            ))
                        {
                            cout << a << b << c << d << e << endl;
                        }
                    }
                }
            }
        }
    }
}

/*
 * 16. 判断能否被 4，7，9 整除
 */
void Q16()
{
    int n = 0;
    cout << "请输入一个整数 n : ";
    cin >> n;
    int k = (n % 4 == 0) + (n % 7 == 0) * 2 + (n % 9 == 0) * 4;
    // null->0
    // 4->1     7->2    9->4
    // 4*7->3   4*9->5  7*9->6
    // 4*7*9->7
    switch (k)
    {
        case 0:
            cout << "都不行" << endl;
            break;
        case 1:
            cout << "只能被 4 整除" << endl;
            break;
        case 2:
            cout << "只能被 7 整除" << endl;
            break;
        case 3:
            cout << "能被 4，7 整除" << endl;
            break;
        case 4:
            cout << "只能被 9 整除" << endl;
            break;
        case 5:
            cout << "能被 4，9 整除" << endl;
            break;
        case 6:
            cout << "能被 7，9 整除" << endl;
            break;
        case 7:
            cout << "都可以" << endl;
        default:
            break;
    }
//    cout << 4*7*9 << endl;
//    cout << k << endl;
}

/*
 * 18. 求两个数据: 5位数 = 2*4位数，9个数字互不相同
 */
void Q18()
{
    for (int i = 1000; i < 10000; i++)
    {
        int a = i / 10 % 10, b = i / 100 % 10, c = i / 1000 % 10, d = i / 1 % 10, e = 0;
        bool x = a != b && a != c && a != d
                 && b != c && b != d
                 && c != d;
        if (x)
        {
//            cout << i << endl;
//            cout << a << "," << b << "," << c << "," << d << endl;
            int j = i * 2;
            int aa = j / 10 % 10, bb = j / 100 % 10, cc = j / 1000 % 10, dd = j / 1 % 10, ee = j / 10000 % 10;
            bool y = aa != bb && aa != cc && aa != dd && aa != ee
                     && bb != cc && bb != d && bb != ee
                     && cc != dd && cc != ee
                     && d != ee;
            if (y
                && aa != a && aa != b && aa != c && aa != d
                && bb != a && bb != b && bb != c && bb != d
                && cc != a && cc != b && cc != c && cc != d
                && dd != a && dd != b && dd != c && dd != d
                && ee != a && ee != b && ee != c && ee != d)
            {
                cout << "4 : " << i << " , ";
                cout << "5 : " << j << endl;
            }
        }
    }
}

/*
 * 23. 对一个 5 位数以内的数
 *      1. 判断是几位数
 *      2. 按顺序输出各位数字
 *      3. 逆序输出各位数字
 */
void Q23()
{
    int n = 0;
    cout << "输入一个5位数以内的正整数 : ";
    cin >> n;
    char arr[10] = { 0 };
    int tmp = n;
    int cnt = 0;
    while (tmp)
    {
        arr[cnt] = '0' + tmp % 10;
        tmp /= 10;
        cnt++;
    }
    cout << "这是一个 " << cnt << " 位数字" << endl;
    cout << "正序 : ";
    while (cnt)
    {
        cout << arr[--cnt];
    }
    cout << endl;
    cout << "逆序 : ";
    cout << arr << endl;
}

int main()
{

    cout << "3. 顺时针打印趣味矩阵" << endl;
    Q3();
    cout << "---------------------" << endl;

    cout << "7. 计算 ackermann 函数 ack(m, n) 的递归函数" << endl;
    int m, n;
    cout << "请输入 m 和 n : ";
    cin >> m >> n;
    cout << ack(m, n) << endl;
    cout << "---------------------" << endl;

    cout << "11. 求 1*2*3*...*n 所得结果的末尾有多少个 0 (100 < n < 10000)." << endl;
    countZero();
    cout << "---------------------" << endl;

    cout << "13. 推断竞赛名次" << endl;
    Q13();
    cout << "---------------------" << endl;

    cout << "16. 判断能否被 4，7，9 整除" << endl;
    Q16();
    cout << "---------------------" << endl;

    cout << "18. 求两个数据: 5位数 = 2*4位数，9个数字互不相同" << endl;
    Q18();
    cout << "---------------------" << endl;

    cout << "23. 对一个 5 位数以内的数" << endl;
    Q23();
    cout << "---------------------" << endl;

    return 0;
}