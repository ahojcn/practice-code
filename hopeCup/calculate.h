// 4_最优数字分配策略.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
//#include <stdio.h>
//#include <stdlib.h>


typedef struct {
	int a[5];
	int testData;
}Unit;
Unit Space[55][55];

//用来标记已经计算过的位置，初始：0代表未计算过，1代表计算过
int flag[55][55] = { 0 };

typedef struct {
	int grade;
	int c_100;
	int c_50;
	int c_20;
	int c_10;
	int c_1;
	int c_0;
}Arr;
Arr sign[31];

int finally_grade = 0;
typedef struct {
	int a_100;
	int a_50;
	int a_20;
	int a_10;
	int a_1;
}Cnt;
Cnt grade_cnt;

void initSpace_sign_gradeCnt()
{
	//init Space
	for (int i = 0; i < 55; i++)
	{
		for (int j = 0; j < 55; j++)
		{
			for (int k = 0; k < Space[i][j].testData; k++)
			{
				Space[i][j].a[k] = -1;
			}
		}
	}
	//init sign
	for (int t = 0; t < 31; t++)
	{
		sign[t].c_0 = 0;
		sign[t].c_1 = 0;
		sign[t].c_10 = 0;
		sign[t].c_20 = 0;
		sign[t].c_50 = 0;
		sign[t].c_100 = 0;
		sign[t].grade = 0;
	}

	//init grade_cnt
	grade_cnt.a_1 = 0;
	grade_cnt.a_10 = 0;
	grade_cnt.a_20 = 0;
	grade_cnt.a_50 = 0;
	grade_cnt.a_100 = 0;
}

//从文件读取测试数据
void readFile()
{
	FILE *fp = fopen("/Users/hanoi_ahoj/Desktop/data1.csv", "r");

	if (!fp)
		printf("\t文件读取错误！\n请检查！\n");
	int i, j;
	fseek(fp, 0L, SEEK_SET);
	for (i = 2; i <= 51; i++)
	{
		for (j = 2; j <= 51; j++)
		{
			fscanf(fp, "%d,", &Space[i][j].testData);
			//printf("%d,", Space[i][j].testData);
		}
		//printf("\n");
	}
	fclose(fp);
	//printf("文件 加载 完成！\n");
}

//初始化统计违约分的数据，每填一个数的时候都要初始化一下
void initSign()
{
	int i;
	for (i = 1; i <= 31; i++)
	{
		sign[i].grade = 0;
		sign[i].c_100 = 0;
		sign[i].c_50 = 0;
		sign[i].c_20 = 0;
		sign[i].c_10 = 0;
		sign[i].c_1 = 0;
		sign[i].c_0 = 0;
	}
}

