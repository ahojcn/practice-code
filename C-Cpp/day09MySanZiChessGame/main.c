
#include "game.h"

void game_ctrl()
{
    char board[ROW][COL] = { 0 };
    board_init(board, ROW, COL);
    board_print(board, ROW, COL);
    char ret = 0;
    while (true)
    {
        player_move(board, ROW, COL);
        ret = is_win(board, ROW, COL);
        if (ret != ' ')
        {
            break;
        }
        board_print(board, ROW, COL);
        
        computer_move(board, ROW, COL);
        ret = is_win(board, ROW, COL);
        if (ret != ' ')
        {
            break;
        }
        board_print(board, ROW, COL);
    }
    board_print(board, ROW, COL);
    if(ret == 'X')
        printf("you win!\n");
    else if(ret == 'O')
        printf("you lose!\n");
    else if(ret == 'Q')
        printf("again?!\n");
    system("sleep 1s");
}

int main(int argc, const char * argv[])
{
    srand((unsigned int)time(NULL));
    int input = 0;
    do
    {
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
                printf("Input Error!\n");
                break;
        }
    } while (input);
    return 0;
}
