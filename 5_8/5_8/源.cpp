#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define nmax 101

int main()
{
	int start[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &start[i]);
	}
	int n; //有几道题
	scanf("%d", &n);
	int student; //给哪个选手加分
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &student);
		student -= 1;
		switch (student)
		{
		case 0: start[student] += 10; break;
		case 1: start[student] += 10; break;
		case 2: start[student] += 10; break;
		case 3: start[student] += 10; break;
		case 4: start[student] += 10; break;
		case 5: start[student] += 10; break;
		case 6: start[student] += 10; break;
		case 7: start[student] += 10; break;
		case 8: start[student] += 10; break;
		case 9: start[student] += 10; break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d", start[i]);
		if (i != 9)
			printf(" ");
	}
	return 0;
}

//int main()
//{
//	int n, count;
//	int test[nmax];
//	scanf("%d %d", &n, &count); // n是数字个数，count是冒泡几次
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &test[i]);
//	}
//	int x;
//	int i;
//	for (i = 0; i < count; i++)
//	{
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (test[j] > test[j + 1])
//			{
//				x = test[j];
//				test[j] = test[j + 1];
//				test[j + 1] = x;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d", test[i]);
//		if (i != n - 1)
//			printf(" ");
//	}
//	return 0;
//}

//int main()
//{
//	int x, count = 0;
//	scanf("%d", &x);
//	int bit[20];
//	for (int i = 0;; i++)
//	{
//		bit[i] = x % 10;
//		x = x / 10;
//		count++;
//		if (x == 0)
//			break;
//	}
//	for (int i = count-1; i >= 0; i--)
//	{
//		printf("%d ", bit[i]);
//	}
//	return 0;
//}