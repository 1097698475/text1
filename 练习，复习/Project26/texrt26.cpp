#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define nmax 100


//int main()
//{
//	int sum, fen1, fen2, fen5, count = 0;
//	scanf("%d", &sum);
//	for (fen5 = 20; fen5 >= 1; fen5--)
//		for (fen2 = 50; fen2 >= 1; fen2--)
//			for (fen1 = 100; fen1 >= 1; fen1--)
//			{
//				if (fen1 * 1 + fen2 * 2 + fen5 * 5 == sum)
//				{
//					int total = fen1 + fen2 + fen5;
//					count++;
//					printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", fen5, fen2, fen1, total);
//				}
//			}
//	printf("count = %d", count);
//	return 0;
//}


//int main()
//{
//	int sum, fen1, fen2, fen5, count = 0;
//	scanf("%d", &sum);
//	for (fen5 = 1; fen5 < 20; fen5++)
//		for (fen2 = 1; fen2 < 50; fen2++)
//			for (fen1 = 1; fen1 < 100; fen1++)
//			{
//				if (fen1 * 1 + fen2 * 2 + fen5 * 5 == sum)
//				{
//					int total = fen1 + fen2 + fen5;
//					count++;
//					printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", fen5, fen2, fen1, total);
//				}
//			}
//	printf("count = %d", count);
//	return 0;
//}


//int main()
//{
//	double limit;
//	scanf("%lf", &limit);
//	int i;
//	int front;
//	double sum = 0;
//	for (i = 1;; i++)
//	{
//		if (i % 2 == 1)
//			front = 1;
//		else
//			front = -1;
//		sum += (double)front / (i*3-2);
//		printf("%lf\n", sum);
//		if (sum <= limit)
//			break;
//	}
//	printf(".6f", sum);
//	return 0;
//}


//void printmenu();
//double print(int);
//int main()
//{
//	printmenu();
//	int usern;
//	int count = 0;
//	do
//	{
//		scanf("%d", &usern);
//		count++;
//		if (count > 5)
//			break;
//		if(usern>=0)
//			printf("price = %.2f\n",print(usern));
//		
//	} while (usern != 0);
//	return 0;
//}
//void printmenu()
//{
//	printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
//}
//double print(int number)
//{
//	switch (number)
//	{
//	case 1:return 3.00;
//	case 2:return 2.50;
//	case 3:return 4.10;
//	case 4:return 10.20;
//	default:return 0.00;
//	}
//}


//void print(int,int);
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i;
//	int middle = n / 2 + 1;
//	for (i = 1; i <= n; i ++)
//	{
//		if (i <= middle)
//			print(i, middle);
//		else
//			print(middle * 2 - i, middle);
//	}
//}
//void print(int line,int middle)
//{
//	int i;
//	for (i = 1; i <= middle - line; i++)
//	{
//		printf("  ");
//	}
//	for (i = 1; i <= line * 2 - 1; i++)
//	{
//		printf("* ");
//	}
//	printf("\n");
//}

//int main()
//{
//	int text;
//	int sum = 0;
//	do
//	{
//		scanf("%d", &text);
//		if (text>0 && text % 2 == 1)
//			sum += text;
//
//	} while (text > 0);
//	printf("%d", sum);
//}


//int main()
//{
//	int num, sum = 0, i;
//	for (i = 1;; i++)
//	{
//		scanf("%d", &num);
//		if (num > 0 && num % 2 == 1)
//		{
//			sum = sum + num;
//		}
//		if (num <= 0)
//		{
//			break;
//		}
//	}
//	printf("%d", sum);
//
//}