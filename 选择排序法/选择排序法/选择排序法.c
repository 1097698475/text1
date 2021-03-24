#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#define INF 1000000

int main()
{
	int n, a, arr[100];
	int max;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n - 1; i++)
	{
		int index = i;   //最小值下标index默认第一个元素
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[index])
				index = j;  //找出最小值的下标
			int temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;  //最小值与第i个元素互换，保证第i个元素下一轮可能是最小的元素

		} //第二次循环从第二个元素开始
	}
	for (int i = n - 1; i >= 0; i--)
		printf("%d ", arr[i]);
	return 0;
}