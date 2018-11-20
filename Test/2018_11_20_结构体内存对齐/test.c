#include <stdio.h>
#include <Windows.h>

struct s1
{
	char c1;	// 1
	char c2;	// 1
	int i;		// 4
};				//占用6字节，最大对齐数为4，要能整除4，故最终占用8字节

struct s2
{
	char c1;	// 1+3
	int i;		// 4
	char c2;	// 1+3
};				// 12

struct s3
{
	double d;	// 8
	char c;		// 1
	int i;		// 4
};				// 16

struct s4
{
	char c;		// 1 + 7
	struct s3 s;// 16,最大对齐数8
	double d;	// 8
};				// 32

/* 修改默认对齐数 */
#pragma pack(8)
struct s5
{
	char c1;	
	int i;
	char c2;
};				// 12
#pragma pack()	// 取消设置的默认对齐数，还原为默认值

#pragma pack(1)
struct s6
{
	char c1;
	int i;
	char c2;
};				// 6
#pragma pack()

#pragma pack(2)
struct s7
{
	char c1;
	int i;
	char c2;
};				// 8
#pragma pack()

#pragma pack(3)	//warning C4086: 杂注参数应为“1”、“2”、“4”、“8”或者“16”  //如果是非法的，编译器将使用默认的对齐数
struct s8
{
	char c1;
	int i;
	char c2;
};				// 12
#pragma pack()


int main()
{
	printf("s1 -> %d\n", sizeof(struct s1));	//8
	printf("s2 -> %d\n", sizeof(struct s2));	//12
	printf("s3 -> %d\n", sizeof(struct s3));	//16
	printf("s4 -> %d\n", sizeof(struct s4));	//32

	printf("s5 -> %d\n", sizeof(struct s5));	//12	
	printf("s6 -> %d\n", sizeof(struct s6));	//6
	printf("s7 -> %d\n", sizeof(struct s7));	//8
	printf("s8 -> %d\n", sizeof(struct s8));	//12

	system("pause");
	return 0;
}