//计算违约分，计算的信息存入sign[y]中
void calculate_grade(int i, int j, int x, int y)
{
	//计算i,j位置填y时违约个数

	//1.计算100、50类型的违约分
	for (int tx = 0; tx < Space[i][j].testData; tx++)
	{
		if (Space[i][j].a[tx] == -1)
			break;
		for (int ty = 0; ty < Space[i][j].testData; ty++)
		{
			if (tx == ty)
				continue;
			if (Space[i][j].a[tx] == Space[i][j].a[ty])
				sign[y].c_100 += 1;
			if (Space[i][j].a[tx] - Space[i][j].a[ty] == -1 || Space[i][j].a[tx] - Space[i][j].a[ty] == 1)
				sign[y].c_50 += 1;
		}
	}/*100、50*/

	 //计算i,j位置填y时，与相邻空间的违约分（20、10）
	for (int tx = 0; tx < Space[i][j].testData; tx++)
	{
		if (Space[i][j].a[tx] == -1)
			break;
		for (int ty = 0; ty < Space[i - 1][j - 1].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i - 1][j - 1].a[ty])
				sign[y].c_20 += 1;
			if (Space[i][j].a[tx] - Space[i - 1][j - 1].a[ty] == -1 || Space[i][j].a[tx] - Space[i - 1][j - 1].a[ty] == 1)
				sign[y].c_10 += 1;
		}
		for (int ty = 0; ty < Space[i - 1][j].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i - 1][j].a[ty])
				sign[y].c_20 += 1;
			if (Space[i][j].a[tx] - Space[i - 1][j].a[ty] == -1 || Space[i][j].a[tx] - Space[i - 1][j].a[ty] == 1)
				sign[y].c_10 += 1;
		}
		for (int ty = 0; ty < Space[i - 1][j + 1].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i - 1][j + 1].a[ty])
				sign[y].c_20 += 1;
			if (Space[i][j].a[tx] - Space[i - 1][j + 1].a[ty] == -1 || Space[i][j].a[tx] - Space[i - 1][j + 1].a[ty] == 1)
				sign[y].c_10 += 1;
		}
		for (int ty = 0; ty < Space[i][j - 1].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i][j - 1].a[ty])
				sign[y].c_20 += 1;
			if (Space[i][j].a[tx] - Space[i][j - 1].a[ty] == -1 || Space[i][j].a[tx] - Space[i][j - 1].a[ty] == 1)
				sign[y].c_10 += 1;
		}
		for (int ty = 0; ty < Space[i][j + 1].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i][j + 1].a[ty])
				sign[y].c_20 += 1;
			if (Space[i][j].a[tx] - Space[i][j + 1].a[ty] == -1 || Space[i][j].a[tx] - Space[i][j + 1].a[ty] == 1)
				sign[y].c_10 += 1;
		}
		for (int ty = 0; ty < Space[i + 1][j - 1].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i + 1][j - 1].a[ty])
				sign[y].c_20 += 1;
			if (Space[i][j].a[tx] - Space[i + 1][j - 1].a[ty] == -1 || Space[i][j].a[tx] - Space[i + 1][j - 1].a[ty] == 1)
				sign[y].c_10 += 1;
		}
		for (int ty = 0; ty < Space[i + 1][j].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i + 1][j].a[ty])
				sign[y].c_20 += 1;
			if (Space[i][j].a[tx] - Space[i + 1][j].a[ty] == -1 || Space[i][j].a[tx] - Space[i + 1][j].a[ty] == 1)
				sign[y].c_10 += 1;
		}
		for (int ty = 0; ty < Space[i + 1][j + 1].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i + 1][j + 1].a[ty])
				sign[y].c_20 += 1;
			if (Space[i][j].a[tx] - Space[i + 1][j + 1].a[ty] == -1 || Space[i][j].a[tx] - Space[i + 1][j + 1].a[ty] == 1)
				sign[y].c_10 += 1;
		}

	}/*20、10*/

	 //计算i,j位置填y时，与相邻的相邻空间的违约分 1
	for (int tx = 0; tx < Space[i][j].testData; tx++)
	{
		if (Space[i][j].a[tx] == -1)
			break;
		for (int ty = 0; ty < Space[i - 2][j - 2].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i - 2][j - 2].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i - 2][j - 1].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i - 2][j - 1].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i - 2][j].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i - 2][j].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i - 2][j + 1].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i - 2][j + 1].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i - 2][j + 2].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i - 2][j + 2].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i - 1][j - 2].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i - 1][j - 2].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i - 1][j + 2].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i - 1][j + 2].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i][j - 2].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i][j - 2].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i][j + 2].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i][j + 2].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i + 1][j - 2].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i + 1][j - 2].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i + 1][j + 2].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i + 1][j + 2].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i + 2][j - 2].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i + 2][j - 2].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i + 2][j - 1].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i + 2][j - 1].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i + 2][j].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i + 2][j].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i + 2][j + 1].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i + 2][j + 1].a[ty])
				sign[y].c_1 += 1;
		}
		for (int ty = 0; ty < Space[i + 2][j + 2].testData; ty++)
		{
			if (Space[i][j].a[tx] == Space[i + 2][j + 2].a[ty])
				sign[y].c_1 += 1;
		}

	}/* 1 */
    
    //printf("c_1=%d\n",sign[y].c_1);

	sign[y].grade = sign[y].c_100 * 100 + sign[y].c_50 * 50 + sign[y].c_20 * 20 + sign[y].c_10 * 10 + sign[y].c_1 * 1;

}

//找出违约分最小的编号，返回要填入的那个值
int select_min()
{
	//从sign中选出grade最小的数
	int min = 1;
	int t;	//临时记录最小的sign[].grade

	for (int i = 1; i <= 30; i++)
	{
		if (sign[i].grade == 0)
			min = i;
	}

	t = sign[1].grade;
	for (int j = 2; j <= 30; j++)
	{
		if (sign[j].grade <= t)
		{
			t = sign[j].grade;
			min = j;
		}
	}


	return min;
}

//计算
void calculate()
{
	int i, j;
	for (i = 2; i <= 52; i++)
	{
		for (j = 2; j <= 52; j++)
		{

			//initSign();
			for (int x = 0; x < Space[i][j].testData; x++)
			{
				initSign();
				for (int y = 1; y <= 30; y++)	//从1-30填数,并计算每一个的违约分
				{

					Space[i][j].a[x] = y;
					calculate_grade(i, j, x, y);	//违约分存在sign[y]中
				}
				Space[i][j].a[x] = select_min();//找出sign中最小违约分的标记，并赋给这个空
			}


		}
	}


	printf("\t计算完成！\n");
}



