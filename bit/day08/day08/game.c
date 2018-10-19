
#include "game.h"

void menu()
{
    printf("*********************\n");
    printf("*****  1. play  *****\n");
    printf("*****  0. exit  *****\n");
    printf("*********************\n");
}

void BoardInit(char board[ROW][COL], int row, int col)
{
    memset(&board[0][0], ' ', row*col*sizeof(board[0][0]));
}

void BoardShow(char board[ROW][COL], int row, int col)
{
    for (int i=0; i<row; i++)
    {
        // 行内容控制
        for (int j=0; j<col; j++)
        {
            printf(" %c ",board[i][j]);
            if (j<col-1)
            {
                printf("|");
            }
        }
        printf("\n");
        // 列内容控制
        if (i<row-1)
        {
            for (int j=0; j<col; j++)
            {
                printf("---");
                if (j<col-1)
                {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
    printf("your turn>");
    int x = 0;
    int y = 0;
    while (1)
    {
        scanf("%d%d", &x, &y);
        if ((x<1 && x>row) || (y<1 && y>col))
        {
            printf("input error!\n");
        }
        else
        {
            if (board[x-1][y-1] == ' ')
            {
                board[x-1][y-1] = 'X';
                break;
            }
            else
            {
                printf("input error!\n");
            }
        }
    }
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    int i = 0;
    while (1)
    {
        x = rand() % row;
        y = rand() % col;
        for (i = 0; i < row; i++)
        {
            if (board[i][0] == board[i][1] && board[i][0] == 'X' && board[i][2] == ' ')
            {
                board[i][2] = 'O';
                goto flag1;
            }
            else if (board[i][1] == board[i][2] && board[i][1] == 'X' && board[i][0] == ' ')
            {
                board[i][0] = 'O';
                goto flag1;
            }
            else if (board[i][0] == board[i][2] && board[i][2] == 'X' && board[i][1] == ' ')
            {
                board[i][1] = 'O';
                goto flag1;
            }
            else if (board[0][i] == board[1][i] && board[0][i] == 'X' && board[2][i] == ' ')
            {
                board[2][i] = 'O';
                goto flag1;
            }
            else if (board[1][i] == board[2][i] && board[1][i] == 'X' && board[0][i] == ' ')
            {
                board[0][i] = 'O';
                goto flag1;
            }
            else if (board[0][i] == board[2][i] && board[2][i] == 'X' && board[1][i] == ' ')
            {
                board[1][i] = 'O';
                goto flag1;
            }
            else if (board[0][0] == board[1][1] && board[0][0] == 'X' && board[2][2] == ' ')
            {
                board[2][2] = 'O';
                goto flag1;
            }
            else if (board[1][1] == board[2][2] && board[1][1] == 'X' && board[0][0] == ' ')
            {
                board[0][0] = 'O';
                goto flag1;
            }
            else if (board[0][0] == board[2][2] && board[0][0] == 'X' && board[1][1] == ' ')
            {
                board[1][1] = 'O';
                goto flag1;
            }
            else if (board[0][2] == board[1][1] && board[1][1] == 'X' && board[2][0] == ' ')
            {
                board[2][0] = 'O';
                goto flag1;
            }
            else if (board[1][1] == board[2][0] && board[1][1] == 'X' && board[0][2] == ' ')
            {
                board[0][2] = 'O';
                goto flag1;
            }
            else if (board[2][0] == board[0][2] && board[2][0] == 'X' && board[1][1] == ' ')
            {
                board[1][1] = 'O';
                goto flag1;
            }
        }
        for (i = 0; i < row; i++)
        {
            if (board[i][0] == board[i][1] && board[i][0] == 'O' && board[i][2] == ' ')
            {
                board[i][2] = 'O';
                goto flag1;
            }
            else if (board[i][1] == board[i][2] && board[i][1] == 'O' && board[i][0] == ' ')
            {
                board[i][0] = 'O';
                goto flag1;
            }
            else if (board[i][0] == board[i][2] && board[i][2] == 'O' && board[i][1] == ' ')
            {
                board[i][1] = 'O';
                goto flag1;
            }
            else if (board[0][i] == board[1][i] && board[0][i] == 'O' && board[2][i] == ' ')
            {
                board[2][i] = 'O';
                goto flag1;
            }
            else if (board[1][i] == board[2][i] && board[1][i] == 'O' && board[0][i] == ' ')
            {
                board[0][i] = 'O';
                goto flag1;
            }
            else if (board[0][i] == board[2][i] && board[2][i] == 'O' && board[1][i] == ' ')
            {
                board[1][i] = 'O';
                goto flag1;
            }
            else if (board[0][0] == board[1][1] && board[0][0] == 'O' && board[2][2] == ' ')
            {
                board[2][2] = 'O';
                goto flag1;
            }
            else if (board[1][1] == board[2][2] && board[1][1] == 'O' && board[0][0] == ' ')
            {
                board[0][0] = 'O';
                goto flag1;
            }
            else if (board[0][0] == board[2][2] && board[0][0] == 'O' && board[1][1] == ' ')
            {
                board[1][1] = 'O';
                goto flag1;
            }
            else if (board[0][2] == board[1][1] && board[1][1] == 'O' && board[2][0] == ' ')
            {
                board[2][0] = 'O';
                goto flag1;
            }
            else if (board[1][1] == board[2][0] && board[1][1] == 'O' && board[0][2] == ' ')
            {
                board[0][2] = 'O';
                goto flag1;
            }
            else if (board[2][0] == board[0][2] && board[2][0] == 'O' && board[1][1] == ' ')
            {
                board[1][1] = 'O';
                goto flag1;
            }
        }
        if (board[x][y] == ' ')
        {
            board[x][y] = 'O';
            goto flag1;
        }
    }
flag1:;
}

char IsWin(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for(i=0; i<row; i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }
    for(i=0; i<col; i++)
    {
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[1][i] != ' ')
        {
            return board[1][i];
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1] != ' ')
        return board[1][1];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1] != ' ')
        return board[1][1];
    
    //判断平局
    if(IsFull(board, row, col) == 1)
    {
        return 'Q';
    }
    //继续
    return ' ';
}

int IsFull(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}
