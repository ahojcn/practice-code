//
//  main.c
//  三子棋
//
//  Created by hanoi_ahoj on 2018/10/18.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#include "game.h"

// 游戏控制函数
void GameCtrl(void)
{
    int input = 0;
    do
    {
        Menu();
        printf("请选择>");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                PlayGame();
                break;
            case 0:
                printf("Bye!\n");
                break;
            default:
                printf("Error!\n");
                break;
        }
    }while(input);
}

int main(int argc, const char * argv[])
{
    GameCtrl();
    
    return 0;
}
