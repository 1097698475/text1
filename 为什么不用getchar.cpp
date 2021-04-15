#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct book
{
	char name[31];
	double price;
}book;
int main()
{
	int n;
	int min = 0, max = 0;  //Ĭ����С���Ϊ��һ��Ԫ��
	book *p; //��̬�ڴ�����

	scanf("%d", &n);
	getchar();

	p = (book*)malloc(sizeof(book)*n);

	for (int i = 0; i < n; i++)
	{
		gets_s(p[i].name);
		//getchar();   Ϊʲôgetchar()���ã�����
		scanf("%lf", &p[i].price);
		getchar();
	}

	for (int i = 1; i < n; i++)  //�ӵڶ������鿪ʼ
	{
		if (p[i].price > p[max].price)
			max = i;
		if (p[i].price < p[min].price)
			min = i;
	}

	printf("%.2f, %s\n", p[max].price, p[max].name);
	printf("%.2f, %s\n", p[min].price, p[min].name);

	free(p);

	return 0;
}


//typedef struct book 
//{
//	char mame[31];
//	double price;
//}book;
//
//int main()
//{
//
//	int n, min = 0, max = 0;
//	book *p;   //�ǽṹ�����飡������ָ��Ĺ�ϵ
//
//	scanf("%d", &n);
//	getchar();  //���ж�Ҫ��
//	p = (book*)malloc(sizeof(book)*n);   //��̬�ڴ涼Ҫ������ָ�룬���������飡
//
//	for (int i = 0; i < n; i++) 
//	{
//		gets_s(p[i].mame);   //��Ϊ�����飬���Կ���ʡȥ&
//		scanf("%lf", &p[i].price);
//		getchar();
//	}
//
//	for (int i = 1; i < n; i++)
//	{
//		if (p[i].price > p[max].price) 
//		{
//			max = i;   //max��ʼΪ0��Ĭ�ϵ�һ����0��Ϊ���ֵ
//		}
//
//		if (p[i].price < p[min].price)
//		{
//			min = i;   //min��ʼҲΪ0
//		}
//	}
//
//	printf("%.2f, %s\n", p[max].price, p[max].mame);
//	printf("%.2f, %s", p[min].price, p[min].mame);
//
//	free(p);
//
//	return 0;
//
//}
