#include<stdio.h>
int main()
{
	int a[10],i,sum=0,num=0;
	double ave;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (i = 0; i < 10; i++)
	{
		if (a[i] >= 60)
			num++;
	}
	ave = sum / 10;
	printf("average = %lf\n", ave);
	printf("through = %d", num);
}


//int main()
//{
//	int i, a[10];
//	for (i = 1; i <= 9; i++)
//	{
//		a[i] = 0;
//		printf("%d ", a[i]);
//	}
//}


//int main()
//{
//	int i, a[5];
//	for (i = 0; i < 5; i++)
//	{
//		a[i] = i;
//		printf("%d ", a[i]);
//	}
//}