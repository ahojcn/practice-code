#include <iostream>
#include <stack>

using namespace std;

/*
 * Hanoi 塔问题
 * 1. 递归
 * 2. 非递归
 */

void hanoiTower(int n, stack<int> &a, stack<int> &b, stack<int> &c)
{
    if (n == 0)
        return;
    hanoiTower(n - 1, a, c, b); // n-1, a->b

    c.push(a.top());    // 最后一个 a->c
    cout << "移动 a 上的 " << a.top() << " 到 c" << endl;
    a.pop();
    cout << "此时 : a.size : " << a.size() << " b.size() : " << b.size() << " c.size() : " << c.size() << endl;

    hanoiTower(n - 1, b, a, c); // n-1, b->c
}

int main()
{
    stack<int> a, b, c;
    int n = 0;
    cout << "输入 a 柱上盘子数量 : ";
    cin >> n;

    for (int i = n; i > 0; i--)
    {
        a.push(i);
//        cout << a.top() << endl;
    }

    hanoiTower(n, a, b, c);

    cout << c.size() << endl;

    return 0;
}