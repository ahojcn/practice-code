/*
 * 5.(1)
 */
//#include <iostream>
//#include <string>
//#include <stack>
//
//std::stack<char> sk; // 用来存放括号
//std::string str;
//bool flag = true;
//
//bool iscal(char c)
//{
//    return c == '+' || c == '-' || c == '*' || c == '/';
//}
//
//int main()
//{
//    std::cin >> str;
//    std::string::iterator it = str.begin();
//
//    while (it != str.end())
//    {
//        if (*it == '(')
//        {
//            if (isdigit(*(it - 1)))
//            {
//                flag = false;
//                break;
//            }
//            else
//            {
//                sk.push(*it);
//            }
//        }
//        else if (*it == ')')
//        {
//            if (sk.empty())
//            {
//                flag = false;
//                break;
//            }
//            else
//            {
//                if (iscal(*(it - 1)))
//                {
//                    flag = false;
//                    break;
//                }
//                else
//                {
//                    sk.pop();
//                }
//            }
//        }
//        else if (isdigit(*it))
//        {
//            if (*(it - 1) == ')')
//            {
//                flag = false;
//                break;
//            }
//            else
//            { ; }
//        }
//        else // is cal, ignore
//        { ; }
//        ++it;
//    }   // while()
//
//    if (!sk.empty())
//    {
//        flag = false;
//    }
//
//    if (flag)
//    { std::cout << "true\n"; }
//    else
//    { std::cout << "false\n"; }
//
//    return 0;
//}

/*
 * 5.(2)
 */
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//
//using namespace std;
//const int maxn = 1000;
//const int inf = 0x3f3f3f3f;
//size_t n;
//string c;
//int dp[maxn][maxn];
//int num[maxn][maxn];
//int m;
//
//int NUM(int x, int y)
//{
//    if (num[x][y] != -1)
//    {
//        return num[x][y];
//    }
//    int sum = 0;
//    for (int i = x; i < y; i++)
//    {
//        sum = sum * 10 + c[i] - '0';
//    }
//    num[x][y] = sum;
//    return sum;
//}
//
//int DP(size_t p, int x)
//{
//    size_t k;
//    if (dp[p][x] != -1)
//    {
//        return dp[p][x];
//    }
//
//    if (x == 0)
//    {
//        dp[p][0] = NUM(0, p);
//        return dp[p][0];
//    }
//    dp[p][x] = inf;
//    for (k = p - 1; k >= x; k--)
//    {
//        dp[p][x] = min(dp[p][x], DP(k, x - 1) + NUM(k, p));
//    }
//    return dp[p][x];
//}
//
//int main()
//{
//    cin >> c;
//    memset(dp, -1, sizeof(dp));
//    memset(num, -1, sizeof(num));
//    cin >> m;
//    n = c.length();
//    cout << DP(n,m) << endl;
//    return 0;
//}

/*
 * 5.(5) 整数划分
 */
//#include <iostream>
//
//#define MAXSIZE 1024
//
//// arr->缓冲，cur->当前位置
//void f(int n, int arr[], int cur)
//{
//    int i;
//    if (n <= 0)
//    {
//        for (i = 0; i < cur; i++)
//        {
//            std::cout << arr[i] << " ";
//        }
//        std::cout << "\n";
//        return;
//    }
//
//    for (i = n; i > 0; i--)
//    {
//        if (cur > 0 && i > arr[cur - 1])
//        {
//            continue;
//        }
//        arr[cur] = i;
//        f(n - i, arr, cur + 1);
//    }
//}
//
//int main()
//{
//    int n;
//    int arr[MAXSIZE] = { 0 };
//    std::cin >> n;
//    f(n, arr, 0);
//    return 0;
//}

/*
 * 5.(11)
 */
//#include <iostream>
//
//int table[6][6] = {{ 0, 0,  0,  0,  0,  0 },
//                        { 0, 13, 11, 10, 4,  7 },
//                        { 0, 13, 10, 10, 8,  5 },
//                        { 0, 5,  9,  7,  7,  4 },
//                        { 0, 15, 12, 10, 11, 5 },
//                        { 0, 10, 11, 8,  8,  4 }};
//
//int tmp[6] = { 0 };
//int best[6] = { 0 };
//int all = 0, tmp_a = 0;
//
//int search(int n)
//{
//    int i, j;
//    for (i = 1; i <= 5; i++)
//    {
//        if (tmp[i] == 0)
//        {
//            tmp[i] = n;
//            tmp_a += table[n][i];
//            if (n == 5)
//            {
//                if (tmp_a > all)
//                {
//                    all = tmp_a;
//                    for (j = 1; j <= 5; j++)
//                    {
//                        best[j] = tmp[j];
//                    }
//                }
//            }
//            else search(n + 1);
//            tmp[i] = 0; //恢复现场
//            tmp_a -= table[n][i];
//        }
//    }
//
//}
//
//int main()
//{
//    int i;
//    search(1);
//    for (i = 1; i <= 5; i++)
//    {
//        std::cout << "job J" << i << "->" << (char)(best[i]+'A'-1) << std::endl;
//    }
//    std::cout << "共计:" << all << std::endl;
//    return 0;
//}

/*
 * 5.(12)
 */
#include <iostream>

using namespace std;

int IsTwo(int n)
{
    return (n & (n - 1)) == 0 ? 1 : 0;
}

int main()
{
    int num, sum = 0;
    int i, j, k;
    cin >> num;
    if (IsTwo(num))
        cout << "no" << endl;
    else
    {
        for (i = 1; i <= num / 2; i++)
        {
            for (k = 1;; k++)
            {
                sum = (k + 1) * (2 * i + k) / 2;
                if (sum > num)
                    break;
                if (sum == num)
                {
                    cout << num << "=";
                    for (j = 0; j < k; j++)
                    {
                        cout << i + j << "+";
                    }
                    cout << i + k << endl;
                }
            }
        }
    }
    return 0;
}