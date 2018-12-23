#include "SeqList.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define N 1000

#define TEST "测试"

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    SeqList sl;

    SeqListLog(TEST, "初始化");
    SeqListInit(&sl);

    SeqListLog(TEST, "插入测试");
    for (int i = 0; i < 5; i++)
    {
        SeqListAddFromTail(&sl, rand() % N);
        SeqListAddFromFront(&sl, rand() % N);
    }
    SeqListShowArr(&sl);

    SeqListInsert(&sl, -1, 0);  // 边界条件测试
    SeqListShowArr(&sl);
    SeqListInsert(&sl, -1, 20); // 边界条件测试
    SeqListShowArr(&sl);
    SeqListInsert(&sl, -1, 19); // 边界条件测试
    SeqListShowArr(&sl);
    SeqListInsert(&sl, -1, 5);  // 正常条件测试
    SeqListShowArr(&sl);

    SeqListLog(TEST, "删除测试");
    SeqListDelFromHead(&sl);
    SeqListShowArr(&sl);
    SeqListDelFromTail(&sl);
    SeqListShowArr(&sl);

    SeqListDelFirstOne(&sl, -1);
    SeqListShowArr(&sl);
    puts("---");
    SeqListDelAllValue(&sl, -1);
    SeqListShowArr(&sl);

    SeqListLog(TEST, "排序测试");
    SeqListBobSort(&sl);
    SeqListShowArr(&sl);

    SeqListQSort(&sl);
    SeqListShowArr(&sl);
    puts("---");


    SeqListInsert(&sl, 555, 5);  // 正常条件测试
    SeqListQSort(&sl);
    SeqListShowArr(&sl);

    printf("%d\n", sl.arr[SeqListBinFindValue(&sl, -1)]);

    return 0;
}
