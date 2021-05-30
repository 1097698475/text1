
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
		scanf