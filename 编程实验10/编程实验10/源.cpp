#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	char str[100];
	for (int i = 0; i < 100; i++)
	{
		scanf("%c", &str[i]);
		if (str[i] == '\n')
			break;
	}
	//gets_s(str);
	printf("%s", str);
}

//int main()
//{
//	int arr[3][3];
//	int max, min;
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	max = min = arr[0][0];
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			if (arr[i][j] > max)
//				max = arr[i][j];
//			if (arr[i][j] < min)
//				min = arr[i][j];
//		}
//	}
//	printf("max=%d min=%d", max, min);
//	return 0;
//}

//#include <stdio.h>
//#define MAXN 20
//
//void delchar(char *str, char c);
////void ReadString(char s[]); /* 由裁判实现，略去不表 */
//
//int main()
//{
//	char str[MAXN], c;
//
//	scanf("%c\n", &c);
//	//ReadString(str);
//	for (int i = 0;; i++)
//	{
//		scanf("%c", &str[i]);
//		if (str[i] == '\n')
//			break;
//	}
//	delchar(str, c);
//	printf("%s\n", str);
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//#include<string.h>
//void delchar(char *str, char c)
//{
//	int i, j, l = strlen(str);
//	for (i = 0; i < l; i++)
//	{
//		while (str[i] == c)		//处理元素
//		{
//			for (j = i; j < l; j++)
//			{		//str[i+1]后的元素左移
//				str[j] = str[j + 1];
//			}
//			l--;              //字符串长度减一
//		}
//	}
//}
//#include <stdio.h>
//#define MAXN 10
//
//int search(int list[], int n, int x);
//
//int main()
//{
//	int i, index, n, x;
//	int a[MAXN];
//
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//	scanf("%d", &x);
//	index = search(a, n, x);
//	if (index != -1)
//		printf("index = %d\n", index);
//	else
//		printf("Not found\n");
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//int search(int list[], int n, int x)
//{
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		if (list[i] == x)
//		{
//			return i;
//		}
//		if (i == n - 1)
//			return -1;
//	}
//	return -1;
//}

//#include <stdio.h>
//#include <string.h>
//
//#define MAXS 10
//
//void Shift(char s[]);
//
//void GetString(char s[]); /* 实现细节在此不表 */
//
//int main()
//{
//	char s[MAXS];
//
//	GetString(s);
//	Shift(s);
//	printf("%s\n", s);
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//void Shift(char s[])
//{
//	int count;
//	f/*or (count = 0;; count++)
//	{
//		if (s[count] == '\0')
//			break;
//	}
//	char temp[3];
//	int i;
//	for (i = 0; i < count; i++)
//	{
//		if(i<3)
//		{
//			temp[i] = s[i];
//		}
//		else
//		{
//			s[i - 3] = s[i];
//		}
//	}
//	s[i] = temp[0];
//	s[i + 1] = temp[1];
//	s[i + 2] = temp[2];
//}*/

//#include <stdio.h>
//
//#define MAXN 10
//
//double f(int n, double a[], double x);
//
//int main()
//{
//	int n, i;
//	double a[MAXN], x;
//
//	scanf("%d %lf", &n, &x);
//	for (i = 0; i <= n; i++)
//		scanf("%lf", &a[i]);
//	printf("%.1f\n", f(n, a, x));
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//double f(int n, double a[], double x)
//{
//	int i, j;
//	double item = 1;
//	double add = 0;
//	for (i = 0; i <= n; i++)
//	{
//		add = add + a[i] * item;
//		item *= x;
//	}
//	return add;
//}