//
//  game.c
//  day08
//
//  Created by hanoi_ahoj on 2018/10/18.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include "game.h"

void Menu(void)
{
    printf("*********************\n");
    printf("****  1. play    ****\n");
    printf("****  0. exit    ****\n");
    printf("*********************\n");
}

void PlayGame(void)
{
    char map[ROW][COL] = {0};
    Init(map, ROW, COL);
    Display(map, ROW, COL);
    
}

void Init(char map[ROW][COL], int row, int col)
{
    memset(&map[ROW][COL], ' ', ROW*COL*sizeof(map[0][0]));
}

void Display(char map[ROW][COL], int row, int col)
{
    for (int i = 0; i<row; i++)
    {
        for (int j = 0; j<col; j++)
        {
            printf(" %c |", map[i][j]);
        }
        printf("\n");
    }
}
