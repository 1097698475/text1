#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	int zi, mu;
	scanf("%d/%d", &zi, &mu);
	int min;
	//�ҳ����ӷ�ĸ�����Լ��
	if (zi > mu)
		min = mu;
	else
		min = zi;
	int x = 1; //���Լ��
	for (int i = 1; i <= min; i++)  
	{
		if (zi%i == 0 && mu%i == 0)
		{
			x = i;
		}
	}
	zi /= x;
	mu /= x;
	printf("%d/%d", zi, mu);
}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= (n+1)/2; i++)  //��i��
//	{
//		int n_star = i * 2 - 1;  //������
//		for (int j = n-n_star; j > 0; j--)  //��ӡ���ٸ��ո�
//		{
//			printf(" ");
//		}
//		for (int k = 1; k <= n_star; k++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//	��ӡʣ�¼���
//	for (int i = 1; i <= (n - 1) / 2; i++)
//	{
//		int n_star = n - i * 2; //������
//		for (int j = i * 2; j > 0; j--)
//		{
//			printf(" ");
//		}
//		
//		for (int k = n_star; k > 0; k--)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//int main()
//{
//	int n;
//	scanf("%d", &n); //n~n+3
//	//3��ѭ������һ��Ϊ��λ�����ڶ���ʮλ��
//	for (int i = n; i <= n + 3; i++)
//	{
//		int count = 0;
//		for (int j = n; j <= n + 3; j++)
//		{
//			if (j == i)
//				continue;
//			for (int k = n; k <= n + 3; k++)
//			{
//				if (k == i || k == j)
//					continue;
//				count++;
//				if (count != 6)
//				{
//					printf("%d ", 100 * i + 10 * j + 1 * k);
//				}
//				if(count==6)
//					printf("%d\n", 100 * i + 10 * j + 1 * k);
//
//			}
//		}
//	}
//	return 0;
//}


//int main()
//{
//	if (1)
//		1 + 1;
//	2 + 2;
//	else
//		3 + 3;
//}


//a = 5, b = 8, c = 6, d = 4, x = 0
//if (a < b)
//	if (c < d) x = 1;
//	else if (a < c)
//		if (b < d) x = 2;
//		else x = 3;
//	else x = 6;
//else x = 7;

//int main()
//{
//	int n;
//	scanf("%d", &n);  //������
//	// 3+1+3
//	for (int i = 1; i <= (n - 1) / 2; i++)  //�ڼ��� һֱ��������
//	{
//		for (int j = n - 1 - (i - 1) * 2; j > 0; j--)  //��ӡ�ո� 6 4 2 0
//		{
//			printf(" ");
//		}
//		for (int k = i * 2 - 1; k > 0; k--)  //�ڶ��оʹ�ӡ3��* 
//			printf("* "); 
//		printf("\n");
//	}
//	printf("* * * * * * * \n");
//	for (int i = (n+1)/2+1; i <= n; i++)  //�ڼ��� һֱ��������
//	{
//		for (int j = n - ; j > 0; j--)  //��ӡ�ո� 2 4 6
//		{
//			printf(" ");
//		}
//		for (int k = (n-i)*2+1; k > 0; k--)  //��5�оʹ�ӡ5��* 
//			printf("* ");
//		printf("\n");
//	}
//	return 0;
//}

//
//int main()
//{
//			for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-4d", i, j, i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//

////����������6��������A�����Ǵ�A��ʼ������4�����֡������������������ɵ����ظ����ֵ�3λ����
////������������ĵ�3λ����Ҫ���С����ÿ��6���������������Կո�ָ�������ĩ�����ж���ո�
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = n; i <= n + 3; i++)  //��λ
//	{
//		for (int j = n; j <= n + 3 && j != i; j++)  //ʮλ
//		{
//			for (int k = n; k <= n + 3 && k != i && k != j; k++)  //��λ
//			{
//				int x = i * 100 + j * 10 + k;
//				printf("%d\n", x);
//			}
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int x, y;
//	double n;
//	scanf("%lf", &n);
//	int flag = 0;
//	for (x = 1;x <= sqrt(n); x++)
//	{
//		for (y = 1; y <= sqrt(n); y++)
//		{
//			if (((x * x + y * y) == n) && x <= y)
//			{
//				printf("%d %d\n", x, y);
//				flag = 1;
//			}
//		}
//	}
//	if (flag == 0)
//		printf("No Solution");
//	return 0;
//}