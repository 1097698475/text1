#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

#include <stdio.h>

void dectobin(int n);

int main()
{
	int n;

	scanf("%d", &n);
	dectobin(n);

	return 0;
}

/* 你的代码将被嵌在这里 */
void dectobin(int n)// 将正整数n转换为二进制后输出
{

}


//#include <stdio.h>
//
//int f(int n);
//
//int main()
//{
//	int n;
//
//	scanf("%d", &n);
//	printf("%d\n", f(n));
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//int f(int n)  //第一斐波那契数为1
//{
//	int x;
//	int sum = 1;
//	if (n == 1)
//		return sum;
//	if (n == 2)
//		return sum;
//	if (n >= 3)
//	{
//		return  f(n - 1) + f(n - 2);
//	}
//}





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
//		return n + 1;
//	if (n == 0 && m > 0)
//	{
//		Ack(m - 1, 1);
//	}
//	if (n > 0 && m > 0)
//	{
//		Ack(m - 1, Ack(m, n - 1));
//	}
//
//}



//#include <stdio.h>
//
//double fn(double x, int n);
//
//int main()
//{
//	double x;
//	int n;
//
//	scanf("%lf %d", &x, &n);
//	printf("%.2f\n", fn(x, n));
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
////double fn(double x, int n)  //x是底数，n是加到的指数，x-x^2+x^3-x^4
////{
////	
////}
//double fn(double x, int n)
//{
//	//先计算每一个（不带符号），用循环，用flag存+-，再用递归加起来
//	double sum, flag = 1;  //sum储存每一位
//	if (n == 1)
//		return x;
//	if (n % 2 == 0)  //偶数为负
//		flag = -1;
//	sum = x;
//	for (int i = 1; i < n; i++)
//	{
//		sum *= x;  //不带符号
//	}
//	return flag * sum + fn(x, n-1);
//}


//double fn(double x, int n)
//{
//	double sum = 1, flage = 1, i;
//	if (n == 1)
//		return x;
//	if ((n - 1) % 2 == 0)
//		flage = 1;
//	else flage = -1;
//	for (i = 1; i <= n; i++)
//	{
//		sum *= x;
//	}
//	return flage * sum + fn(x, n - 1);
//}






//#include <stdio.h>
//
//double calc_pow(double x, int n);
//
//int main()
//{
//	double x;
//	int n;
//
//	scanf("%lf %d", &x, &n);
//	printf("%.0f\n", calc_pow(x, n));
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */  //计算x的n次幂（n>=1
//double calc_pow(double x, int n) //函数calc_pow应返回x的n次幂的值。建议用递归实现
//{
//	//x=2,n=3,则计算2的3次幂
//	double pow = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		pow *= x;
//	}
//	return pow;
//}





//#include <stdio.h>
//
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
//double fact(int n)  //n!
//{
//	int result;
//	if (n > 0)
//		result = n * fact(n - 1);
//	else
//		result = 1;
//	return result;
//}//have been tested
//
//double factsum(int n)
//{
//	//循环加fact
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int fac = fact(i);
//		sum += fac;
//	}
//	return sum;
//}


//int main()
//{
//	int x;
//	scanf("%d",&x);
//	int y;
//	if (x >= 0)
//		if (x > 0) y = 1;
//		else y = 0;
//	else y = -1;
//	printf("%d", y);
//
//	/*int y = 0;
//	if (x >= 0);
//	if (x > 0) y = 1;
//	else y = -1;
//	printf("%d", y);*/
//}


//#include <stdio.h>
//
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
//double fact(int n)  //n!
//{
//	int result = 1;
//	if (n > 0)
//		result = n * fact(n - 1);
//	else
//		result = 1;
//	return result;
//}
//double factsum(int n)
//{
//	int result = fact(n);
//	int sum = 0;
//	if (n > 0)
//		sum = result + fact(n - 1);
//	else
//		result = 1;
//	return result;
//}





//#include <stdio.h>
//#include <math.h>
//
//int search(int n);
//
//int main()
//{
//	int number;
//
//	scanf("%d", &number);
//	printf("count=%d\n", search(number));
//
//	return 0;
//}
//
//
///* 你的代码将被嵌在这里 */
////统计给定区间内的三位数中有两位数字相同的完全平方数（如144、676）的个数
//int search(int n)  //101~n,返回满足该条件的数的个数
//{
//	//生成11^2到31^2的数
//	int perfect[21];  //101~999有21个完全平方数
//	int object[21];   //101~999符合条件的完全平方数
//	int ojcount = 0;  //符合条件的个数
//
//	for (int i = 0; i <= 20; i++)  //21次循环
//	{
//		perfect[i] = pow(11 + i, 2);  //将完全平方数读入perfect数组
//		int a = perfect[i];   //不改变数组的完全平方数
//		int bit[3] = { 0 };  //将每一位放在数组bit中，
//
//		//第i个元素的每一位数字都存入bit数组
//		for (int j = 0; j < 3; j++)
//		{
//			bit[j] = a % 10;
//			a /= 10;
//		}
//		if (bit[0] == bit[1] || bit[1] == bit[2] || bit[0] == bit[2])
//		{
//			object[ojcount] = perfect[i];  //将符合条件的完全平方数存到object
//			ojcount++;
//		}
//	}
//	
//	//i = 101~n与object数组元素比较，i等于object则count+1
//	int count = 0;
//	for (int i = 101; i <= n; i++)
//	{
//		for (int j = 0; j < ojcount; j++)
//		{
//			if (i == object[j])
//				count++;
//		}
//	}
//	return count;
//}


//#include <stdio.h>

//int sum(int n);
//
//int main()
//{
//	int n;
//
//	scanf("%d", &n);
//	printf("%d\n", sum(n));
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//int sum(int n)//该函数对于传入的正整数n返回1+2+3+…+n的和,若n不是正整数则返回0
//{
//	int result = 0;
//	if (n > 0)
//		result = n + sum(n - 1); //递归减1，直至n等于1；
//	else
//		result = 0; //要求输入非正整数返回0；
//	return result;
//}





//int main()
//{
//	int x = 4;
//	int y;
//	if (x < 0)
//		y = -1;
//	else if (x = 0)
//		y = 0;
//	else
//		y = 1;
//	printf("%d", x);
//	return 0;
//}