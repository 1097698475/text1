#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i, a[5];
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 1; i <= 5; i++)
	{
		printf("%d", a[i - 1]);
	}
}


//int main()
//{
//	int i, a[5];
//	for (i = 0; i < 5; i++)
//	{
//		a[i] = i + 1;
//		printf("%d ", a[i]);
//	}
//}


//int main()
//{
//	double x, y;
//	int n,num=0;
//	double pai;
//	srand(time(0));
//	printf("input n = ");
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		x = rand() / 32767.0;
//		y = rand() / 32767.0;
//		if (x*x + y * y < 1)
//			num++;
//	}
//	printf("pai = 4.0*%d/%d = \n",num,n);
//	pai = 4.0*num / n;
//	printf("%lf", pai);
//}


//int main()
//{
//	int x;
//	srand(time(0));
//	for (int i = 0; i < 30; i++)
//	{
//		x = rand() % 100 + 1;
//		printf("%d ", x);
//	}
//}


//int main()
//{
//	double x1, x2,x3;
//	char a;
//	for (int i = 1;; i++)
//	{
//		scanf("%lf %c %lf", &x1,&a,&x2);
//		switch (a)
//		{
//		case '+':
//			x3 = x1 + x2;
//			printf("%lf + %lf = %lf", x1, x2, x3);
//		case '*':
//			x3 = x1 * x2;
//			printf("%lf * %lf = %lf", x1, x2, x3);
//		}
//		if (x1 = 0)
//			break;
//		
//	}
//}


//int main()
//{
//	double price, amount;
//	double sum=0;
//	for (int i = 1;; i++)
//	{
//		scanf("%lf %lf", &price, &amount);
//		sum = sum + price * amount;
//		if (price ==0  || amount ==0)
//			break;
//	}
//	printf("sum = %.2f", sum);
//}


//int main()
//{
//	double sum=0, mon;
//	for (int i = 1; i <= 12; i++)
//	{
//		printf("enter data : ");
//		scanf("%lf", &mon);
//		sum = sum + mon;
//	}
//	
//}


//int main()
//{
//	int c;
//	while ((c = getchar()) != EOF)
//		putchar(c);
//
//}


//int main()
//{
//	int m, n,i;
//	double a1=1, a2=1, a3=1,jie;
//	scanf("%d %d", &m, &n);
//	for ( i = 1; i <= n; i++)
//	{
//		a1 = a1 * i;
//	}
//	for (i = 1; i <= m; i++)
//	{
//		a2 = a2 * i;
//	}
//	for (i = 1; i <= n - m; i++)
//	{
//		a3 = a3 * i;
//	}
//	jie = a1  / (a2*a3);
//	printf("resule = %.0f", jie);
//}


//int main()
//{
//	int c,num=1;
//	for (int i = 1;; i++)
//	{
//		scanf("&c", &c);
//		if (c ==' ');
//		num++;
//		if (c == '\n');
//		break;
//	}
//	printf("%d", num);
//}