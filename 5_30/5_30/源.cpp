
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
		scanf