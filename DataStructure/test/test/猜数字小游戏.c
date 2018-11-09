
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game()
{
    int num = rand()%100+1;
    
    printf("im ok >");
    
    int x = 0;
    
    scanf("%d", &x);
    
    while(1)
    {
        if(x < num)
        {
            printf("小了\n");
            scanf("%d", &x);
        }
        else if(x > num)
        {
            printf("大了\n");
            scanf("%d", &x);
        }
        else
            break;
    }
    
}

int main(int argc, const char * argv[])
{
    srand((unsigned int)time(NULL));
    
    printf("*******************\n");
    printf("***1.play 0.exit***\n");
    printf("*******************\n");
    
    int input = 0;
    
    scanf("%d", &input);
    
    switch(input)
    {
        case 1:
            game();
            break;
        case 0:
            exit(0);
        default:
            printf("error!\n");
            break;
    }
    
    
    
    return 0;
}
