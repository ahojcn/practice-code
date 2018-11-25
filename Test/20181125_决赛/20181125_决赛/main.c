/**
 基于C语言程序求出两个城市坐标之间的最短距离。该程序需要实现以下功能：
 1、程序能够根据已有的6个城市坐标，按照考生文件夹中1.jpg所示的有向图，找到从某两个城市之间最短的距离。
 2、已知的六个城市及其坐标为
 ◎A(31.9,17.7)
 ◎B(19.43,20.6)
 ◎C(50.5,48.21)
 ◎D(21.43,27.84)
 ◎E(30.56,34.36)
 ◎F(12.9,23.87)
 
 
 程序说明及要求：
 1、程序已定义了main函数，按题目的要求完善程序，可以根据需要创建结构体和函数。
 2、void createdDG(PDG g, Node *node)函数功能为创建有向图。
 3、void findPath(PDG g,int from,int to)函数功能为找出最短路径。
 4、DG为图的结构体，考生可用可不用。
 5、要求输出结果如考生文件夹中2.jpg所示样式。
 
 */
#include<stdio.h>
#include<math.h>
#define MAX 20
#define NOP 10000

typedef struct Node
{
    int number;
    char vertex[MAX];
    double arc[MAX][MAX];
}DG,*PDG;


void createdDG(PDG g, struct Node *node)
{
    
    
}


void findPath(PDG g,int from,int to)
{
    
}



int main()
{
    DG graph;
    struct Node node[6]={{31.9,17.7},{19.43,20.6},{50.5,48.21},{21.43,27.84},{30.56,34.36},{12.9,23.87}};
    char from,to;
    createdDG(&graph, &node[0]);
    printf("Please input the start and the end point, e.g. 'AF'.\n");
    scanf("%c%c",&from,&to);
    printf("\nThe result:\n");
    findPath(&graph,from-'A',to-'A');
    
    return 0;
}


