//
//  SqList.h
//  SqList
//
//  Created by hanoi_ahoj on 2018/11/9.
//  Copyright © 2018 ahoj. All rights reserved.
//

#ifndef SqList_h
#define SqList_h

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status; //函数类型Status，值是函数结果状态代码

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

Status InitSqList(SqList *S);       // 默认初始化，值为 1~MAXSIZE
Status DisplaySqList(SqList *S);    // 打印
Status GetElem(SqList *S, int i, ElemType *e);    // 查找第i个位置的值，该值通过参数e带回 和 返回该值


#endif /* SqList_h */
