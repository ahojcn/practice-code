#ifndef SeqList_h
#define SeqList_h

#include <stdbool.h>

#define INIT_SIZE 10    // 初始大小
#define INC_SIZE 3  // 扩容倍数

typedef int SeqElemType;

typedef struct SeqList
{
    SeqElemType *arr;
    int size;
    int cap;
} SeqList;

// log fun
void SeqListLog(const char *leval, const char *msg);

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
void SeqListDelFromTail(SeqList *sl);
void SeqListDelFromHead(SeqList *sl);
// 删除sl中第一个值为value的元素，返回这个元素的下标，如果没有返回-1
int SeqListDelFirstOne(SeqList *sl, SeqElemType value);
// 删除sl中所有值为value的元素，有元素返回删除了几个，没有返回0
int SeqListDelAllValue(SeqList *sl, SeqElemType value);

// 改
void SeqListUpdateValue(SeqList *sl, int index, SeqElemType value);

// 查
// 返回遍历查找到的第一个value的下标，没有返回-1
int SeqListFindValue(SeqList *sl, SeqElemType value);
// 二分查找，找到返回下标，找不到返回-1，要求arr为正向有序（从小到大）
int SeqListBinFindValue(SeqList *sl, SeqElemType value);
// 在sl中查找index下标的元素值
SeqElemType SeqListSearchIndex(SeqList *sl, int index);

// 对arr进行冒泡排序
void SeqListBobSort(SeqList *sl);
void SeqListQSort(SeqList *sl);

#endif /* SeqList_h */