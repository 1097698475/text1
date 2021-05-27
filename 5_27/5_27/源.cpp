#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	char str[] = "abc\000def\n";
	printf("%d %d", sizeof(str), strlen(str));
	//char p[] = "hello!";
	//char q[10] = { 'h','e','l','l','o','!' };
	//printf("%d %d\n", sizeof(p), sizeof(q));
	//printf("%d %d\n", strlen(p), strlen(q));
}

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int arr[100];
//	for (int i = 0; i < n; i++)
//		scanf("%d", &arr[i]);
//
//	int add = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if(j!=i)
//				add += arr[i] * 10 + arr[j];
//		}
//	}
//	printf("%d", add);
//	return 0;
//}