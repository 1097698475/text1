#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	char test = 'A';
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - i; j++)
//		{
//			printf("%c ", test);
//			test++;
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int n; //n>=2,n<=50
//	scanf("%d", &n);
//	int count, entercount = 0;
//	for (int i = 2; i <= n; i++)
//	{
//		count = 0;
//		for (int j = 1; j < i; j++)
//		{
//			if (i%j == 0)
//				count++;
//		}
//		if (count == 1)
//		{
//			printf("%5d", i);
//			entercount++;
//		}
//		if (entercount == 8)
//		{
//			printf("\n");
//			entercount = 0;
//		}
//	}
//	return 0;
//}

//int func(int ,int );
//int main()
//{
//	int a, n;
//	scanf("%d %d", &a, &n);
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		sum += func(i, a);
//	}
//	printf("s = %d", sum);
//	return 0;
//}
//int func(int n,int a)
//{
//	int result = 0;
//	int item = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		result += a * item;
//		item *= 10;
//	}
//	return result;
//}

//int main()
//{
//	int n;
//	char arr[81], temp[81];
//	scanf("%d", &n);
//	int i = 0;
//	int lnum, index;
//	gets_s(arr);
//	lnum = strlen(arr);
//	index = i;
//	for (i = 1; i < n; i++)
//	{
//		gets_s(temp);
//		if (lnum < strlen(temp))
//		{
//			strcpy(arr, temp);
//			lnum = strlen(arr);
//		}
//	}
//	printf("The longest is: %s", arr);
//	return 0;
//}

//int main()
//{
//	char arr[5][100];
//	int i, j;
//	for (i = 0; i < 5; i++)
//	{
//		scanf("%s", arr[i]);
//	}
//	for (i = 0; i < 5; i++)
//		printf("%s\n", arr[i]);
//	int index[5] = { 0,1,2,3,4 };
//	char temp[100];
//	for (i = 0; i < 4; i++)
//	{
//		for (j = i + 1; j < 5; j++)
//		{
//			if (strcmp(arr[i], arr[j]) > 0)
//			{
//				strcpy(temp, arr[i]);
//				strcpy(arr[i], arr[j]);
//				strcpy(arr[j], temp);
//			}
//			/*if (strcmp(arr[index[i]], arr[index[j]]) > 0)
//			{
//				temp = index[i];
//				index[i] = index[j];
//				index[j] = temp;
//			}*/
//		}
//	}
//	printf("After sorted:\n");
//	for (i = 0; i < 5; i++)
//		printf("%s\n", arr[index[i]]);
//	return 0;
//}

//double fact(int n);
//double factsum(int n);
//
//int main()
//{
//	int n;
//
//	scanf("%d", &n);
//	printf("fact(%d) = %.0f\n", n, fact(n));
//	printf("sum = %.0f\n", factsum(n));
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//double fact(int n)
//{
//	if (n == 1)
//		return 1;
//	else if (n == 0)
//		return 1;
//	else
//		return n*fact(n - 1);
//}
//double factsum(int n)
//{
//	int sum = 0;
//	if (n == 0)
//		return 0;
//	else
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			sum += fact(i);
//		}
//		return sum;
//	}
//	
//}