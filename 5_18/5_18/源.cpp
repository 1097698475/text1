#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<iostream>
using namespace std;

void input(int, int a[], int);

int main()
{
	int n = 0, a[100], x = 0;
	input(n, a, x);

	int i = 0;
	while (x > a[i] && i < n)
		i++;   //i为x要插入的位置

	for (int j = n; j > i; j--)
	{
		a[j] = a[j - 1];
	}
	a[i] = x;

	for (int k = 0; k < n + 1; k++)
		cout << a[k] << " ";
	return 0;
}
void input(int n, int a[100], int x)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> x;
}

//void input(int a[], int n);
//
//int main()
//{
//	int n, i, j, x, a[11];
//
//	scanf("%d", &n);
//	input(a, n);                 //输入n个数到数组a中
//	scanf("%d", &x);                //输入插入的数 
//	i = 0;
//	while (a[i] < x && i < n)
//		i++;                 //右移
//	for (j = n - 1; j >= i; j--)
//	{
//		a[j + 1] = a[j];          //左移
//	}
//	a[i] = x;                   //判断插入的数在哪位
//	for (i = 0; i < n + 1; i++)
//		printf("%d ", a[i]);
//	return 0;
//}
//void input(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//}

//int main()
//{
//	int n, arr[100];
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		scanf("%d", &arr[i]);
//
//	int x;
//	scanf("%d", &x);
//
//	for (int i = n - 1;; i--)
//	{
//		if (x < arr[i])
//		{
//			arr[i + 1] = arr[i];
//		}
//		if (i != 0)
//		{
//			if (x >= arr[i - 1])
//			{
//				arr[i] = x;
//				break;
//			}
//		}
//		else
//		{
//			arr[i] = x;
//			break;
//		}
//	}
//
//	for (int i = 0; i <= n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}