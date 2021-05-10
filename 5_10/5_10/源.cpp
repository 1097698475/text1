#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	/* ³ÌÐò¶ÎB */
	int s = 0;
	int i = 1;
	while (1) {
		if (i > 10) {
			break;
		}
		s = s + i;
		i++;
	}
	printf("%d", s);
	return 0;
}