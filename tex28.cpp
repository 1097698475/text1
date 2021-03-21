#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int main()
{
	double limit;
	scanf("%lf", &limit);
	double sum = 0;
	double a, text;
	
	for(int i = 1;; i++)
	{
		if (i % 2 == 1)
			a = 1;
		else
			a = -1;
		text = 1.0 / (i * 3 - 2);
		sum += a * text;
		if (text <= limit)
			break;
	}
	printf("%.6f", sum);
	return 0;
}

//int main()
//{
//	double limit;
//	scanf("%lf", &limit);
//	int i;
//	double front;
//	double sum = 0;
//	for (i = 1;; i++)
//	{
//		i % 2 == 1 ? front = 1 : front = -1;
//		if (1.0 / (i * 3 - 2) <= limit)
//			break;
//		sum += front / (i * 3 - 2);
//	}
//	printf("%.6f", sum);
//	return 0;
//}