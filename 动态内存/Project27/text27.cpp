#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//#include<malloc.h>����ͷ�ļ�Ҳ���������
#include<stdlib.h>

int main()
{
	void *p;
	int cnt = 0;
	while (p = malloc(100 * 1024 * 1024))//1024��1KB��������ÿ������100MB�Ŀռ�
		cnt++;//��̬�ڴ�����ռ������ʱ�᷵��0��p=0Ϊ�����˳�
	printf("������%d00MB�ռ�", cnt);
	return 0;
}


int main()
{
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(n * sizeof(int));
	//���������Ǵ���ģ��� int b[] = (int *)malloc(n * sizeof(int));
	//��sizeof���㲻�˶�̬�ڴ棡��printf("%d", sizeof(a));
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = n - 1; i >= 0; i--)
		printf("%d ", a[i]);

	return 0;
}