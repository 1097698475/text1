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
//	int b = a >> 1;//16ת��Ϊ������������һλ��10000���01000
//	int c = a >> 2;
//	printf("%d\n", b);
//	printf("%d\n", c);//����һλ�ǳ���2������һλ�ǳ���2
//	return 0;
//}


int main()
{
	int a = 3;
	int b = 5;
	int c = a & b;     //��λ��
	//011
	//101
	//001      ����0��1=0��0��0=0��1��1=1

	int a1 = 3;
	int b1 = 5;
	int c1 = a1 | b1;      //��λ��
	//011
	//101
	//111     ����0��1Ϊ1��0��0Ϊ0��1��1Ϊ1


	int a2 = 3;
	int b2 = 5;
	int c2 = a2 ^ b2;     //��λ���
	//011
	//101
	//110     ������ͬΪ0������Ϊ1




}