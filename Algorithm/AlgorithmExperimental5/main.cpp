#include <iostream>

using namespace std;

/**
 * 资源分配问题
 */
int main()
{
    int i, j, k, m, n, rest, a[100][100], gain[100];
    float q[100], f[100], temp[100];
    cout << "how many item?";
    cin >> m;
    cout << "how many moeny?";
    cin >> n;
    cout << "input one item gain table :";
    for (i = 0; i <= n; i++)
    {
        cin >> q[i];
        f[i] = q[i];
    }
    for (i = 0; i <= n; i++)
    {
        a[1][i] = i;
    }
    for (k = 2; k <= m; k++)
    {
        cout << "input another item gain table: ";
        for (i = 0; i <= n; i++)
        {
            temp[i] = q[i];
            cin >> q[i];
            a[k][i] = 0;
        }
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= i; j++)
            {
                if (f[i - j] + q[j] > temp[i])
                {
                    temp[i] = f[i - j] + q[j];
                    a[k][i] = j;
                }
            }
        }
        for (i = 0; i <= n; i++)
        {
            f[i] = temp[i];
        }
    }
    rest = n;
    for (i = m; i >= 1; i--)
    {
        gain[i] = a[i][rest];
        rest -= gain[i];
    }
    for (i = 1; i <= m; i++)
    {
        cout << gain[i] << " ";
    }
    cout << f[n];

    return 0;
}