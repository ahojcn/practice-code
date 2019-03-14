#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define N 3
#define WUCHA 1e-6

int main()
{
	double c = 0;
	
	double a[N][N + 1] = {
		{12, -3, 3, 15},
		{-18, 3, -1, -15},
		{1, 1, 1, 6}
	};

	int r = 0;
	for (int k = 0; k < N - 1; k++)
	{
		r = k;
		for (int i = k; i < N; i++)
		{
			if (fabs(a[i][k]) > fabs(a[r][k]))
			{
				r = i;
			}
		}
		if (fabs(a[r][k]) < WUCHA)
		{
			printf("\n ÏûÔªÊ§°Ü\n");
			exit(0);
		}
		if (r > k)
		{
			for (int j = k; j < N + 1; j++)
			{
				c = a[k][j];
				a[k][j] = a[r][j];
				a[r][j] = c;
			}
		}
		for (int i = k + 1; i < N; i++)
		{
			a[i][k] = a[i][k] / a[k][k];
			for (int j = k + 1; j < N + 1; j++)
			{
				a[i][j] = a[i][j] - a[i][k] * a[k][j];
			}
		}
	}

	a[N - 1][N] = a[N - 1][N] / a[N - 1][N - 1];

	for (int k = N - 2; k >= 0; k--)
	{
		c = 0;
		for (int j = k + 1; j < N + 1; j++)
		{
			c = c + a[k][j] * a[j][N];
		}
		a[k][N] = (a[k][N] - c) / a[k][k];
	}

	for (int k = 0; k < N; k++)
	{
		printf("\na[%d]=%12.8f\n", k, a[k][N]);
	}

	system("pause");

	return 0;
}
