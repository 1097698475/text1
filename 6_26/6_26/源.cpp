#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double foot, inch;//Ò»Ó¢³ßµÈÓÚ12Ó¢´ç
	double cm;
	scanf("%lf", &cm);

	return 0;
}

//int main()
//{
//	//2.12 88 c 4.7
//	//c 88 2.12 4.70
//	char ch;
//	int a;
//	double dou1, dou2;
//	scanf("%lf %d %c %lf", &dou1, &a, &ch, &dou2);
//	printf("%c %d %.2f %.2f", ch, a, dou1, dou2);
//	return 0;
//}
//int main()
//{
//	double d1, d2;
//	int in;
//	char ch;
//	scanf("%lf", &d1);
//	scanf("%d", &in);
//	getchar();
//	scanf("%c", &ch);
//	scanf("%lf", &d2);
//	printf("%c %d %.2f %.2f", ch, in, d1, d2);
//	return 0;
//}

//int main()
//{
//	int x;
//	scanf("%d", &x);
//	int test = x;
//	int i, item = 1;
//	int bit[20];
//	for (i = 0;test != 0; i++)
//	{
//		bit[i] = test % 10;
//		test /= 10;
//	}
//	int count = i;
//	//printf("%d\n", count);
//	int result = 0;
//	for(i = count - 1; i >= 0; i--)
//	{
//		result += bit[i]*item;
//		item *= 10;
//	}
//	printf("%d", result);
//	return 0;
//}

//int main()
//{
//	int x;
//	scanf("%d", &x);
//	int bit[100];
//	int i;
//	for (i = 0;x!=0; i++)
//	{
//		bit[i] = x % 10;
//		x /= 10;
//	}
//	int count = i - 1;
//	for (i = 0; i < count; i++)
//	{
//		
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int text;
//	scanf("%d", &text);
//	int result = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		int bit = text % 10;
//		text /= 10;
//		if (bit != 0)
//		{
//			result = result + bit * pow(10, 2 - i);
//		}
//	}
//	printf("%d", result);
//	return 0;
//}