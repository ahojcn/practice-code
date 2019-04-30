#include <iostream>
#include <stack>

using namespace std;

typedef struct Point
{
    int x;
    int y;
} POINT;

stack<POINT> s;
int row = 4, col = 4;

POINT item[4] = {
        { -1, 0 },
        { 0,  1 },
        { 1,  0 },
        { 0,  -1 }
};

int map[6][6] = {
        { 1, 1, 1, 1, 1, 1 },//0
        { 1, 0, 0, 1, 0, 1 },//1
        { 1, 0, 0, 1, 0, 1 },//2
        { 1, 0, 0, 0, 0, 1 },//3
        { 1, 0, 0, 1, 0, 1 },//4
        { 1, 1, 1, 1, 1, 1 },
};

void dfs(int row, int col, POINT p);

int main()
{
    POINT begin;
    begin.x = 1;
    begin.y = 1;

    dfs(row, col, begin);

    return 0;
}

void printPath()
{
    cout << "-------------\n";
    while (!s.empty())
    {
        cout << "[" << s.top().x << "," << s.top().y << "]\n";
        s.pop();
    }
    cout << "-------------\n";
}

void dfs(int row, int col, POINT p)
{
    int x = p.x, y = p.y;
    int i = 0;
    POINT t;
    map[p.x][p.y] = -1; // 走过的节点赋值为 -1
    s.push(p);
    if (row == p.x && col == p.y)
    {
        printPath();
        map[p.x][p.y] = 0;
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            t.x = x + item[i].x;
            t.y = y + item[i].y;
            if (map[t.x][t.y] == 0)
            {
                dfs(row, col, t);
            }
        }
    }
}