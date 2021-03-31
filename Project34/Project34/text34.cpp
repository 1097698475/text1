#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

#include <stdio.h>

int fib(int n);
void PrintFN(int m, int n);

int main()
{
	int m, n, t;

	scanf("%d %d %d", &m, &n, &t);
	printf("fib(%d) = %d\n", t, fib(t));
	PrintFN(m, n);

	return 0;
}

/* 你的代码将被嵌在这里 */
int arr[100] = { 1,1 };
int fib(int x)
{
	if (x == 1)
		return 1;
	else if (x == 2)
		return 1;
	else
	{
		for (int i = 2; i < x; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		return arr[x - 1];
	}
}
void PrintFN(int m, int n)
{
	//先计算到n的兔子数，并存入数组中
	//for(i从m到n){while(arr[i]<m) 如果元素大于的话记录i,continue,下一次遍历数组从i开始
	int i = 1;
	while (arr[i] <= n)
	{
		//printf("%d ", arr[i]);
		i++;
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int begin = 0;
	i = 0;
	while (arr[i] <= m)
	{
		begin = i;//begin是数组的序号，若要表示第几个兔子数，需要+1
		i++;
	}
	//printf("fib(%d) = %d\n", begin+1, fib(begin+1));
	//printf("%d\n", begin+1);
	int flag = 1;
	int count = 1;
	for(int text=m;text<=n;text++)//从m开始，判断m是否是兔子数->有个循环
	{
		int a = begin;//让begin保持不变
		if (m != 1)
		{
			do  //判断text是否兔子数，从arr[begin]开始判断（一开始一定小于
			{
				if (arr[a] == text)
				{
					if (count == 1)
						printf("%d", text);
					else
						printf(" %d", text);
					flag = 0;
					count++;
					break;
				}
				a++;
			} while (arr[a] <= text);
		}
	}
	if (flag)
		printf("No Fibonacci number");
}




//int fib(int x)
//{
//	if (x == 1)
//		return 1;//第一个斐波那契数为1
//	else if (x == 2)
//		return 1;//第二个斐波那契数为1
//	else
//		return fib(x - 1) + fib(x - 2);//从第三个数开始就回去找Fib（2）和Fib（1）
//									   //不断回去找直到找到为止
//}
//void PrintFN(int m, int n)
//{
//	int flag = 0;
//	for (int i = m; i <= n; i++)
//	{
//		if (fib(i) == i)
//		{
//			printf("%d ", i);
//			flag = 1;
//		}
//	}
//	if (flag == 0)
//		printf("No Fibonacci number");
//}



//#include <stdio.h>
//
//int factorsum(int number);//判断是否是完数：恰好等于除自己外的因子的和
//void PrintPN(int m, int n);//输出区间内的完数，并且写成6=1+2+3
//
//int main()
//{
//	int m, n;
//
//	scanf("%d %d", &m, &n);
//	if (factorsum(m) == m) printf("%d is a perfect number\n", m);
//	if (factorsum(n) == n) printf("%d is a perfect number\n", n);
//	PrintPN(m, n);
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//int factorsum(int number)
//{
//	int add = 0;
//	for (int i = 1; i < number / 2 + 1; i++)
//	{
//		if (number%i == 0)
//		{
//			add += i;
//		}
//	}
//	if (add == number)
//		return number;
//	else
//		return 0;
//}
//void PrintPN(int m, int n)
//{
//	int arr[100];
//	int flag = 0;
//	for (int i = m; i <= n; i++)
//	{
//		if (factorsum(i) == i)
//		{
//			int k = 0;
//			int count = 0;
//			flag = 1;
//			for (int j = 1; j < i / 2 + 1; j++)
//			{
//				if (i%j == 0)
//				{
//					arr[k++] = j;
//					count++;
//				}
//			}
//			//printf("%d\n", count);
//			printf("%d = ", i);
//			for (int a = 0; a < count; a++)
//			{
//				if (a < count - 1)
//					printf("%d + ", arr[a]);
//				else
//					printf("%d", arr[a]);
//			}
//			printf("\n");
//		}
//	}
//	if (flag == 0)
//		printf("No perfect number");
//}


//int main()
//{
//	while (x = 10~100)
//	{
//		x%3==2,x%5==1x%7==6
//	}
//}


//int main()
//{
//	double x1, y1, x2, y2;  //(x1,y1+(x2,y2)
//	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
//	double x3 = x1 + x2;
//	double y3 = y1 + y2;
//
//	printf("(%.1f, %.1f)", x3, y3);
//	return 0;
//}


//#include <stdio.h>
//
//int fib(int n);   //返回第n项兔子数
//void PrintFN(int m, int n);
//
//int main()
//{
//	int m, n, t;
//
//	scanf("%d %d %d", &m, &n, &t);
//	printf("fib(%d) = %d\n", t, fib(t));
//	//PrintFN(m, n);
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//int fib(int n)
//{
//	if (n == 1 || 2)
//		return 1;
//	else
//	{
//		return fib(n - 1) + fib(n - 2);
//		
//	}
//}