#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include <stdio.h>

int fn(int a, int n);
int SumA(int a, int n);

int main()
{
	int a, n;

	scanf("%d %d", &a, &n);
	printf("fn(%d, %d) = %d\n", a, n, fn(a, n));
	printf("s = %d\n", SumA(a, n));

	return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
int fn(int a, int n)
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		int fact;
		for(int j=0;j<)
		num += a * fact;
	}
	return num;
}



//#include <stdio.h>
//#define MAXS 15
//
//void StringCount(char s[]);
//void ReadString(char s[]); /* �ɲ���ʵ�֣���ȥ���� */
//
//int main()
//{
//	char s[MAXS];
//
//	ReadString(s);
//	StringCount(s);
//
//	return 0;
//}
//
///* Your function will be put here */
//void StringCount(char s[])
//{
//	int letter = 0;//��ĸ
//	int blank = 0;//�ո�ͻس�
//	int digit = 0;//�����ַ�
//	int other = 0;
//	int i = 0;
//	int n = 0;
//	while (s[i] != '\0')
//		i++ ;
//	for (int j = 0; j < i; i++)
//	{
//		if ((s[i] >= 'A'&&s[i] <= 'Z') || (s[i] >= 'a'&&s[i] <= 'z'))
//			letter++;
//		else if (s[i] == ' ' || s[i] == '\n')
//			blank++;
//		else if (s[i] >= '0'&&s[i] <= '9')
//			digit++;
//		else
//			other++;
//	}
//	printf("letter = %d, blank = %d, digit = %d, other = %d", letter, blank, digit, other);
//}



//#include <stdio.h>
//#include <math.h>
//
//double funcos(double e, double x);
//
//int main()
//{
//	double e, x;
//
//	scanf("%lf %lf", &e, &x);
//	printf("cos(%.2f) = %.6f\n", x, funcos(e, x));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//double funcos(double e, double x) //eΪ���һ�����ֵС�ڣ�xΪҪ���Ƶ�ֵ
//{
//	int flag = 1;
//	double part;
//	do
//	{
//		double i = 2;
//		double fact = 1;
//		double sum = 0;
//		for (int j = 1; j <= i; j++) //����fact:��ĸ�Ľ׳ˣ�����part:ÿһ��
//		{
//			fact *= j;
//			part = pow(x, i) / fact;
//		}
//			if (flag == 1) //һ��ʼ���Ǹ�������һ��ʼΪ1
//			{
//				sum -= part;
//				flag = 0;
//			}
//			else //��һ��Ϊ��������Ϊ0������flag�ĳ�1
//			{
//				sum += part;
//				flag = 1;
//			}
//		i += 2;
//	} while (part >= e);
//}



//#include <stdio.h>
//
//int narcissistic(int number);
//void PrintN(int m, int n);
//
//int main()
//{
//	int m, n;
//
//	scanf("%d %d", &m, &n);
//	if (narcissistic(m)) printf("%d is a narcissistic number\n", m);
//	PrintN(m, n);
//	if (narcissistic(n)) printf("%d is a narcissistic number\n", n);
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//int narcissistic(int number) //�ж��Ƿ�ˮ�ɻ���������return 1
//{
//	int bitcount = 0;
//	int text1 = number;
//	while (text1 > 0)  //��������Ǽ�λ��,��bitcount
//	{
//		bitcount++;
//		text1 /= 10;
//	}
//	int alladd = 0;
//	int text2 = number;
//	for (int i = 0; i < bitcount; i++) //����ѭ������һ��ѭ����Ҫ������ٴΣ��ڶ���ѭ�����۳�
//	{
//		int bit = text2 % 10;
//		text2 /= 10;
//		int p = 1;
//		for (int j = 0; j < bitcount; j++)
//		{
//			p *= bit;
//		}
//		int bitadd = p;
//		alladd += bitadd;
//	}
//	if (alladd == number)
//		return 1;
//	else return 0;
//	
//}
//void PrintN(int m, int n)
//{
//	int add = 0;
//	for (int i = m+1; i < n; i++)
//	{
//		if (narcissistic(i))
//			printf("%d\n", i);
//	}
//	return add;
//}




