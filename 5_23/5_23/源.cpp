#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n;
	int arr[10][10];
	int add = 0;
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
			if (i == n - 1)
				arr[i][j] = 0;  //最后一行赋值为0
			if (i + j == n - 1)
				arr[i][j] = 0;
		}
		arr[i][n-1] = 0;  //最后一列赋值为0
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			add += arr[i][j];
		}
	}
	printf("%d", add);
	return 0;
}

//int main()
//{
//	int score[4][4], nopast[4] = { 0 };
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			scanf("%d", &score[i][j]);
//		}
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (score[j][i] < 60)
//				nopast[i]++;
//		}
//		printf("%d ", nopast[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int a1[10][10], a2[10][10];
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%d", &a1[i][j]);
//			a2[j][i] = a1[i][j];
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%4d", a2[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int max, min;
//	int arr[3][3];
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			scanf("%d", &arr[i][j]);
//			if (i == 0 && j == 0)
//				max = min = arr[i][j];
//			if (max < arr[i][j])
//				max = arr[i][j];
//			if (min > arr[i][j])
//				min = arr[i][j];
//		}
//	}
//	printf("max=%d min=%d", max, min);
//	return 0;
//}