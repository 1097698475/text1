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
	int min = 0, max = 0;  //默认最小最大都为第一个元素
	book *p; //动态内存数组

	scanf("%d", &n);
	getchar();

	p = (book*)malloc(sizeof(book)*n);

	for (int i = 0; i < n; i++)
	{
		gets_s(p[i].name);
		//getchar();   为什么getchar()不用？？？
		scanf("%lf", &p[i].price);
		getchar();
	}

	for (int i = 1; i < n; i++)  //从第二个数组开始
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
