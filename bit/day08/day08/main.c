//
//  main.c
//  三子棋
//
//  Created by hanoi_ahoj on 2018/10/18.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include "game.h"

void game()
{
    char board[ROW][COL] = {0};
    BoardInit(board, ROW, COL);
    BoardShow(board, ROW, COL);
    char ret = 0;
    while (1)
    {
        PlayerMove(board, ROW, COL);
        system("clear");
        ret = IsWin(board, ROW, COL);
        if (ret != ' ')
        {
            break;
        }
        BoardShow(board, ROW, COL);
        
        ComputerMove(board, ROW, COL);
        system("clear");
        ret = IsWin(board, ROW, COL);
        if (ret != ' ')
        {
            break;
        }
        BoardShow(board, ROW, COL);
    }
    if(ret == 'X')
        printf("you win!\n");
    else if(ret == '0')
        printf("you lose!\n");
    else if(ret == 'Q')
        printf("over\n");
    BoardShow(board, ROW, COL);
}

void GameCtrl()
{
    srand((unsigned int)time(NULL));
    int input = 0;
    do
    {
        menu();
        printf(">");
        scanf("%d",&input);
        switch (input)
        {
            case 1:
                system("clear");
                game();
                break;
            case 0:
                printf("Bye!\n");
                break;
            default:
                printf("Error!\n");
                break;
        }
    } while (input);
}

int main(int argc, const char * argv[])
{
    GameCtrl();
    return 0;
}
