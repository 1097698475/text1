#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct book 
{
	char mame[31];
	double price;

}book;

int main()
{
	int n, min = 0, max = 0, i;
	book *p;

	scanf("%d", &n);
	getchar();
	p = (book*)malloc(sizeof(book)*n);

	for (i = 0; i < n; i++)
	{
		gets_s(p[i].mame);
		scanf("%lf", &p[i].price);
		getchar();
	}

	for (i = 1; i < n; i++)
	{
		if (p[i].price > p[max].price)
		{
			max = i;
		}

		if (p[i].price < p[min].price) 
		{
			min = i;
		}
	}

	printf("%.2f, %s\n", p[max].price, p[max].mame); // 输出%s可以空格
	printf("%.2f, %s", p[min].price, p[min].mame);

	free(p);

	return 0;

}



//int main()
//{
//	book text[10];
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) //输入n本书的数据，因为书名有空格,且之后要整体排序，所以用！=\n，且不用getchar
//	{
//		for (int j = 0; text[i].name[j-1]!='\n'; j++)
//		{
//			scanf("%c", &text[i].name[j]);
//		}
//		scanf("%lf", &text[i].price);
//	}
//
//	//按价格排序
//	//for (int i = 0; i < n - 1; i++)  //最后一个不用排序
//	//{
//	//	book tmp = { 0 };
//	//	for (int j = i + 1; j < n; j++)  // 跟剩下的交换比
//	//	{
//	//		if (text[i].price < text[j].price)  //最大的留在前面 ,交换结构体，而不单是价格
//	//		{
//	//			tmp = text[i];
//	//			text[i] = text[j];
//	//			text[j] = tmp;
//	//		}
//	//	}
//	//}
//
//	//输出排序后的，最高价格和最低价格，再书名
//	printf("%.2f, ", text[0].price);
//	for (int i = 0;text[0].name[i] != '0'; i++)
//	{
//		printf("%c", text[0].name[i]);
//	}
//	printf("%.2f, ", text[n-1].price);
//	for (int i = 0; text[n-1].name[i] != '0'; i++)
//	{
//		printf("%c", text[n-1].name[i]);
//	}
//	return 0;
//}


//typedef struct time
//{
//	int hh;
//	int mm;
//	int ss;
//}time;
////typedef struct time22
////{
////	char hh;
////	char mm;
////	char ss;
////}time2;
//int main()
//{
//	/*time2 now;
//	time2 *p = &now;
//	scanf("%c %c %c", &p->hh, &p->mm, &p->ss);
//	printf("%c %c %c", p->hh, p->mm, p->ss);*/
//
//	time now;
//	time *p = &now;
//	int s;
//	scanf("%d:%d:%d", &p->hh, &p->mm, &p->ss);
//	scanf("%d", &s);
//	p->ss = p->ss + s;
//
//	//判断+60秒是否ss大于60
//	if (p->ss >= 60)
//	{
//		p->ss -= 60;
//		p->mm += 1;
//		if (p->mm == 60)
//		{
//			p->mm = 0;
//			p->hh += 1;
//			if (p->hh == 24)
//			{
//				p->hh = 0;
//			}
//		}
//	}
//	printf("%02d:%02d:%02d", p->hh, p->mm, p->ss);
//	return 0;
//}