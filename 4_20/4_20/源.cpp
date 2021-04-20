#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char arr[100] = { 0 };
	int count = 0;
	int i = 0;
	while ((arr[i] = getchar() != '\n'))
	{
		i++; 
	}
	for (int j = i - 1; j >= 0; j--)
		printf("%c", arr[j]);

	return 0;
}


//#include<stdio.h>
//
//int main()
//{
//	int n, max, maxnumber, arr[100];
//	int i;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (i == 0)
//		{
//			max = arr[0];
//			maxnumber = 0;
//		}
//		if (i > 0 && max < arr[i])
//		{
//			max = arr[i];
//			maxnumber = i;
//		}
//	}
//	printf("%d %d", max, maxnumber);
//	return 0;
//}
//// 6
//// 2 8 10 1 9 10
//// 10 2
//int main()
//{
//	int n;
//	int arr[100];
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		scanf("%d", &arr[i]);
//	int max = arr[0], index = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//			index = i;
//		}
//	}
//	printf("%d %d", max, index);
//	//for (int i = 0; i < n; i++)
//	//	if (arr[i] == max)
//	//		index = i;
//
//	return 0;
//}

//int main()
//{
//	int fen5 = 0, fen2 = 0, fen1 = 0;
//	int fee;  //Ç®
//	int count = 0; //·½·¨Êý
//	scanf("%d", &fee);
//	for (fen5 = fee/5; fen5 >=1; fen5--)
//		for(fen2 = fee/2; fen2 >= 1;fen2--)
//			for (fen1 = fee/1; fen1 >= 1; fen1--)
//			{
//				if ((5 * fen5 + 2 * fen2 + 1 * fen1) == fee)
//				{
//					printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", fen5, fen2, fen1, fen5 + fen2 + fen1);
//					count++;
//				}
//			}
//	printf("count = %d", count);
//	return 0;
//}