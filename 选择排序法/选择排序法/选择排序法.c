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
		int index = i;   //��Сֵ�±�indexĬ�ϵ�һ��Ԫ��
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[index])
				index = j;  //�ҳ���Сֵ���±�
			int temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;  //��Сֵ���i��Ԫ�ػ�������֤��i��Ԫ����һ�ֿ�������С��Ԫ��

		} //�ڶ���ѭ���ӵڶ���Ԫ�ؿ�ʼ
	}
	for (int i = n - 1; i >= 0; i--)
		printf("%d ", arr[i]);
	return 0;
}