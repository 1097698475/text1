#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int main()
{
	int m, n; //��Χ��m��n
	scanf("%d %d", &m, &n);
	int sum = 0;
	int count = 0;
	for (int i = m; i <= n; i++)  //��m��ʼ�ж��Ƿ�Ϊ������һֱ��n
	{
		int ying = 0;  //����һ��ʼΪ0
		for (int j = 1; j <= i; j++)  //��Լ����1��ʼ��һֱ������������Լ��==2����ʾΪ����
		{
			if (i%j == 0)
			{
				ying++;
			}
		}
		if (ying == 2)
		{
			count++;
			sum += i;
			//printf("%d\n", i);
		}
	}
	printf("%d %d", count, sum);
	return 0;
}

//int main()
//{
//	int a, b;
//	char ch;
//	scanf("%d", &a);
//	int flag = 1;
//	for (int i = 0;; i++)
//	{
//		scanf("%c", &ch);
//		if (ch != '=')
//		{
//			scanf("%d", &b);
//			switch (ch)
//			{
//			case '+':a = a + b; break;
//			case '-':a = a - b; break;
//			case '*':a = a * b; break;
//			case '/': 
//			{
//				if (b == 0)
//				{
//					printf("ERROR");
//					flag = 0;
//				}
//				else
//					a = a / b;
//				break;
//			}
//			default:printf("ERROR"); flag = 0; break;
//			}
//		}
//		else
//		{
//			flag = 0;
//			printf("%d", a);
//		}
//		if (flag == 0)
//			break;
//	}
//	return 0;
//}

//#include<math.h>
//int main()
//{
//	double a, b, c;
//	scanf("%lf %lf %lf", &a, &b, &c);
//	double slt1, slt2;  //���̵Ľ�
//
//	if (a == 0)  //һԪһ��
//	{
//		if (b == 0)
//		{
//			if (c == 0)
//			{
//				printf("Zero Equation");
//			}
//			else  //c������0
//			{
//				printf("Not An Equation");
//			}
//		}
//		else  //b������0
//		{
//			slt1 = -c / b;
//			printf("%.2f", slt1);
//		}
//	}
//	else  //a������0
//	{
//		double disc;  //���б�ʽ
//		disc = b * b - 4 * a * c;
//		//printf("%.2f", disc);
//
//		if (disc > 0)  //������Ϊһ������ֱ�Ӹ���slt������Ҫ����b��c
//		{
//			slt1 = (-b + sqrt(disc)) / (2 * a);
//			slt2 = (-b - sqrt(disc)) / (2 * a);
//			if (slt1 > slt2)
//				printf("%.2f\n%.2f", slt1, slt2);
//			else
//				printf("%.2f\n%.2f", slt2, slt1);
//		}
//		else if (disc == 0)
//		{
//			slt1 = -b / (2 * a);
//			printf("%.2f", slt1);
//		}
//		else  //�б�ʽС��0�������⣬��������Ϊһ������ֱ�Ӹ���slt����Ҫ����b��c
//		{
//			disc = -disc;  //�б�ʽ����෴�����ܸ���
//			double from = -b / (2 * a);  //ʵ����Ҫ�ж�ʵ���Ƿ�Ϊ0
//			double back = sqrt(disc) / (2 * a);
//
//			if (b != 0)
//			{
//				printf("%.2f+%.2fi\n%.2f-%.2fi", from, back, from, back);
//			}
//
//			else  //ʵ��Ϊ0��ֻ��ӡ�鲿����
//			{
//				printf("%.2fi\n-%.2fi", back, back);
//			}
//		}
//	}
//	return 0;
//}