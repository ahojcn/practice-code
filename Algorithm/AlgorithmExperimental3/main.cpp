#include <iostream>
#include <stack>

using namespace std;

/*
 * Hanoi 塔问题
 * 1. 递归
 * 2. 非递归
 */

// 1. 递归
void hanoiTower(int n, stack<int> &a, stack<int> &b, stack<int> &c)
{
    if (n == 0)
        return;
    hanoiTower(n - 1, a, c, b); // n-1, a->b

    c.push(a.top());    // 最后一个 a->c
//    cout << "移动 a 上的 " << a.top() << " 到 c" << endl;
    a.pop();
    cout << " a.size() : " << a.size()
         << " b.size() : " << b.size()
         << " c.size() : " << c.size() << endl;

    hanoiTower(n - 1, b, a, c); // n-1, b->c
}

/*
首先把三根柱子按顺序排成品字型，把所有的圆盘按从大到小的顺序放在柱子A上。
根据圆盘的数量确定柱子的排放顺序：
若n为偶数，按顺时针方向依次摆放 A B C；
若n为奇数，按顺时针方向依次摆放 A C B。

（1）按顺时针方向把圆盘1从现在的柱子移动到下一根柱子，即当n为偶数时，若圆盘1在柱子A，则把它移动到B；
    若圆盘1在柱子B，则把它移动到C；若圆盘1在柱子C，则把它移动到A。

（2）接着，把另外两根柱子上可以移动的圆盘移动到新的柱子上。
    即把非空柱子上的圆盘移动到空柱子上，当两根柱子都非空时，移动较小的圆盘
    这一步没有明确规定移动哪个圆盘，你可能以为会有多种可能性，其实不然，可实施的行动是唯一的。

（3）反复进行（1）（2）操作，最后就能按规定完成汉诺塔的移动。
 */

/*
所有的汉诺塔移动可以总结为重复的两步，我们假设现在最小的圆盘在a柱子上，柱子为a，b，c
第一步：将最小圆盘移动到下一个柱子上，也就是b
第二步：对a柱子和c柱子进行顶上最小的元素进行判断，
 把小一点的那个圆盘移动到大一点的那个圆盘（有空则摞在空柱子上）。
重复上述两步就可以得到答案。
注意：这样得到的最后的答案不一定是摞在c上，如果N是偶数将摞在b上，
    所以如果N是偶数我们就令第二个柱子为c，第三个柱子为b，这样就一定最后是摞在c上的。
 */
// 2. 非递归
char s[4] = { '0', 'a', 'b', 'c' };
stack<int> a[4];

bool move(int before, int after)
{
    if (a[before].empty())
    {
        return false;
    }
    if (!a[after].empty())
    {
        if ((a[after].top() - a[before].top()) < 0)
        {
            return false;
        }
    }
    a[after].push(a[before].top()); // a -> c   // a -> b
    a[before].pop();
    cout << s[before] << " -> " << s[after] << endl;
    return true;
}

int main()
{
    stack<int> aa, b, c;
    int N = 0;
    cout << "输入 a 柱上盘子数量 : ";
    cin >> N;

    for (int i = N; i > 0; i--)
    {
        aa.push(i);
//        cout << a.top() << endl;
    }

    cout << "递归 : " << endl;
    hanoiTower(N, aa, b, c);

//    cout << c.size() << endl;
    cout << "-------" << endl;

    cout << "非递归 : " << endl;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        a[1].push(N - i);   // a[1] : 3 2 1
    }
    if (N % 2 == 1) // N 是奇数，交换 b c 柱子的位置
    {
        s[2] = 'c';
        s[3] = 'b';
    }
    while (++count)
    {
        move((count - 1) % 3 + 1, (count) % 3 + 1);
        if (!move((count - 1) % 3 + 1, (count + 1) % 3 + 1)
            && !move((count + 1) % 3 + 1, (count - 1) % 3 + 1))
        {
            break;
        }
    }

    return 0;
}