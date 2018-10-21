//
//  game.h
//  MyMineClearanceGame
//
//  Created by hanoi_ahoj on 2018/10/20.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#ifndef game_h
#define game_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

#define EASY 10
#define MAXOPEN 3  //一次最多展开的数量

typedef struct
{
    int x;
    int y;
}Point;

void game_menu(void);
void board_init(char board[ROWS][COLS], int rows, int cols, char set);
void board_print(char board[ROWS][COLS], int row, int col);

// 布置雷
void set_mine(char board_mine[ROWS][COLS], int row, int col);
// play
void clear_mine(char board_mine[ROWS][COLS], char board_show[ROWS][COLS], char sign[ROWS][COLS], int row, int col);
// 计算x,y周围雷数量
int get_mine_count(char board_mine[ROWS][COLS], Point p);
// 计算所有雷数，放到sign[][]里
void calculate_mine(char mine[ROWS][COLS], char sign[ROWS][COLS]);
// 展开周围没有雷的地方，直到遇到 show[][]有数字
void open_show(char mine[ROWS][COLS], char show[ROWS][COLS], char sign[ROWS][COLS], int row, int col, Point p);

#endif /* game_h */
