#ifndef SeqList_h
#define SeqList_h

#include <stdbool.h>

#define INIT_SIZE 10    // 初始大小
#define INC_SIZE 2  // 扩容倍数

typedef int SeqElemType;

typedef struct SeqList
{
    SeqElemType *arr;
    int size;
    int cap;
} SeqList;

// 初始化
void SeqListInit(SeqList *sl);

// 扩容
void SeqListInc(SeqList *sl);

// 销毁
void SeqListDestory(SeqList *sl);

// Show
void SeqListShowArr(const SeqList *sl);

// get info
int SeqListGetSize(const SeqList *sl);
int SeqListGetCap(const SeqList *sl);

// 增
// 在尾部添加一个值为value的元素
void SeqListAddFromTail(SeqList *sl, SeqElemType value);
// 在头部添加一个值为value的元素
void SeqListAddFromFront(SeqList *sl, SeqElemType value);
// 在中间arr下标为i的位置插入一个值为valude的元素
void SeqListInsert(SeqList *sl, SeqElemType value, int index);

// 删

// 改

// 查 

#endif /* SeqList_h */