#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define M 50
#define N 6
#define B 2
int main()
{
	int score[B][M][N];
	int sum[B][M];
	int m, n, b;
	int i, j;
	for (b = 0; b < 2; b++)
	{
		printf("%d班\n", b + 1);
		printf("学生人数 ：");
		scanf("%d", &m);
		printf("课程数量 ：");
		scanf("%d", &n);
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &score[b][m][n]);
		putchar('\n');
		printf("学号\t语文\t数学\t英语\t总分");
		for (i = 0; i < m; i++)
		{
			printf("%d\t", i + 1);
			sum[b][i] = 0;
			for (j = 0; j < n; j++)
			{
				printf("%d\t", score[b][i][j]);
				sum[b][i] = sum[b][i] + score[b][i][j];
			}
			printf("%d\n", sum[b][i]);
		}
		printf("\n");
	}
}


//#define M 50
//#define N 10
//int main()
//{
//	int score[M][N];
//	int m, n;
//	int sum[M];
//	int i, j;
//	printf("学生人数 ：");
//	scanf("%d", &m);
//	printf("课程数量 ：");
//	scanf("%d", &n);
//	for (i = 0; i < m; i++)
//		for (j = 0; j < n; j++)
//			scanf("%d",&score[i][j]);
//	//putchar('\n');
//	printf("\n");
//	printf("学号\t语文\t数学\t英语\t总分\n");
//	for (i = 0; i < m; i++)
//	{
//		printf("%d\t", i + 1);
//		sum[i] = 0;
//		for (j = 0; j < n; j++)
//		{
//			printf("%3d\t", score[i][j]);
//			sum[i] = score[i][j] + sum[i];
//		}
//		
//		printf("%d\n", sum[i]);
//	}
//}


//int main()
//{
//	int a[3][4] = { 1,2,3,4,9,8,7,6,-10,10,-5,2 };
//	int i, j, hang, lie,max;
//	hang = 0, lie = 0, max = a[0][0];
//	for(i = 0; i < 3;i++)
//		for (j = 0; j < 4; j++)
//		{
//			if (a[i][j] > max)
//			{
//				max = a[i][j];
//				hang = i;
//				lie = j;
//			}
//		}
//	printf("max = %d,row = %d,colum = %d", max, hang, lie);
//}


//int main()
//{
//	int a[][4] = { 0,1,0,0,1,0,0,0,2,6,4 };
//	int i;
//	for(i=0;i<12;i++)
//	{
//		printf("%4d", a[0][i]);
//		if (i % 4 == 3)
//		{
//			printf("\n");
//		}
//	}
//}


//int main()
//{
//	int a[3][4];
//	int hang, lie;
//	hang = sizeof(a) / sizeof(a[0]);
//	lie = sizeof(a[0]) / sizeof(int);
//	printf("%d %d", hang, lie);
//}


//int main()
//{
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int i;
//	for (i = 0; i < 12; i++)
//		printf("%4d", a[0][i]);
//
//}


//int main()
//{
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int i, j;
//	for (i = 0; i < 3; i++)
//		for (j = 0; j < 4; j++)
//			printf("%4d", a[0][4 * i + j]);
//}


//int main()
//{
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int i, j;
//	for (i = 0; i < 3; i++)
//		for (j = 0; j < 4; j++)
//			printf("%4d", a[i][j]);
//
//}


//int main()
//{
//	int score[10], i, num[5] = { 0,0,0,0,0 };
//	for (i = 0; i < 10; i++)
//		scanf("%d", &score[i]);
//	//putchar('\n');
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		switch (score[i] / 10)
//		{
//		case 0:
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//			num[0]++;
//			break;
//		case 6:
//			num[1]++;
//			break;
//		case 7:
//			num[2]++;
//			break;
//		case 8:
//			num[3]++;
//			break;
//		case 9:
//		case 10:
//			num[4]++;
//			break;
//		}
//	}
//	printf("各分数段的人数为：\n");
//	printf("0-60\t60-69\t70-79\t80-89\t90-100\n");
//	for (i = 0; i < 5; i++)
//		printf("%d\t", num[i]);
//	return 0;
//}


//int main()
//{
//	int i, j, del=0,x=5;
//	int a[10] = { 1,2,3,4,5,5,7,8,9,10 };
//	for (i = 0; i < 10; i++)
//		printf("%d ", a[i]);
//	putchar('\n');
//	for (i = 0; i < 10-del; i++)
//	{
//		if (a[i] == 5)
//		{
//			for (i; i < 10; i++)
//				a[i] = a[i + 1];
//			del++;
//			i--;
//		}
//	}
//	for (i = 0; i < 10 - del; i++)
//		printf("%d ", a[i]);
//}


//int main()
//{
//	int i, score[11],x,j;
//	for (i = 0; i < 10; i++)
//		scanf("%d", &score[i]);
//	printf("\n");
//	printf("待插入数据 ： ");
//	scanf("%d", &x);
//	for (i = 0; i < 10; i++)
//	{
//		if (x < score[i])
//		{
//			for (j=10;j>=i;j--)
//				score[j + 1] = score[j];
//			score[i] = x;
//			break;
//		}
//	}
//	for (i = 0; i < 11; i++)
//		printf("%4d", score[i]);
//}


//int main()
//{
//	int score[10],i,t;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &score[i]);
//	}
//	for (i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 30-i-1; j++)
//		{
//			if (score[i] > score[i + 1])
//			{
//				t = score[i + 1];
//				score[i + 1] = score[i];
//				score[i] = t;
//			}
//		}
//	}
//	for (i = 0; i < 10; i++)
//		printf("%4d", score[i]);
//}


//int main()
//{
//	int score[20];
//	int i,a,num=0;
//	for (i = 0; i < 20; i++)
//	{
//		scanf("%d", &score[i]);
//	}
//	printf("请输入想查找的分数 ： ");
//		scanf("%d\n", &a);
//	
//		for (i = 0; i < 20; i++)
//		{
//			if (score[i] == a)
//			{
//				num++;
//				printf("score[%d] = %d", i, a);
//			}
//		}
//		printf("有%d个同学分数为%d", num, a);
//}


//int main()
//{
//	int a[10];
//	int min, max;
//	scanf("%d", &a[0]);
//	min = max = a[0];
//	for (int i = 1; i <= 10; i++)
//	{
//		scanf("%4d", &a[1]);
//		if (a[i] < a[0])
//		{
//			a[0] = a[i];
//		}
//		max = max > a[i] ? max : a[i - 1];
//
//	}
//}



//int main()
//{
//	int a[20];
//	int max, min;
//	scanf("%d", &a[0]);
//	min = a[0];
//	max = a[0];
//	for (int i = 1; i < 20; i++)
//	{
//		scanf("%d", &a[i]);
//		min = min < a[i] ? min : a[i];
//		max = max > a[i] ? max : a[i - 1];
//
//	}
//	printf("%d %d", min, max);
//}


//int main()
//{
//	int a[20] = { 1,1 };
//	for (int i = 2; i < 20; i++)
//		a[i] = a[i - 1] + a[i - 2];
//	for (int i = 0; i < 20; i++)
//	{
//		if (i % 5 == 0)
//			printf("\n");
//		printf("%8d", a[i]);
//		
//	}
//}


//int main()
//{
//	int a[20], i;
//	a[0] = 1, a[1] = 1;
//	printf("%d %d ", a[0], a[1]);
//	for (i = 2; i <= 19; i++)
//	{
//		a[i] = a[i - 1] + a[i - 2];
//		printf("%d ", a[i]);
//
//	}
//}
