#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	int n, i,count=0;
	double sum=0, average, score;
	scanf("%d", &n);
	if (n > 0)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%d ", &score);
			sum = sum + score;
			if(score>=60)
			{
				count = count + 1;
			}
			
		}
		average = sum / n;
		printf("average = &.1f/n", average);
		printf("count = &d", count);
	}
	return 0;
}


//int main()
//{
//	int min;
//	int n;//输入n个数
//	scanf("%d ", &n);
//	int num;
//	scanf("%d ", &num);//接收输入的数串。由于输入的数串的第一个已经被n接收了，所以num会接受第二个数
//
//
//	min = num;//先把第一个当成最小的
//	for (int x = 1; x <= n - 1; x++)//只循环n-1次
//	{
//		scanf("%d ", &num);
//		if (min > num)
//		{
//			min = num;
//		}
//
//	}
//
//	printf("min = %d", min);
//	return 0;
//}
//int main()
//{
//	double eps,i,fu,a=1;
//	double sum = 0;
//	scanf("%lf", &eps);
//	for (i = 1; a>= eps; i+=3);
//	{
//		a = 1 / i;
//		fu = pow(-1, i + 1);
//		sum = sum + fu * 1 / i;
//	}
//	printf("sum = %lf", sum);
//}



//#include<math.h>
//int main()
//{
//	double x1, x2, x3, y1, y2, y3;
//	double l1, l2, l3;
//	double s, A,L;
//	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
//	l1 = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
//	l2 = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
//	l3 = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
//	if (l1 + l2 > l3&&l2 + l3 > l1&&l1 + l3 > l2)
//	{
//		L = l1 + l2 + l3;
//		s = 0.5*(l1 + l2 + l3);
//		A = sqrt(s*(s - l1)*(s - l2)*(s - l3));
//		printf("L = %.2f, A = %.2f", L, A);
//	}
//	else
//		printf("Impossible");
//}
//#include<stdio.h>
//int main()
//{
//	    int T,F,A;
//		double drive, time;
//		double drivefeed, timefeed;
//		scanf("%lf %lf", &drive, &time);
//		T = time / 5;
//		timefeed = T * 2;
//		if (drive <= 3)
//		{
//			drivefeed = 10;
//		}
//		else if (drive <= 10)
//		{
//			drivefeed = 10 + 2 * (drive - 3);
//		}
//		else
//		{
//			drivefeed = 10 + 14 + 3 * (drive - 10);
//		}
//		A = drivefeed + 0.5;
//		F = A + timefeed;
//		printf("%d", F);
//
//}

//{
//	int max, min;
//	int x, y, z;
//	scanf("%d %d %d", &x, &y, &z);
//	max = x > y&&x > z ? x : (y > z ? y : z);
//	min = x < y&&x < z ? x : (y < z ? y : z);
//	printf("max=%d min=%d", max, min);
//
//}

//{
//	int x,y,X;
//	scanf("%d", &x);
//	X=x > 0 ? 1 : (x < 0 ? -1 : 0);
//	printf("y=%d", X);
//}

//int main()
//{
//	double v, vm;
//	double n;
//	scanf("%lf %lf", &v, &vm);
//	if (v < 1.1*vm)
//	{
//		printf("OK");
//	}
//	else if (v >= 1.1*vm && v < 1.5*vm)
//	{
//		n = ((v - vm) / vm) * 100;
//		printf("Exceed %.0f%%. Ticket 200", n);
//	}
//	else
//	{
//		n = ((v - vm) / vm) * 100;
//		printf("Exceed %.0f%%. License Revoked", n);
//	}
//}