#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define nmax 100

int main()
{
	int i = 0, cnt = 0, j;
	char ch, a[80],b[80];
	ch = getchar();
	for (i = 0; ch != '\n'; i++) 
	{
		a[i] = ch;
		cnt++;
		ch = getchar();
	}
	/*do
	{
		ch = getchar();
		a[i] = ch;
		cnt++;
	} while (ch != '\n');*/
	for (i = 0, j = cnt - 1; i < cnt; i++, j--)
		b[j] = a[i];
	for (i = 0; i < cnt; i++)
		printf("%c", b[i]);
	return 0;
}
//int main()
//{
//	int i, j, cnt = 0;
//	char ch, a[80], b[80];
//	ch = getchar();
//	for (i = 0; ch != '\n'; i++) {
//		a[i] = ch;
//		cnt++;
//		ch = getchar();
//	}
//	for (i = 0, j = cnt - 1; i < cnt; i++, j--)
//		b[j] = a[i];
//	for (i = 0; i < cnt; i++)
//		printf("%c", b[i]);
//
//	return 0;
//}

//int main()
//{
//	char ch;
//	char arr[nmax];
//	int i = 0;
//	int cnt = 0;
//	while ((ch = getchar()) != '\n')
//	{
//		arr[i] = ch;
//		cnt++;
//	}
//	for (i = cnt - 1; i >=0; i--)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}