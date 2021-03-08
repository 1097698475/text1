#define _CRT_SECURE_NO_WARNINGS
#define nmax 100
#include<stdio.h>

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i;
//	char arr[nmax];
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int tmp;
//	int j;
//	for (i = 0; i < n-1; i++)
//	{
//		for (j = 0; j < n - 1-i; j++)
//		{
//			tmp = arr[i];
//			arr[i] = arr[i + 1];
//			arr[i + 1] = tmp;
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}


//int main()
//{
//	int a = 16;
//	int b = a >> 1;//16转化为二进制在右移一位，10000变成01000
//	int c = a >> 2;
//	printf("%d\n", b);
//	printf("%d\n", c);//右移一位是除以2，左移一位是乘以2
//	return 0;
//}


int main()
{
	int a = 3;
	int b = 5;
	int c = a & b;     //按位与
	//011
	//101
	//001      法则：0与1=0，0与0=0，1与1=1

	int a1 = 3;
	int b1 = 5;
	int c1 = a1 | b1;      //按位或
	//011
	//101
	//111     法则：0或1为1，0或0为0，1或1为1


	int a2 = 3;
	int b2 = 5;
	int c2 = a2 ^ b2;     //按位异或
	//011
	//101
	//110     法则：相同为0，相异为1




}