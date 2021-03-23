//#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int main()
{
	char a[80], b[80], c[80], d[80], e[80];
	char ch;
	int i = 0;
	while ((ch = getchar()) != '\n')
	{
		a[i++] = ch;
	}
	printf("%s", a);
	return 0;
}