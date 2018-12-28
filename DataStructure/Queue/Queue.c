//
// Created by hanoi_ahoj on 2018/12/28.
//

#include "Queue.h"

Status InitQueue(SqQueue *q){
    q->front = 0;
    q->rear = 0;
    return OK;
}

int QueueLength(const SqQueue *q){
    return (q->rear-q->front+MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue *q, const QElemType e){
    if (IsFull(q) == FULL){
        return ERROR;
    }
    else{
        q->data[q->rear] = e;
        q->rear = (q->rear + 1) % MAXSIZE;
        return OK;
    }
}

Status DeQueue(SqQueue *q, QElemType *e){
    if (IsEmpty(q) == EMPTY){
        return ERROR;
    }
    else{
        *e = q->data[q->front];
        q->front = (q->front + 1) % MAXSIZE;
        return OK;
    }
}

Status IsFull (const SqQueue *q) {
    return ((q->rear + 1) % MAXSIZE) == q->front ? FULL : NOTFULL;
}

Status IsEmpty(const SqQueue *q){
    return q->front == q->rear ? EMPTY : NOTEMPTY;
}
