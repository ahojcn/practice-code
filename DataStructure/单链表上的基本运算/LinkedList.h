//
//  LinkedList.h
//  单链表上的基本运算
//
//  Created by hanoi_ahoj on 2018/10/10.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node, *LinkedList;

// 初始化单链表
void InitLinkedList(LinkedList *L);

// 头插法 建立单链表
void CreateFromHead(LinkedList L);
// 尾插法 建立单链表
void CreateFromTail(LinkedList L);

// 按序号查找
Node *Get(LinkedList L, int i);
// 按值查找
Node *Locate(LinkedList L, ElemType Key);

// 求单链表长度
int LinkedListLength(LinkedList L);

// 插入
void InsertLinkedList(LinkedList L, int i, ElemType e);

// 删除
void DeleteLinkedList(LinkedList L, int i);

// 输出单链表的内容
void ShowData(LinkedList L);

// 合并两个有序（升序）的单链表
LinkedList MergeLinkedList(LinkedList LA, LinkedList LB);


#endif /* LinkedList_h */
