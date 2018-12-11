//
//  main.c
//  1学生成绩
//
//  Created by hanoi_ahoj on 2018/9/28.
//  Copyright © 2018年 hanoi_ahoj. All rights reserved.
//
#include "head.h"
#define FILE_PATH "info.txt"

void init(SeqList *L)
{
    FILE *fp = fopen(FILE_PATH, "r");
    if(NULL == fp)
    {
        exit(0);
    }
    for (int i=0; i<L->last; i++)
    {
        L->elem[i].stu_name = (char *)malloc(20);
        L->elem[i].stu_id = (char *)malloc(20);
        L->elem[i].stu_class = (char *)malloc(20);
        
        fscanf(fp, "%[^\n]%*c\n" , L->elem[i].stu_name);
        fscanf(fp, "%[^\n]%*c\n" , L->elem[i].stu_class);
        fscanf(fp, "%[^\n]%*c\n" , L->elem[i].stu_id);
    }
    
    fclose(fp);
}

void show_one_info(SeqList *L,int n)
{
    n=n-1;
    printf("%s\t\t",L->elem[n].stu_name);
    printf("%s\t\t",L->elem[n].stu_class);
    printf("%s\n",L->elem[n].stu_id);
}

void show_tittle()
{
    printf("姓名\t\t");
    printf("班级\t\t");
    printf("学号\n");
}

void show_all_info(SeqList *L)
{
    for (int i=0; i<L->last; i++)
    {
        printf("%s\t\t",L->elem[i].stu_name);
        printf("%s\t\t",L->elem[i].stu_class);
        printf("%s\n",L->elem[i].stu_id);
    }
}

int main(int argc, const char * argv[])
{
    printf("需要录入多少名同学信息?>");
    int n = 0;
    scanf("%d",&n);
    
    SeqList L;
    L.last = n;
    
    init(&L);
    printf("%d名学生信息录入完成，你想查看哪一位同学信息?>",n);
    scanf("%d",&n);
    
    show_tittle();
    show_one_info(&L,n);
    
    return 0;
}









