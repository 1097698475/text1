#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//#include<malloc.h>好像头文件也可以是这个
#include<stdlib.h>

int main()
{
	void *p;
	int cnt = 0;
	while (p = malloc(100 * 1024 * 1024))//1024是1KB，所以是每次申请100MB的空间
		cnt++;//动态内存申请空间达上限时会返回0，p=0为假则退出
	printf("分配了%d00MB空间", cnt);
	return 0;
}


int main()
{
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(n * sizeof(int));
	//这样定义是错误的！： int b[] = (int *)malloc(n * sizeof(int));
	//用sizeof计算不了动态内存！：printf("%d", sizeof(a));
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = n - 1; i >= 0; i--)
		printf("%d ", a[i]);

	return 0;
}