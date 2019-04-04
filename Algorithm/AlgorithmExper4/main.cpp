#include <iostream>

using namespace std;

int amount = 0;
int board[100][100];

void Cover(int tr, int tc, int dr, int dc, int size)
{
    int s, t;
    if (size < 2)
        return;
    amount++;
    t = amount;
    s = size / 2;
    if ((dr < tr + s) && (dc < tc + s))
    {
        Cover(tr, tc, dr, dc, s);
        board[tr + s - 1][tc + s] = t;
        board[tr + s][tc + s - 1] = t;
        board[tr + s][tc + s] = t;
        Cover(tr, tc + s, tr + s - 1, tc + s, s);
        Cover(tr + s, tc, tr + s, tc + s - 1, s);
        Cover(tr + s, tc + s, tr + s, tc + s, s);
    }
    else if ((dr < tr + s) && (dc >= tc + s))
    {
        Cover(tr, tc + s, dr, dc, s);
        board[tr + s - 1][tc + s - 1] = t;
        board[tr + s][tc + s - 1] = t;
        board[tr + s][tc + s] = t;
        Cover(tr, tc, tr + s - 1, tc + s - 1, s);
        Cover(tr + s, tc, tr + s, tc + s - 1, s);
        Cover(tr + s, tc + s, tr + s, tc + s, s);
    }
    else if ((dr >= tr + s) && (dc < tc + s))
    {
        Cover(tr + s, tc, dr, dc, s);
        board[tr + s - 1][tc + s - 1] = t;
        board[tr + s - 1][tc + s] = t;
        board[tr + s][tc + s] = t;
        Cover(tr, tc, tr + s - 1, tc + s - 1, s);
        Cover(tr, tc + s, tr + s - 1, tc + s, s);
        Cover(tr + s, tc + s, tr + s, tc + s, s);
    }
    else if ((dr >= tr + s) && (dc >= tc + s))
    {
        Cover(tr + s, tc + s, dr, dc, s);
        board[tr + s - 1][tc + s - 1] = t;
        board[tr + s - 1][tc + s] = t;
        board[tr + s][tc + s - 1] = t;
        Cover(tr, tc, tr + s - 1, tc + s - 1, s);
        Cover(tr, tc + s, tr + s - 1, tc + s, s);
        Cover(tr + s, tc, tr + s, tc + s - 1, s);
    }
}

void OutPutBoard(int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int size = 1;
    int x, y, i, k;
    cin >> k;
    for (i = 1; i <= k; i++)
    {
        size *= 2;
    }
    cout << "input incomplete pane : ";
    cin >> x >> y;

    Cover(0, 0, x, y, size);
    OutPutBoard(size);

    return 0;
}