#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int main()
{
	int i;
	int n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		printf("%d ", i);
	return 0;
}

//void print_n(int n)
//{
//	if (n)
//	{
//		print_n(n-1);
//		printf("%d ", n);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	print_n(n);
//	return 0;
//}


//int f(void);
//int ALL = 12;
//int main()
//{
//	printf("in %s ALL is %d\n", __func__, ALL);
//	f();
//	printf("again in %s ALL is %d\n", __func__, ALL);
//
//	return 0;
//}
//int f(void)
//{
//	ALL = 1;
//	printf("in %s ALL is %d\n", __func__, ALL);
//	ALL += 2;
//	printf("again in %s ALL is %d\n", __func__, ALL);
//	return  ALL;
//}


//typedef union
//{
//	int i;
//	char ch[sizeof(int)];
//}CHI;
//int main()
//{
//	CHI chi;
//	int i;
//	chi.i = 1234;
//	for (i = 0; i < sizeof(int); i++)
//	{
//		printf("%02hhx", chi.ch[i]);
//	}
//}


//typedef struct date
//{
//	int x;
//	int y;
//	int z;
//}date;
//int main()
//{
//	date today = { 1,2,3 };
//	printf("%d %d %d", today.x, today.y, today.z);
//	return 0;
//}


//struct time
//{
//	int hours;
//	int minutes;
//	int seconds;
//};
//struct time timeupdate(struct time now);
//int main()
//{
//	struct time texttime[] = { {11,59,59},{12,0,0},{12,0,1},{12,0,2},{12,0,3} };
//	int i;
//	for (i = 0; i < 5; i++)
//	{
//
//	}
//	return 0;
//}