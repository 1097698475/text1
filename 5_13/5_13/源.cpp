#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	int arr[100];
	scanf("%d", &n);
	int max_index, min_index;

	int i = 0;
	do
	{
		scanf("%d", &arr[i]);
		if (i == 0)
			max_index = min_index = i;
		else
		{
			if (arr[i] > arr[max_index])
				max_index = i;
			else
				;
			if (arr[i] < arr[min_index])
				min_index = i;
			else
				;
		}
		i++;
	} while (i < n);
	int temp;
	printf("%d %d\n", min_index, max_index);

	temp = arr[min_index];
	arr[min_index] = arr[0];
	arr[0] = temp;
	/*printf("第一次交换后：");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");*/
	max_index = 0;

	temp = arr[max_index];
	arr[max_index] = arr[n - 1];
	arr[n - 1] = temp;
	printf("第二次交换后：");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}
//void showmenu();
//void Initprice(double a[]);
//
//int main()
//{
//	showmenu();
//
//	double price[4];
//	Initprice(price);
//
//	int count = 0;
//	int number;
//	for (count = 0; count < 5; count++)
//	{
//		scanf("%d", &number);
//		if (number == 0)
//		{
//			break;
//		}
//		else
//		{
//			printf("price = %.2f\n", price[number - 1]);
//		}
//	}
//
//	return 0;
//}
//
//void showmenu()
//{
//	printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
//}
//void Initprice(double price[4])
//{
//	price[0] = 3;
//	price[1] = 2.5;
//	price[2] = 4.1;
//	price[3] = 10.2;
//}
//int main()
//{
//	int n, m;
//	scanf("%d", &n);
//	int *arr;
//	arr = (int*)malloc(n * sizeof(int));
//	for (int i = n - 1; i >= 0; i--)
//	{
//		scanf("%d", &arr[i]);
//	}
//	scanf("%d", &m);
//	printf("%d", arr[m]);
//	return 0;
//}