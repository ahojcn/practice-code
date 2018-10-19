//
//  game.h
//  day08
//
//  Created by hanoi_ahoj on 2018/10/18.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#ifndef game_h
#define game_h

#include <stdio.h>
#include <string.h>  // memset()
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void menu(void);

void BoardInit(char board[ROW][COL], int row, int col);
void BoardShow(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);
int IsFull(char board[ROW][COL], int row, int col);


#endif /* game_h */
