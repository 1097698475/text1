#define _CRT_SECURE_NO_WARNINGS
#include<Stdio.h>

void swap(int *, int *);
int main()
{
	int a = 3, b = 5;
	swap(&a, &b);
	printf("%d %d", a, b);
	return 0;
}
void swap(int *p1, int *p2)
{
	int p;
	p = *p1;
	*p1 = *p2;
	*p2 = p;
}