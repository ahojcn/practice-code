//
// Created by hanoi_ahoj on 2018/12/28.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include "Status.h"

#define MAXSIZE 10

typedef int QElemType;

typedef struct {
    QElemType data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

/*   循坏队列的顺序存储   */
// 初始化一个空队列
Status InitQueue(SqQueue *q);
// 返回队列的长度
int QueueLength(const SqQueue *q);
// 判满
Status IsFull(const SqQueue *q);
// 判空
Status IsEmpty(const SqQueue *q);
// 入队
Status EnQueue(SqQueue *q, const QElemType e);
// 出队
Status DeQueue(SqQueue *q, QElemType *e);

#endif //QUEUE_QUEUE_H
