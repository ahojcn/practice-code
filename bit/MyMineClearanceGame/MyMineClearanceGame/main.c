//
//  main.c
//  MyMineClearanceGame
//
//  Created by hanoi_ahoj on 2018/10/20.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include "game.h"

void game_ctrl()
{
    char board_show[ROWS][COLS] = {0}; // *
    char board_mine[ROWS][COLS] = {0}; // 0
    char sign[ROWS][COLS] = {0};    // 把雷区个数都放进来
    board_init(board_show, ROWS, COLS, '*');    // *
    board_init(board_mine, ROWS, COLS, '0');    // 0
    board_init(sign, ROWS, COLS, '0');  // 0
    
    board_print(board_show, ROW, COL);
    set_mine(board_mine, ROW, COL);
    calculate_mine(board_mine, sign);
//
//    board_print(board_mine, ROW, COL);
//    board_print(sign, ROW, COL);
//
    clear_mine(board_mine, board_show, sign, ROW, COL);
}

int main(int argc, const char * argv[])
{
    srand((unsigned int)time(NULL));
    int input = 0;
    do {
        game_menu();
        printf(">");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                game_ctrl();
                break;
            case 0:
                printf("Bye!\n");
                break;
            default:
                printf("Error!\n");
                break;
        }
    } while (input);
    
    return 0;
}