//#include <stdio.h>
//
//int CountDigit(int number, int digit);
//
//int main()
//{
//	int number, digit;
//
//	scanf("%d %d", &number, &digit);
//	printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//int CountDigit(int number, int digit)  //number��Ҫ���Ե���,digit��key�����س���key�Ĵ���
//{
//	if (number < 0)
//		number = -number;
//	int count = 0;
//	do
//	{
//		int bit = number % 10;
//		number /= 10;
//		if (bit == digit)
//			count++;
//
//	} while (number > 0);
//	return count;
//}




//#include <stdio.h>
//#include <math.h>
//
//int prime(int p);
//int PrimeSum(int m, int n);
//
//int main()
//{
//	int m, n, p;
//
//	scanf("%d %d", &m, &n);
//	printf("Sum of ( ");
//	for (p = m; p <= n; p++) {
//		if (prime(p) != 0)
//			printf("%d ", p);
//	}
//	printf(") = %d\n", PrimeSum(m, n));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//int prime(int p)//�������򷵻�1
//{
//	int a = 2;
//	if (p <= 1)
//		return 0;
//	for (a; a <= p; a++)
//	{
//		if (p%a == 0 && a < p)
//			return 0;
//		if (a == p)
//			return 1;
//	}
//}
//int PrimeSum(int m, int n)
//{
//	int sum = 0;
//	for (int i = m; i <= n; i++)
//	{
//		if (prime(i) == 1)
//			sum += i;
//	}
//	return sum;
//}




//#include <stdio.h>
//#include <math.h>
//
//double dist(double x1, double y1, double x2, double y2);
//
//int main()
//{
//	double x1, y1, x2, y2;
//
//	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
//	printf("dist = %.2f\n", dist(x1, y1, x2, y2));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//double dist(double x1, double y1, double x2, double y2)
//{
//	double sum = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
//	double dis = sqrt(sum);
//	return dis;
//}




//#include <stdio.h>
//
//#define MAXN 10
//
//int even(int n);
//int OddSum(int List[], int N);
//
//int main()
//{
//	int List[MAXN], N, i;
//
//	scanf("%d", &N);
//	printf("Sum of ( ");
//	for (i = 0; i < N; i++) {
//		scanf("%d", &List[i]);
//		if (even(List[i]) == 0)
//			printf("%d ", List[i]);
//	}
//	printf(") = %d\n", OddSum(List, N));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//int even(int n)
//{
//	if (n % 2 == 1) return 0;
//	else return 1;
//}
//int OddSum(int List[], int N)
//{
//	int i;
//	int sum = 0;
//	for (i = 0; i < N; i++)
//	{
//		if (even(List[i]) == 0)
//			sum += List[i];
//	}
//	return sum;
//}




//#include <stdio.h>
//
//int sign(int x);
//
//int main()
//{
//	int x;
//
//	scanf("%d", &x);
//	printf("sign(%d) = %d\n", x, sign(x));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//int sign(int x)
//{
//	int result;
//	if (x > 0) result = 1;
//	else if (x == 0) result = 0;
//	else result = -1;
//	return result;
//}




//#include <stdio.h>
//
//void pyramid(int n);
//
//int main()
//{
//	int n;
//
//	scanf("%d", &n);
//	pyramid(n);
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//void pyramid(int n)
//{
//	int i;
//	for (i = 1; i <= n; i++)
//	{
//		for (int j = n - i; j > 0; j--)
//		{
//			printf(" ");
//		}
//		for (int k = 0; k < i; k++)
//		{
//			printf("%d ", i);
//		}
//		printf("\n");
//	}
//}



//#include <stdio.h>
//
//int max(int a, int b);
//
//int main()
//{
//	int a, b;
//
//	scanf("%d %d", &a, &b);
//	printf("max = %d\n", max(a, b));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//int max(int a, int b)
//{
//	int max = a;
//	max < b ? max = b: max;
//	return max;
//}



//int sum(int m, int n);
//
//int main()
//{
//	int m, n;
//
//	scanf("%d %d", &m, &n);
//	printf("sum = %d\n", sum(m, n));
//
//	return 0;
//}
//
//int sum(int m, int n)
//{
//	int i;
//	int sum = 0;
//	for (i = m; i <= n; i++)
//		sum += i;
//	return sum;
//}