void Grade_20_10()
{
    for (int i = 2; i <= 51; i++)
    {
        for (int j = 2; j <= 51; j++)
        {
            //计算20、10违约分
            for (int tx = 0; tx < Space[i][j].testData; tx++)
            {
                if (flag[i - 1][j - 1] == 0)
                {
                    for (int ty = 0; ty < Space[i - 1][j - 1].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i - 1][j - 1].a[ty])
                        {
                            finally_grade += 20;
                            grade_cnt.a_20++;
                        }
                        if (Space[i][j].a[tx] - Space[i - 1][j - 1].a[ty] == -1 || Space[i][j].a[tx] - Space[i - 1][j - 1].a[ty] == 1)
                        {
                            finally_grade += 10;
                            grade_cnt.a_10++;
                        }
                    }
                }
                if (flag[i - 1][j] == 0)
                {
                    for (int ty = 0; ty < Space[i - 1][j].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i - 1][j].a[ty])
                        {
                            finally_grade += 20;
                            grade_cnt.a_20++;
                        }
                        if (Space[i][j].a[tx] - Space[i - 1][j].a[ty] == -1 || Space[i][j].a[tx] - Space[i - 1][j].a[ty] == 1)
                        {
                            finally_grade += 10;
                            grade_cnt.a_10++;
                        }
                    }
                }
                if (flag[i - 1][j + 1] == 0)
                {
                    for (int ty = 0; ty < Space[i - 1][j + 1].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i - 1][j + 1].a[ty])
                        {
                            finally_grade += 20;
                            grade_cnt.a_20++;
                        }
                        if (Space[i][j].a[tx] - Space[i - 1][j + 1].a[ty] == -1 || Space[i][j].a[tx] - Space[i - 1][j + 1].a[ty] == 1)
                        {
                            finally_grade += 10;
                            grade_cnt.a_10++;
                        }
                    }
                }
                if (flag[i][j - 1] == 0)
                {
                    for (int ty = 0; ty < Space[i][j - 1].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i][j - 1].a[ty])
                        {
                            finally_grade += 20;
                            grade_cnt.a_20++;
                        }
                        if (Space[i][j].a[tx] - Space[i][j - 1].a[ty] == -1 || Space[i][j].a[tx] - Space[i][j - 1].a[ty] == 1)
                        {
                            finally_grade += 10;
                            grade_cnt.a_10++;
                        }
                    }
                }
                if (flag[i - 1][j + 1] == 0)
                {
                    for (int ty = 0; ty < Space[i][j + 1].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i][j + 1].a[ty])
                        {
                            finally_grade += 20;
                            grade_cnt.a_20++;
                        }
                        if (Space[i][j].a[tx] - Space[i][j + 1].a[ty] == -1 || Space[i][j].a[tx] - Space[i][j + 1].a[ty] == 1)
                        {
                            finally_grade += 10;
                            grade_cnt.a_10++;
                        }
                    }
                }
                if (flag[i + 1][j - 1] == 0)
                {
                    for (int ty = 0; ty < Space[i + 1][j - 1].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i + 1][j - 1].a[ty])
                        {
                            finally_grade += 20;
                            grade_cnt.a_20++;
                        }
                        if (Space[i][j].a[tx] - Space[i + 1][j - 1].a[ty] == -1 || Space[i][j].a[tx] - Space[i + 1][j - 1].a[ty] == 1)
                        {
                            finally_grade += 10;
                            grade_cnt.a_10++;
                        }
                    }
                }
                if (flag[i + 1][j] == 0)
                {
                    for (int ty = 0; ty < Space[i + 1][j].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i + 1][j].a[ty])
                        {
                            finally_grade += 20;
                            grade_cnt.a_20++;
                        }
                        if (Space[i][j].a[tx] - Space[i + 1][j].a[ty] == -1 || Space[i][j].a[tx] - Space[i + 1][j].a[ty] == 1)
                        {
                            finally_grade += 10;
                            grade_cnt.a_10++;
                        }
                    }
                }
                if (flag[i + 1][j + 1] == 0)
                {
                    for (int ty = 0; ty < Space[i + 1][j + 1].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i + 1][j + 1].a[ty])
                        {
                            finally_grade += 20;
                            grade_cnt.a_20++;
                        }
                        if (Space[i][j].a[tx] - Space[i + 1][j + 1].a[ty] == -1 || Space[i][j].a[tx] - Space[i + 1][j + 1].a[ty] == 1)
                        {
                            finally_grade += 10;
                            grade_cnt.a_10++;
                        }
                    }
                }
                
            }/*20、10*/
            
            //被计算标记
            flag[i][j] = 1;
        }
    }
}

