#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{

	return 0;
}

//#include<math.h>
//
//int main()
//{
//	double foot, cm;  
//	double m;
//	scanf("%lf", &cm);
//	m = cm / 100;
//	//printf("%.1f\n", m);
//
//	foot = m / 0.3048;
//	//printf("%lf\n", foot);
//
//	int foot2 = (int)foot;
//	//printf("%d\n", foot2);
//
//	double a = foot - foot2;
//	int inch = (int)(a * 12);
//	//printf("%d\n", inch);
//
//	printf("%d %d", foot2, inch);
//	return 0;
//}


//int main()
//{
//	double money, year, rate;
//	double in;
//	scanf("%lf %lf %lf", &money, &year, &rate);
//	in = money * pow(1 + rate, year) - money;
//	printf("interest = %.2f", in);
//	return 0;
//}

//int main()
//{
//	int ntime1, ptime;
//	scanf("%d %d", &ntime1, &ptime);
//	int ntime2;  //相对于零点的分钟+ptime
//	ntime2 = ntime1 / 100 * 60 + ntime1 % 100 + ptime;
//	//printf("%d\n", ntime2);
//	int hour, min;
//	hour = ntime2 / 60;
//	min = ntime2 % 60;
//	if (hour > 23)
//	{
//		hour = hour - 24;
//		printf("%d%d", hour, min);
//
//	}
//	else if (min == 0)
//	{
//		printf("%d00", hour);
//	}
//	else
//		printf("%d%d", hour, min);
//
//	return 0;
//}


//int main()
//{
//	int ntime, ptime;
//	scanf("%d ptime", &ntime,&ptime);
//	int min = 0;  //当前分钟
//	min += ntime % 10;
//	ntime /= 10;
//	min += (ntime % 10) * 10;
//	ntime / 10;
//	printf("%d\n", min);
//
//	int hour=0;  //当前小时
//	hour += ntime % 10;
//	if (ntime / 10 != 0)
//		hour += (ntime % 10) * 10;
//	printf("%d\n",hour);
//
//	if (min + ptime >= 60)
//		min = min + ptime - 60;
//
//	return 0;
//}


//int main()
//{
//	double cm;
//	double foot, inch;  //foot为英尺，inch为英寸
//	scanf("%d", &cm);
//	double m = cm / 100;
//	inch = ((m / 0.3048) * 12) / 145;
//	printf("%d", inch / 12);
//	return 0;
//}


//int main()
//{
//	double d1, d2;
//	int in;
//	char ch;
//	scanf("%lf", &d1);
//	scanf("%d", &in);
//	getchar();
//	scanf("%c", &ch);
//	scanf("%lf", &d2);
//	printf("%c %d %.2f %.2f", ch, in, d1, d2);
//	return 0;
//}

//int main()
//{
//	int n;
//	double sum = 0;
//	double ave;
//	for (int i = 0; i < 4; i++)
//	{
//		scanf("%d", &n);
//		sum += n;
//	}
//	printf("Sum = %.0f; Average = %.1f", sum, sum / 4);
//	return 0;
//}


//#include<math.h>

//int main()
//{
//	int text;
//	scanf("%d", &text);
//	int result = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		int bit = text % 10;
//		text /= 10;
//		if (bit != 0)
//		{
//			result = result + bit * pow(10, 2 - i);
//		}
//	}
//	printf("%d", result);
//	return 0;
//}


//#include <stdio.h>
//
//int factorsum(int number);
//void PrintPN(int m, int n);
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





//#include <stdio.h>
//
//int fn(int a, int n);
//int SumA(int a, int n);
//
//int main()
//{
//	int a, n;
//
//	scanf("%d %d", &a, &n);
//	printf("fn(%d, %d) = %d\n", a, n, fn(a, n));
//	printf("s = %d\n", SumA(a, n));
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//int fn(int a, int n)
//{
//	/*9*循环4次
//	1+10+100+1000
//	每一项再循环i次*/
//	int add = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int x = 1;
//		for (int j = 0; j < i; j++)
//		{
//			x *= 10;
//		}
//		add += x;
//	}
//	return a * add;
//}
//int SumA(int a, int n)
//{
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int item = fn(a,i);
//		sum += item;
//	}
//	return sum;
//
//}




//int main()
//{
//	int x, y;
//	printf("%d\n",(x = y = 5, x + y, x + 5));
//	printf("%d\n", (x = y = 5, x = x + y, x + 5));
//	printf("%d\n", (x = 5, x + 5, y = 0, x + y));
//	printf("%d\n", (y = 5, y+5, x = 0,x+y));
//
//	return 0;
//}