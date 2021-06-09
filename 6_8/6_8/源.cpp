#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int m, n;
	int arr1[100][100];
	int arr2[100][100];
	scanf("%d %d", &m, &n);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			arr2[i][(j + m) % n] = arr1[i][j];
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
}

//int main()
//{
//	int m, n;
//	scanf("%d %d", &m, &n);
//	int arr[100][100];
//	int add[100];
//	for (int i = 0; i < m; i++)
//	{
//		add[i] = 0;
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//			add[i] += arr[i][j];
//		}
//	}
//	for (int i = 0; i < m; i++)
//	{
//		printf("%d\n", add[i]);
//	}
//}

//int main()
//{
//	int t, n;
//	scanf("%d", &t); //t表示几个矩阵
//	int i, j, k;
//	int arr[10][10];
//	int ifit[100] = { 0 };
//	for (i = 0; i < t; i++)
//	{
//		int flag = 0;
//		scanf("%d", &n);
//		for (j = 0; j < n; j++)
//		{
//			for (k = 0; k < n; k++)
//			{
//				scanf("%d", &arr[j][k]);
//
//			}
//		}
//		for (j = 1; j < n; j++) //表示行数
//		{
//			for (k = 0; k <= j - 1; k++)  //表示列数
//			{
//				if (arr[j][k] != 0)
//				{
//					flag = 1;
//					break;
//				}
//			}
//		}
//		if (flag == 0)
//		{
//			ifit[i] = 1;
//		}
//	}
//	for (i = 0; i < t; i++)
//	{
//		if (ifit[i] == 1)
//			printf("YES\n");
//		else
//			printf("NO\n");
//
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int arr[100000];
//	int i, j;
//	int flag = 0;   //1表示有重复
//	int endflag = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < n; i++)  //若相等，变为-1，flag=1
//	{
//		flag = 0;
//		if (arr[i] > 0)
//		{
//			for (j = i + 1; j < n; j++)
//			{
//				if (arr[i] == arr[j])
//				{
//					arr[j] = -1;
//					flag = 1;
//				}
//			}
//			if (flag == 0)
//			{
//				endflag = 1;
//			}
//		}
//		if (endflag == 1)
//		{
//			printf("%d", arr[i]);
//			break;
//		}
//		if (i == n - 1)
//			printf("None");
//	}
//	return 0;
//}

//int main()
//{
//	int x;
//	int bit[4];
//	scanf("%d", &x);
//	for (int i = 0; i < 4; i++)
//	{
//		bit[i] = x % 10;
//		x /= 10;
//	}// 倒序 bit[0]为7
//	for (int i = 0; i < 4; i++)
//	{
//		bit[i] += 9;
//		bit[i] %= 10;
//	}
//	int temp;
//	temp = bit[1];
//	bit[1] = bit[3];
//	bit[3] = temp;
//
//	temp = bit[0];
//	bit[0] = bit[2];
//	bit[2] = temp;
//
//	printf("The encrypted number is ");
//	for (int i = 3; i >= 0; i--)
//	{
//		printf("%d", bit[i]);
//	}
//	return 0;
//}