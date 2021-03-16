#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//#include<malloc.h>好像头文件也可以是这个
#include<stdlib.h>

int main()
{
	void *p;
	int cnt = 0;
	while (p = malloc(100 * 1024 * 1024))//1024是1KB，所以是每次申请100MB的空间
		cnt++;
	printf("分配了%d00MB空间", cnt);
	return 0;
}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int *a = (int *)malloc(n * sizeof(int));
//	//这样定义是错误的！： int b[] = (int *)malloc(n * sizeof(int));
//	//用sizeof计算不了动态内存！：printf("%d", sizeof(a));
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (i = n - 1; i >= 0; i--)
//		printf("%d ", a[i]);
//
//	return 0;
//}


//int main()
//{
//	int n;
//	int arr[100];
//	int i;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//		scanf("%d", arr[i]);
//
//	return 0;
//}


//int scan(int *);
//void ifsame(int *,int *);
////void print(int *,int);
//int main()
//{
//	int a[100], b[100];
//	int anumber, bnumber;
//	int *pa = a, *pb = b;
//	anumber = scan(pa);
//	//print(a,anumber);
//	bnumber = scan(pb);
//	pa = a, pb = b;
//	void ifsame(pa,pb);
//	return 0;
//}
//int scan(int *text)
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", text++);
//	}
//	return n;
//}
//void print(int *a,int number)
//{
//	for (int i = 0; i < number; i++)
//		printf("%d ", a[i]);
//}




//int main()
//{
//	int n, max, maxnumber, arr[100];
//	int i;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (i == 0)
//		{
//			max = arr[0];
//			maxnumber = 0;
//		}
//		if (i>0 && max < arr[i])
//		{
//			max = arr[i];
//			maxnumber = i;
//		}
//	}
//	printf("%d %d", max, maxnumber);
//	return 0;
//}
//#include<stdio.h>
//#define nmax 1000
//int main()
//{
//	int n, i, num[nmax], *p, max, nummax;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//		scanf("%d", &num[i]);
//	p = num;
//	max = num[0];
//	nummax = 1;
//	for (i = 0; i < n; i++)
//	{
//		if (*(p + i) > max)
//		{
//			max = *(p + i);
//			nummax = i;
//		}
//	}
//	printf("%d %d", max, nummax);
//}