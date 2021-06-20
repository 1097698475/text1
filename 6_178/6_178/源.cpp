#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

double P(int n, double x);

int main()
{
	int n;
	double x;

	scanf("%d %lf", &n, &x);
	printf("%.2f\n", P(n, x));

	return 0;
}

/* 你的代码将被嵌在这里 */
double P(int n, double x)
{
	if (n == 0)
		return 1 ;
	if (n == 1)
		return x;
	if (n > 1)
		return ((2*n - 1)*P(n - 1, x) - (n - 1)*P(n - 2, x)) / n;
}

//#include <stdio.h>
//
//int Ack(int m, int n);
//
//int main()
//{
//	int m, n;
//
//	scanf("%d %d", &m, &n);
//	printf("%d\n", Ack(m, n));
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//int Ack(int m, int n)
//{
//	if (m == 0)
//	{
//		return n + 1;
//	}
//	if (n == 0 && m > 0)
//	{
//		return Ack(m - 1, 1);
//	}
//	if (m>0&&n>0)
//		return Ack(m-1,Ack(m,n-1));
//}

//#include <stdio.h>
//#define MAXN 10
//
//void f(long int x, char *p);
//
//int main()
//{
//	long int x;
//	char s[MAXN] = "";
//
//	scanf("%ld", &x);
//	f(x, s);
//	printf("%s\n", s);
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//void f(long int x, char *p)
//{
//	int bit[100];
//	int i = 0;
//	int flag = 1; //默认1为正数
//	if (x != 0)
//	{
//		if (x < 0)
//		{
//			x = -x;
//			flag = 0;
//		}
//		while (x > 0)
//		{
//			bit[i] = x % 16;
//			i++;
//			x /= 16;
//		}
//		int count = i;  //count是位数，bit[1]是最低位（最后一位）
//		/*for (i = 0; i < count; i++)
//			printf("%d ", bit[i]);*/
//		if (flag == 0)
//			printf("-");
//		for (i = count - 1; i >= 0; i--)
//		{
//			switch (bit[i])
//			{
//			case 0: printf("0"); break;
//			case 1: printf("1"); break;
//			case 2: printf("2"); break;
//			case 3: printf("3"); break;
//			case 4: printf("4"); break;
//			case 5: printf("5"); break;
//			case 6: printf("6"); break;
//			case 7: printf("7"); break;
//			case 8: printf("8"); break;
//			case 9: printf("9"); break;
//			case 10: printf("A"); break;
//			case 11: printf("B"); break;
//			case 12: printf("C"); break;
//			case 13: printf("D"); break;
//			case 14: printf("E"); break;
//			case 15: printf("F"); break;
//			}
//		}
//	}
//	else
//		printf("0");
//}