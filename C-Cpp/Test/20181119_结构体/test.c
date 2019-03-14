#include <stdio.h>
#include <Windows.h>

/* 结构体的定义和初始化 */

//错误，这种递归的调用，并且是没有终止条件的
//struct Node
//{
//	int data;
//	struct Node next;
//};
//正确
//struct Node
//{
//	int data;
//	struct Node *next;	////指针的大小在32位下是4字节，是确定的
//};

//错误
//typedef struct
//{
//	int data;
//	Node *next;		////在编译器检查语法的时候走到这里，不知道Node是什么东西，所以会报错。
//}Node;
//正确
//typedef struct Node
//{
//	int data;
//	struct Node *next;
//}Node;

//struct Point
//{
//	int x;
//	int y;
//}p1;
//struct Point p2;	//正确

//struct Stu
//{
//	char name[15];
//	int age;
//};
//struct Stu s = { "ahoj",20 };	//正确

//struct Node
//{
//	int data;
//	struct Point p;
//	struct Node *next;
//}n1 = { 10,{1,2},NULL };	//正确
//
//int main()
//{
//	struct Node a;
//	printf("%d\n", sizeof(a.next));	// 4
//
//	p1 = { 1,1 }; //错误！初始化的时候可以这么赋值
//	struct Point p3 = { 1,2 }; //正确
//
//
//
//
//	system("pause");
//	return 0;
//}




/* 结构体内存对齐 */



int main()
{


	system("pause");
	return 0;
}