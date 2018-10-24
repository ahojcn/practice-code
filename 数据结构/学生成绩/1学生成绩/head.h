//
//  head.h
//  1学生成绩
//
//  Created by hanoi_ahoj on 2018/9/28.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//

#ifndef head_h
#define head_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char* stu_class;    //班级
    char* stu_id;       //学号
    char* stu_name;     //学生姓名
}Stu;

#define ElemType Stu
#define MAXSIZE 100

typedef struct
{
    ElemType elem[MAXSIZE];
    int last;
}SeqList;

#endif /* head_h */