void Grade_1()
{
    for (int i = 2; i <= 51; i++)
    {
        for (int j = 2; j <= 51; j++)
        {
            //计算 1 违约分
            for (int tx = 0; tx < Space[i][j].testData; tx++)
            {
                if (flag[i - 2][j - 2] == 1)
                {
                    for (int ty = 0; ty < Space[i - 2][j - 2].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i - 2][j - 2].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i - 2][j - 1] == 1)
                {
                    for (int ty = 0; ty < Space[i - 2][j - 1].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i - 2][j - 1].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i - 2][j] == 1)
                {
                    for (int ty = 0; ty < Space[i - 2][j].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i - 2][j].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i - 2][j + 1] == 1)
                {
                    for (int ty = 0; ty < Space[i - 2][j + 1].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i - 2][j + 1].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i - 2][j + 2] == 1)
                {
                    for (int ty = 0; ty < Space[i - 2][j + 2].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i - 2][j + 2].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i - 1][j - 2] == 1)
                {
                    for (int ty = 0; ty < Space[i - 1][j - 2].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i - 1][j - 2].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i - 1][j + 2] == 1)
                {
                    for (int ty = 0; ty < Space[i - 1][j + 2].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i - 1][j + 2].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i][j - 2] == 1)
                {
                    for (int ty = 0; ty < Space[i][j - 2].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i][j - 2].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i][j + 2] == 1)
                {
                    for (int ty = 0; ty < Space[i][j + 2].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i][j + 2].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i + 1][j - 2] == 1)
                {
                    for (int ty = 0; ty < Space[i + 1][j - 2].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i + 1][j - 2].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i + 1][j + 2] == 1)
                {
                    for (int ty = 0; ty < Space[i + 1][j + 2].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i + 1][j + 2].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i + 2][j - 2] == 1)
                {
                    for (int ty = 0; ty < Space[i + 2][j - 2].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i + 2][j - 2].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i + 2][j - 1] == 1)
                {
                    for (int ty = 0; ty < Space[i + 2][j - 1].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i + 2][j - 1].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i + 2][j] == 1)
                {
                    for (int ty = 0; ty < Space[i + 2][j].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i + 2][j].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i + 2][j + 1] == 1)
                {
                    for (int ty = 0; ty < Space[i + 2][j + 1].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i + 2][j + 1].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                if (flag[i + 2][j + 2] == 1)
                {
                    for (int ty = 0; ty < Space[i + 2][j + 2].testData; ty++)
                    {
                        if (Space[i][j].a[tx] == Space[i + 2][j + 2].a[ty])
                        {
                            grade_cnt.a_1++;
                            finally_grade += 1;
                        }
                    }
                }
                
            }/* 1 */
            
            //被计算标记
            flag[i][j] = 0;
        }
    }
}

//计算最终违约分
void Grade()
{
    for (int i = 2; i <= 51; i++)
    {
        for (int j = 2; j <= 51; j++)
        {
            //计算100、50违约分
            for (int x = 0; x < Space[i][j].testData; x++)
            {
                for (int y = 0; y < Space[i][j].testData; y++)
                {
                    if (x == y)
                        break;
                    if (Space[i][j].a[x] == Space[i][j].a[y])
                    {
                        finally_grade += 100;
                        grade_cnt.a_100++;
                    }
                    if (Space[i][j].a[x] - Space[i][j].a[y] == -1 || Space[i][j].a[x] - Space[i][j].a[y] == 1)
                    {
                        finally_grade += 50;
                        grade_cnt.a_50++;
                    }
                }
            }
            
        }
    }
    Grade_20_10();
    Grade_1();
    
    
    /*printf("\t100分违约个数:%d\n\t50分违约个数:%d\n\t20分违约个数:%d\n\t10分违约个数:%d\n\t1分违约个数:%d\n",
           grade_cnt.a_100, grade_cnt.a_50, grade_cnt.a_20, grade_cnt.a_10, grade_cnt.a_1);*/
    printf("\t违约分：%d\n", finally_grade);
}



//输出计算结果到文件
void toFile()
{
	FILE *fp = fopen("/Users/hanoi_ahoj/Desktop/output.csv", "a+");

	if (!fp)
		printf("\t文件输出错误！\n\t请检查:\n");
	fseek(fp, 0L, SEEK_SET);

	fprintf(fp, "违约分：%d\n", finally_grade);
	//fprintf(fp, "\n");
	int i, j, k;
	for (i = 2; i <= 51; i++)
	{
		for (j = 2; j <= 51; j++)
		{
			//fprintf(fp, "");
			for (k = 0; k < Space[i][j].testData; k++)
			{
				fprintf(fp, "%d ", Space[i][j].a[k]);
			}
			fprintf(fp, ",");
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	printf("\t文件输出完成！\n");
}

//int main()
//{

//	readFile();

	//initSpace_sign_gradeCnt();

	//calculate();


	//Grade();



	//toFile();



	//return 0;
//}



