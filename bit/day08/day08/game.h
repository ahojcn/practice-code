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

#define ROW 3
#define COL 3

void Menu(void);
void PlayGame(void);
void Init(char map[ROW][COL], int row, int col);
void Display(char map[ROW][COL], int row, int col);


#endif /* game_h */
