//
//  head.h
//  blog数组的增删改查练习
//
//  Created by hanoi_ahoj on 2018/10/3.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#ifndef head_h
#define head_h

#define MAXSIZE 10
typedef int ElemType;
typedef struct SeqList
{
    ElemType data[MAXSIZE];
    ElemType last;
}SeqList;

// 初始化
void InitSeqList(SeqList *L);
// 输出所有数据
void ShowAllSeqListData(SeqList *L);
// 结尾增加一个数据
void AddOneData(SeqList *L,int e);
// 插入一个数据
void InsertOneData(SeqList *L,int sign,int e);
// 根据位置删除一个数据
void DelOneData(SeqList *L,int sign);
// 根据位置修改数据
void ChangeOneData(SeqList *L,int sign,ElemType e);
// 根据内容修改数据
void ChangeData(SeqList *L,ElemType a,ElemType e);
// 根据位置查找，返回内容
ElemType FileData1(SeqList *L,int sign);
// 根据内容查找，返回编号
int FindData2(SeqList *L,ElemType e);

#endif /* head_h */
