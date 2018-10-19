//
//  main.c
//  MySanZiChessGame
//
//  Created by hanoi_ahoj on 2018/10/19.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//
#include "game.h"

void game_ctrl()
{
    
}

int main(int argc, const char * argv[])
{
    int input = 0;
    do
    {
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
                printf("Input Error!\n");
                break;
        }
    } while (input);
    return 0;
}
