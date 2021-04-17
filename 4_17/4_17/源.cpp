#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



//int main()
//{
//	char a[5];
//	for (int i = 0; i <= 5; i++)
//		scanf("%c", &a[i]);
//}

int main()
{
	int m, n;
	
	scanf("%d %d", &m, &n);
	int min;
	//m < n ? min = m : min = n;  //循环到较小一个
	if (m < n)
		min = m;
	else
		min = n;
	int a = 1;  //a为最大公约数，b为最小公倍数
	for (int i = 1; i <= min; i++)
	{
		if (m%i == 0 && n%i == 0)
		{
			a *= i;
		}
	}
	printf("%d %d", a, m/a*n);
	return 0;
}


//int main()
//{
//	int flag = 1;
//	int n;
//	double sum = 0;
//	scanf("%d", &n);
//	for (double i = 1; i <= n; i++)
//	{
//		double item = i / (i * 2 - 1);
//		sum += flag * item;
//		flag = -flag;
//	}
//	printf("%.3f", sum);
//}

//int main()
//{
//	int n, a;
//	int jcount = 0; //奇数个数
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &a);
//		if (a % 2 == 1)
//			jcount++;
//	}
//	printf("%d %d",jcount, n - jcount);
//	return 0;
//}


//int main()
//{
//	int total = 0;
//	int score;
//	scanf("%d", &score);
//	while (score >= 0)
//	{
//		total = total + score;
//		scanf("%d", &score);
//	}
//	return 0;
//}
