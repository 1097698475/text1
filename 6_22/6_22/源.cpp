#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	char pre_ip[40]; //32������
	gets_s(pre_ip);
	int count = 0;
	for (count = 0; count < 4; count++)
	{
		int sum = 0;
		int item = 1;
		int i;
		for (i = count * 8 + 7; i >= count * 8; i--)
		{
			if (pre_ip[i] == '1')
			{
				sum += item;
			}
			item *= 2;
			//printf("%d ", sum);
		}
		//printf("\n");
		printf("%d", sum);
		if (count != 3)
			printf(".");
	}
	return 0;
}

//#include<math.h>
//
//int main()
//{
//	double a, b, c;
//	scanf("%lf %lf %lf", &a, &b, &c);
//	if (a == 0)
//	{
//		if (b == 0)
//		{
//			if (c == 0)
//				printf("Zero Equation");
//			else
//				printf("Not An Equation");
//		}
//		else
//			printf("%.2f", -c / b);
//	}
//	else
//	{
//		double del = b * b - 4 * a*c;
//		if (del > 0)
//		{
//			printf("%.2f\n", (-b + sqrt(del)) / (2 * a));
//			printf("%.2f", (-b - sqrt(del)) / (2 * a));
//		}
//		else if (del == 0)
//		{
//			printf("%.2f", -b / (2 * a));
//		}
//		else
//		{
//			del = -del;
//			if (-b / (2 * a) != 0)
//			{
//				printf("%.2f+%.2fi\n%.2f-%.2fi", -b / (2 * a), sqrt(del) / (2 * a), -b / (2 * a), sqrt(del) / (2 * a));
//			}
//			else
//			{
//				printf("+%.2fi\n-%.2fi", sqrt(del) / (2 * a), sqrt(del) / (2 * a));
//			}
//		}
//	}
//	return 0;
//}
//
//#include<stdio.h>
//
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
//			if (from != 0)
//			{
//				printf("%.2f+%.2fi\n%.2f-%.2fi", from, back, from, back);
//			}
//
//			else  //ʵ��Ϊ0��ֻ��ӡ�鲿����
//			{
//				printf("0.00+%.2fi\n0.00-%.2fi", back, back);
//			}
//		}
//	}
//	return 0;
//}

//#include<math.h>
//
//int main()
//{
//	double eps;
//	scanf("%lf", &eps);
//	double item, sum = 0;
//	double i, flag = -1;
//	int fflag = 0;
//	for (i = 1;; i += 3)
//	{
//		flag = -flag; //��һ���flagΪ����
//		item = flag * (1 / i);
//		if (fabs(item) > eps)
//		{
//			sum += item;
//		}
//		else
//		{
//			sum += item;
//			break;
//		}
//	}
//	printf("sum = %.6f", sum);
//	return 0;
//}
//
//#include<stdio.h>
//
//int main()
//{
//	double limit;
//	double sum = 0;
//	double a, text;
//	scanf("%lf", &limit);
//
//	for (int i = 1;; i++)
//	{
//		if (i % 2 == 1)
//			a = 1;
//		else
//			a = -1;
//		text = 1.0 / (i * 3 - 2);
//		sum += a * text;
//		if (text <= limit)
//			break;
//	}
//	printf("sum = %.6f", sum);
//	return 0;
//}

//int main()
//{
//	int a, b;
//	char ch;
//	int flag = 1;
//	scanf("%d", &a);
//	while ((ch = getchar()) != '=')
//	{
//		scanf("%d", &b);
//		switch (ch)
//		{
//		case '+':a = a + b; break;
//		case '-':a = a - b; break;
//		case '*':a = a * b; break;
//		case '/':
//		{
//			if (b == 0)
//			{
//				printf("ERROR");
//				flag = 0;
//				break;
//			}
//			else
//			{
//				a = a / b;
//				break;
//			}
//		}
//		default: printf("ERROR"); flag = 0; break;
//		}
//	}
//	if(flag)
//		printf("%d", a);
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//int a, b;
//char ch;
//scanf("%d", &a);
//int flag = 1;
//for (int i = 0;; i++)
//{
//	scanf("%c", &ch);
//	if (ch != '=')
//	{
//		scanf("%d", &b);
//		switch (ch)
//		{
//		case '+':a = a + b; break;
//		case '-':a = a - b; break;
//		case '*':a = a * b; break;
//		case '/':
//		{
//			if (b == 0)
//			{
//				printf("ERROR");
//				flag = 0;
//			}
//			else
//				a = a / b;
//			break;
//		}
//		default:printf("ERROR"); flag = 0; break;
//		}
//	}
//	else
//	{
//		flag = 0;
//		printf("%d", a);
//	}
//	if (flag == 0)
//		break;
//}
//return 0;
//}

//int main()
//{
//	int hour, min;
//	scanf("%d:%d", &hour, &min);
//	if (hour >= 0 && hour <= 12)
//	{
//		printf("Only %02d:%02d.  Too early to Dang.", hour, min);
//	}
//	else
//	{
//		int i;
//		if (min == 0)
//		{
//			for (i = 1; i <= hour - 12; i++)
//			{
//				printf("Dang");
//			}
//		}
//		else
//		{
//			for (i = 1; i <= hour - 11; i++)
//			{
//				printf("Dang");
//			}
//		}
//	}
//	return 0;
//}
//
//
//#include<stdio.h>
//
//int main()
//{
//	int hour, min;
//	scanf("%d:%d", &hour, &min);
//
//	if (hour >= 0 && hour <= 11)
//		printf("Only %02d:%02d.  Too early to Dang.", hour, min);
//
//	if (hour >= 12)
//	{
//		int count;
//		if (hour == 12 && min == 0)
//		{
//			printf("Only %02d:%02d.  Too early to Dang.", hour, min);
//		}
//		else
//		{
//			count = hour % 12;
//			if (min > 0)
//				count++;
//			for (int i = 0; i < count; i++)
//				printf("Dang");
//		}
//	}
//	return 0;
//}