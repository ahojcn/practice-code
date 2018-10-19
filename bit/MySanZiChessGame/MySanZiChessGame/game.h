#ifndef game_h
#define game_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROW 3
#define COL 3

typedef struct
{
    int x;
    int y;
}Point;

void game_menu(void);

// 初始化地图
void board_init(char board[ROW][COL], int row, int col);

// 展示地图信息
void board_print(char board[ROW][COL], int row, int col);

// 玩家走
void player_move(char board[ROW][COL], int row, int col);

// 电脑走
void computer_move(char board[ROW][COL], int row, int col);

// 胜利判断
char is_win(char board[ROW][COL], int row, int col);
int is_full(char board[ROW][COL], int row, int col);


// 扫描的地图函数
// 扫描行 如果玩家即将胜利，返回一个他下一步的棋子位置
Point scan_row(char board[ROW][COL], int row, int col);
// 扫描列 如果玩家即将胜利，返回一个他下一步的棋子位置
Point scan_col(char board[ROW][COL], int row, int col);




#endif /* game_h */
