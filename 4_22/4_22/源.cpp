#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include <stdio.h>

int fib(int n);
void PrintFN(int m, int n);

int main()
{
	int m, n, t;

	scanf("%d %d %d", &m, &n, &t);
	printf("fib(%d) = %d\n", t, fib(t));
	PrintFN(m, n);

	return 0;
}

/* 你的代码将被嵌在这里 */



//#include <stdio.h>
//#define MAXS 15
//
//void StringCount(char s[]);
//void ReadString(char s[]); /* 由裁判实现，略去不表 */
//
//int main()
//{
//	char s[MAXS];
//
//	ReadString(s);
//	StringCount(s);
//
//	return 0;
//}
//
///* Your function will be put here */
//void StringCount(char s[])
//{
//	int letter = 0, digit = 0, blank = 0, other = 0;
//	int count = 0;
//
//	while (s[count] != '\0')
//		count++;
//
//	for (int i = 0; i < count; i++)
//	{
//		if (s[i] >= 'a'&&s[i] <= 'z' || s[i] >= 'A'&&s[i] <= 'Z')
//			letter++;
//		else if (s[i] >= '0'&&s[i] <= '9')
//			digit++;
//		else if (s[i] == ' '&&s[i] == '\n')
//			blank++;
//		else
//			other++;
//	}
//	printf("letter = %d, blank = %d, digit = %d, other = %d", letter, blank, digit, other);
//}



//int main()
//{
//
//	return 0;
//}


//int main()
//{
//	char arr[81];
//	int count = 0;
//	for (int i = 0; i < 81; i++)
//	{
//		scanf("%c", &arr[i]);
//		if (65 <= arr[i] && arr[i] <= 90)
//		{
//			arr[i] = 155 - arr[i];
//		}
//		printf("%c", arr[i]);
//		if (arr[i] == '\n')
//			break;
//	}
//	//printf("%d", count);
//	return 0;
//}