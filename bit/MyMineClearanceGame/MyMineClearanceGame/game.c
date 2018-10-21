//
//  game.c
//  MyMineClearanceGame
//
//  Created by hanoi_ahoj on 2018/10/20.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include "game.h"

void game_menu(void)
{
    printf("*********************\n");
    printf("*** 1.play 0.exit ***\n");
    printf("*********************\n");
}

void board_init(char board[ROWS][COLS], int rows, int cols, char set)
{
    memset(&board[0][0], set, rows*cols*sizeof(board[0][0]));
}

void board_print(char board[ROWS][COLS], int row, int col)
{
    system("clear");
    for (int i=0; i<=col; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i=1; i<=row; i++)
    {
        printf("%d ", i);
        for (int j=1; j<=col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("-------------------\n");
}

// 布置雷
void set_mine(char board_mine[ROWS][COLS], int row, int col)
{
    Point p;
    int count = EASY;
    while (count)
    {
        p.x = rand()%row + 1;
        p.y = rand()%col + 1;
        if (board_mine[p.x][p.y] == '0')
        {
            board_mine[p.x][p.y] = '1';
            count--;
        }
    }
}

// play
void clear_mine(char board_mine[ROWS][COLS], char board_show[ROWS][COLS], char sign[ROWS][COLS], int row, int col)
{
    Point p;
    int win = 0;
    int cnt = 0;
    while (win<row*col-EASY)
    {
        cnt++;
        printf(">");
        scanf("%d%d", &p.x, &p.y);
        if (p.x>=1 && p.x<=row && p.y>=1 && p.y<=col)
        {
//             第一次踩到雷
            if (board_mine[p.x][p.y]=='1' && cnt==1)
            {
//                重新计算sign中的值
                board_mine[p.x][p.y] = '0';
                Point tmp;
                tmp.x = p.x;
                tmp.y = p.y;
                while (p.x==tmp.x && p.y==tmp.y)
                {
                    p.x = rand()%row+1;
                    p.x = rand()%col+1;
                    if (board_mine[p.x][p.y] == '0' && (p.x!=tmp.x || p.y!=tmp.y))
                    {
                        board_mine[p.x][p.y] = '1';
                        calculate_mine(board_mine, sign);
        ////////////////////////////////test////////////////////////////////////////////
//                        board_print(board_mine, row, col);
//                        board_print(sign, row, col);
        ////////////////////////////////test////////////////////////////////////////////
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }/*if() 第一次踩到雷*/
            else if(board_mine[p.x][p.y] == '1')    // 第一次以后踩到雷了
            {
                board_print(board_mine, row, col);
                printf("you die!\n");
                break;
            }
            else    // 没踩到雷
            {
                int count = get_mine_count(board_mine, p);
                board_show[p.x][p.y] = count + '0';
                open_show(board_mine, board_show, sign, row, col, p);
                board_print(board_show, row, col);
                win++;
            }
        }
        else
        {
            printf("illegal input!\n");
        }
    }// while() 雷没排完
    if(win==row*col-EASY)
    {
        board_print(board_mine, row, col);
        printf("you win!\n");
    }
}

// 计算x,y周围雷数量
int get_mine_count(char board_mine[ROWS][COLS], Point p)
{
    return board_mine[p.x-1][p.y]+
    board_mine[p.x-1][p.y-1]+
    board_mine[p.x][p.y-1]+
    board_mine[p.x+1][p.y-1]+
    board_mine[p.x+1][p.y]+
    board_mine[p.x+1][p.y+1]+
    board_mine[p.x][p.y+1]+
    board_mine[p.x-1][p.y+1]-8*'0';
}

// 计算所有雷数，放到sign[][]里
void calculate_mine(char mine[ROWS][COLS], char sign[ROWS][COLS])
{
    Point p;
    for (int i=0; i<ROWS; i++)
    {
        for (int j=0; j<COLS; j++)
        {
            p.x = i;
            p.y = j;
            sign[i][j] = '0' + get_mine_count(mine, p);
        }
    }
}

int count = MAXOPEN;
// 展开周围没有雷的地方，直到遇到 show[][]有数字
void open_show(char mine[ROWS][COLS], char show[ROWS][COLS], char sign[ROWS][COLS], int row, int col, Point p)
{
    if (count>=0)
    {
        if (mine[p.x-1][p.y-1] == '0')
        {
            Point tmp;
            tmp.x = p.x-1;
            tmp.y = p.y-1;
            show[tmp.x][tmp.y] = sign[tmp.x][tmp.y];
            count--;
            open_show(mine, show, sign, row, col, tmp);
        }
        if(mine[p.x-1][p.y] == '0')
        {
            Point tmp;
            tmp.x = p.x-1;
            tmp.y = p.y;
            show[tmp.x][tmp.y] = sign[tmp.x][tmp.y];
            count--;
            open_show(mine, show, sign, row, col, tmp);
        }
        if(mine[p.x-1][p.y+1] == '0')
        {
            Point tmp;
            tmp.x = p.x-1;
            tmp.y = p.y+1;
            show[tmp.x][tmp.y] = sign[tmp.x][tmp.y];
            count--;
            open_show(mine, show, sign, row, col, tmp);
        }
        if(mine[p.x][p.y+1] == '0')
        {
            Point tmp;
            tmp.x = p.x;
            tmp.y = p.y+1;
            show[tmp.x][tmp.y] = sign[tmp.x][tmp.y];
            count--;
            open_show(mine, show, sign, row, col, tmp);
        }
        if(mine[p.x+1][p.y+1] == '0')
        {
            Point tmp;
            tmp.x = p.x+1;
            tmp.y = p.y+1;
            show[tmp.x][tmp.y] = sign[tmp.x][tmp.y];
            count--;
            open_show(mine, show, sign, row, col, tmp);
        }
        if(mine[p.x+1][p.y] == '0')
        {
            Point tmp;
            tmp.x = p.x+1;
            tmp.y = p.y;
            show[tmp.x][tmp.y] = sign[tmp.x][tmp.y];
            count--;
            open_show(mine, show, sign, row, col, tmp);
        }
        if(mine[p.x+1][p.y-1] == '0')
        {
            Point tmp;
            tmp.x = p.x+1;
            tmp.y = p.y-1;
            show[tmp.x][tmp.y] = sign[tmp.x][tmp.y];
            count--;
            open_show(mine, show, sign, row, col, tmp);
        }
        if(mine[p.x][p.y-1] == '0')
        {
            Point tmp;
            tmp.x = p.x;
            tmp.y = p.y-1;
            show[tmp.x][tmp.y] = sign[tmp.x][tmp.y];
            count--;
            open_show(mine, show, sign, row, col, tmp);
        }
    }
    else
    {
        NULL;
    }
}
