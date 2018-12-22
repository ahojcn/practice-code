#include "SeqList.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define N 100

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    SeqList sl;
    SeqListInit(&sl);

    for (int i = 0; i < 7; i++)
    {
        SeqListAddFromTail(&sl, rand() % N);
        SeqListAddFromFront(&sl, rand() % N);
    }

    SeqListShowArr(&sl);

    printf("sl->size = %d\n", sl.size);
    printf("sl->cap = %d\n", sl.cap);

    return 0;
}
