#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main()
{
	int i;
	char c;
	scanf("%d %c", &i, &c);//����12 1��12    1��12a��12     a
	printf("i=%d, c=%d, c='%c'\n", i, c, c);//ǰ�������Ľ����Ϊ12 49 1  ���������Ľ����Ϊ12 97 a
	return 0;
}

//Ū������