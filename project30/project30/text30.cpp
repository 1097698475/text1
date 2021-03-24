#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#define INF 1000000

int main()
{
	int n, a, arr[100];
	int max;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n-1; i++)
	{
		int index = i;   //最小值下标index默认第一个元素
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[index])
				index = j;  //找出最小值的下标
			int temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;  //最小值与第i个元素互换，保证第i个元素下一轮可能是最小的元素

		}
	}
	for (int i = n-1; i >= 0; i--)
		printf("%d ", arr[i]);
	return 0;
}


//int main()
//{
//	char ch;
//	while ((ch = getchar()) != '\n')
//	{
//		if (ch >= 65 && ch <= 90)
//		{
//			ch = 155 - ch;
//		}
//		putchar(ch);
//	}
//	return 0;
//}

//int main()
//{
//	int n = 3;
//	int i, j, k;
//	int min = 100, max = 1000;
//	for (i = min; i < max; i++)
//	{
//		int a = i;
//		int add = 0;
//		for (j = 0; j < n; j++)
//		{
//			int d = a % 10;
//			a /= 10;
//			int p = 1;
//			for (k = 0; k < n; k++)
//			{
//				p *= d;
//			}
//			add += p;
//		}
//		if (add == i)
//			printf("%d\n", i);
//	}
//	return 0;
//}

//int main()
//{
//	int n = 3;
//	int i, j, k;
//	int min = 100, max = 1000;
//	for (i = min; i < max; i++)
//	{
//		int text = i;
//		int add = 0;
//		for (j = 0; j < n; j++)
//		{
//			int wei = text % 10;
//			text /= 10;
//			int dsum = 1;
//			for (k = 0; k < n; k++)
//				dsum *= wei;
//			add += dsum;
//		}
//		if (add == i)
//			printf("%d\n", i);
//	}
//}

//int main()
//{
//	int min = 100, max = 1000, i, j, k;
//	int wei;
//	for (i = min; i < max; i++)
//	{
//		int sum = 0;
//		int text = i;
//		for(k=0; k<3; k++)
//		{
//			wei = text % 10;
//			int dsum = 1;
//			text /= 10;
//			for (j = 0; j < 3; j++)
//				dsum *= wei;
//			sum += dsum;
//		}
//
//		if (sum == i)
//			printf("%d/n", i);
//	}
//
//	return 0;
//}


//int main()
//{
//	int sum = 0;
//	int i, x;
//	int b = 1;
//	for (i = 100; i <= 999; i++)
//	{
//		int a = i;
//		x = i;
//		sum = 0;
//		for(int k=0;k<3;k++)
//		{
//			int wei = x % 10;
//			x /= 10;
//			for (int j = 0; j < 2; j++)
//			{
//				b = b* wei;
//			}
//			sum += a;
//		}
//		if (a == sum)
//			printf("%d ", a);
//	}
//	return 0;
//}


//int main()
//{
//	int n, x, sum=0, min, max;
//	int kase = 0;
//	while (scanf("%d", &n) == 1 && n)
//	{
//		int s = 0;
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &x);
//			sum += x;
//			if (i == 0)
//				min = max = x;
//			else
//			{
//				if (x < min) min = x;
//				if (x > max) max = x;
//			}
//		}
//		if (kase)
//			printf("\n");
//		printf("case %d : %d %d %.2f", ++kase, min, max, (double)sum/n);
//	}
//	return 0;
//}


//int main()
//{
//	double i;
//	for (i = 0; i != 10.0; i += 0.1)
//		printf("%.1f\n", i);
//	return 0;
//}


//int main()
//{
//	int x, n = 0;
//	int max, min;
//	int s = 0;
//	while (scanf("%d", &x))
//	{
//		s += x;
//		n++;
//	}
//	printf("%d", s);
//	return 0;
//}



//int main()
//{
//	int a = 1;
//	for (int i = 1; i <= 10; i++)
//	{
//		a = a * i;
//	}
//	printf("%d\n", a);
//	printf("time used = %.6f", (double)clock() / CLOCKS_PER_SEC);
//	return 0;
//}

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	getchar();  //缓冲区
//	char ch;
//	int number[10] = { 0 };
//	int max;
//	while ((ch = getchar()) != '\n')
//	{
//		switch (ch)
//		{
//		case '0':number[0]++; break;
//		case '1':number[1]++; break;
//		case '2':number[2]++; break;
//		case '3':number[3]++; break;
//		case '4':number[4]++; break;
//		case '5':number[5]++; break;
//		case '6':number[6]++; break;
//		case '7':number[7]++; break;
//		case '8':number[8]++; break;
//		case '9':number[9]++; break;
//		}
//	}
//	max = number[0];
//	for (int i = 0; i < 9; i++)
//	{
//		max > number[i] ? max: max = number[i];
//		printf("%d:", max);
//	}
//	for (int i = 0; i < 9; i++)
//	{
//		if (max == number[i])
//			printf(" %d", i);
//	}
//	return 0;
//}


//int main()
//{
//	char a[5][80], tmp[80];
//	int i, j;
//	for (i = 0; i < 5; i++)
//		scanf("%s", &a[i]);
//	冒泡排序
//	for (i = 1; i < 5; i++)
//	{
//		for (j = 0; i < 4; j++)
//		{
//			if (strcmp(a[j], a[j + 1]) > 0)
//			{
//				strcpy(tmp, a[j]);
//				strcpy(a[j], a[j + 1]);
//				strcpy(a[j + 1], tmp);
//			}
//		}
//    }
//	printf("After sorted:\n");
//	for (i = 0; i < 5; i++)
//	{
//		printf("%s\n", a[i]);
//	}
//	return 0;
//}

//int main()
//{
//	char a[80] = { 0 }, b[80], c[80], d[80], e[80];
//	char ch;
//	int i = 0;
//	while ((ch = getchar()) != '\n')
//	{
//		a[i++] = ch;
//	}
//	while ((ch = getchar()) != '\n')
//	{
//		b[i++] = ch;
//	}
//	while ((ch = getchar()) != '\n')
//	{
//		c[i++] = ch;
//	}
//	while ((ch = getchar()) != '\n')
//	{
//		d[i++] = ch;
//	}
//	while ((ch = getchar()) != '\n')
//	{
//		e[i++] = ch;
//	}
//	
//	//printf("%s", a);
//	return 0;
//}