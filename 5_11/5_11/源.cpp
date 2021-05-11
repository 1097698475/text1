#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int main()
{
	int m, n; //范围从m到n
	scanf("%d %d", &m, &n);
	int sum = 0;
	int count = 0;
	for (int i = m; i <= n; i++)  //从m开始判断是否为素数，一直到n
	{
		int ying = 0;  //因数一开始为0
		for (int j = 1; j <= i; j++)  //公约数从1开始，一直到该数本身，若约数==2，表示为素数
		{
			if (i%j == 0)
			{
				ying++;
			}
		}
		if (ying == 2)
		{
			count++;
			sum += i;
			//printf("%d\n", i);
		}
	}
	printf("%d %d", count, sum);
	return 0;
}

//int main()
//{
//	int a, b;
//	char ch;
//	scanf("%d", &a);
//	int flag = 1;
//	for (int i = 0;; i++)
//	{
//		scanf("%c", &ch);
//		if (ch != '=')
//		{
//			scanf("%d", &b);
//			switch (ch)
//			{
//			case '+':a = a + b; break;
//			case '-':a = a - b; break;
//			case '*':a = a * b; break;
//			case '/': 
//			{
//				if (b == 0)
//				{
//					printf("ERROR");
//					flag = 0;
//				}
//				else
//					a = a / b;
//				break;
//			}
//			default:printf("ERROR"); flag = 0; break;
//			}
//		}
//		else
//		{
//			flag = 0;
//			printf("%d", a);
//		}
//		if (flag == 0)
//			break;
//	}
//	return 0;
//}

//#include<math.h>
//int main()
//{
//	double a, b, c;
//	scanf("%lf %lf %lf", &a, &b, &c);
//	double slt1, slt2;  //方程的解
//
//	if (a == 0)  //一元一次
//	{
//		if (b == 0)
//		{
//			if (c == 0)
//			{
//				printf("Zero Equation");
//			}
//			else  //c不等于0
//			{
//				printf("Not An Equation");
//			}
//		}
//		else  //b不等于0
//		{
//			slt1 = -c / b;
//			printf("%.2f", slt1);
//		}
//	}
//	else  //a不等于0
//	{
//		double disc;  //根判别式
//		disc = b * b - 4 * a * c;
//		//printf("%.2f", disc);
//
//		if (disc > 0)  //根可作为一个整体直接赋给slt，不需要讨论b与c
//		{
//			slt1 = (-b + sqrt(disc)) / (2 * a);
//			slt2 = (-b - sqrt(disc)) / (2 * a);
//			if (slt1 > slt2)
//				printf("%.2f\n%.2f", slt1, slt2);
//			else
//				printf("%.2f\n%.2f", slt2, slt1);
//		}
//		else if (disc == 0)
//		{
//			slt1 = -b / (2 * a);
//			printf("%.2f", slt1);
//		}
//		else  //判别式小于0，复数解，根不能作为一个整体直接赋给slt，需要讨论b与c
//		{
//			disc = -disc;  //判别式变成相反数才能根号
//			double from = -b / (2 * a);  //实部，要判断实部是否为0
//			double back = sqrt(disc) / (2 * a);
//
//			if (b != 0)
//			{
//				printf("%.2f+%.2fi\n%.2f-%.2fi", from, back, from, back);
//			}
//
//			else  //实部为0，只打印虚部即可
//			{
//				printf("%.2fi\n-%.2fi", back, back);
//			}
//		}
//	}
//	return 0;
//}