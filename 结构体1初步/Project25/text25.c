#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include<stdbool.h>

struct date {
	int day;
	int month;
	int year;
};
bool isleap(struct date d);
int numberofdays(struct date d);
int main()
{
	struct date today, tomorrow;
	printf("enter today date(dd,mm,yyyy)\n");
	scanf("%d %d %d", &today.day, &today.month, &today.year);
	if (today.day != numberofdays(today))
	{
		tomorrow = today;
		tomorrow.day = today.day + 1;
	}
	else if (today.month == 12)
	{
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year + 1;
	}
	else
	{
		tomorrow.day = 1;
		tomorrow.month = today.month + 1;
		tomorrow.year = today.year;
	}
	printf("tomorrow date is %d-%d-%d", tomorrow.day, tomorrow.month, tomorrow.year);


	return 0;
}
int numberofdays(struct date d)
{
	int days;
	int dayspermonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (d.month == 2 && isleap(d))
		days = 29;
	else
		days = dayspermonth[d.month - 1];
	return days;
}
bool isleap(struct date d)
{
	bool leap = false;
	if ((d.year % 4 == 0 && d.day % 100 != 0) || d.year % 400 == 0)
		leap = true;
	return true;

}


//struct date {
//	int month;
//	int day;
//	int year;
//};
//int main()
//{
//	struct date day1 = { 12,20,2020 };
//	struct date day2 = { 12,23,2021 };
//	printf("%d-%d-%d\n", day1.month, day1.day, day1.year);
//	printf("%d-%d-%d\n", day2.month, day2.day, day2.year);
//	day1 = day2;
//	printf("%d-%d-%d\n", day1.month, day1.day, day1.year);
//	printf("%d-%d-%d", day2.month, day2.day, day2.year);
//
//	return 0;
//}

//int main()
//{
//	int month;
//	char *months[] = { "January","February","March","April","May",
//		"June","July","August","September","October","November","December" };
//	scanf("%d", &month);
//	if (month >= 1 && month <= 12)
//		printf("%s\n", months[month - 1]);
//	
//	return 0;
//}
//int main()
//{
//	char word[9];
//	char word2[9];
//	scanf("%9s", word);
//	scanf("%9s", word2);
//	printf("%s##%s##\n",word,word2);
//	return 0;
//}

//int main()
//{
//	int n;
//	int i, j, k;
//	int min=1, max=1;
//	scanf("%d", &n);
//	for (i = 0; i < n-1; i++)
//	{
//		min *= 10;
//		max *= 10;
//	}
//	max = max * 10;
//	for (i = min; i < max; i++)
//	{
//		int a = i;
//		int add = 0;
//		for (j = 0; j < n; j++)
//		{
//			int d = a % 10;
//			a /= 10;
//			int p = 1;
//			for (k = 0; k < n; k++)
//			{
//				p *= d;
//			}
//			add += p;
//		}
//		if (add == i)
//			printf("%d\n", i);
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	int min=1, max=1;
//	scanf("%d", &n);
//	/*for (i = 0; i < n; i++)
//	{
//		min = min * 10;
//		max = min;
//	}
//	min = min/10;*/
//	for (int i = 100; i < 1000; i++)
//	{
//		int add = 0;
//		int a = i;
//		for (int j = 0; j < n; j++)
//		{
//			int d = i % 10;
//			int p = 1;
//			for (int k = 0; k < n; k++)
//			{
//				p *= d;
//			}
//			add += p;
//			i /= 10;
//		}
//		if (add == a)
//			printf("%d\n", a);
//	}
//	return 0;
//}


//int main()
//{
//	char arr[] = { "hello" };
//	int sz = sizeof(arr);
//	printf("%d", sz);
//	return 0;
//}


//int main()
//{
//	int a[255] = { 0 };
//	a['A'] = 1;
//	printf("%d\n", a['A']);
//	printf("%d", 'A');
//	return 0;
//}


//int main()
//{
//	int a[10];
//	int i;
//	for (i = 0; i < 10; i++)
//	{
//		a[i] = 0;
//	}
//	int x = 0;
//	while (x != -1)
//	{
//		scanf("%d", &x);
//		if (x >= 0 && x <= 9)
//			a[x]++;
//	}
//	for (i = 0; i < 10; i++)
//		printf("%d出现了%d次\n", i, a[i]);
//	return 0;
//}
//

//void f()
//{
//	int a[10];
//	a[9] = 0;
//}
//int main()
//{
//	f();
//	printf("here");
//}


//void cheer(int i)
//{
//	printf("%d", i);
//}
//int main()
//{
//	cheer(2.4);
//	return 0;
//}


//int main()
//{
//	char a = 'B';
//	char b = '1';
//	printf("%d %d", a, b);
//
//	//char ch = -1;
//	//printf("%d\n", ch);//输出就是-1
//
//	/*int i, j = 6;
//	printf("%d %d", i, j);*/
//	return 0;
//
//}

