#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main()
{
	int i;
	char c;
	scanf("%d %c", &i, &c);//输入12 1或12    1或12a或12     a
	printf("i=%d, c=%d, c='%c'\n", i, c, c);//前面两个的结果都为12 49 1  后面两个的结果都为12 97 a
	return 0;
}

//弄懂！！