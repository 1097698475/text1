#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdlib.h>//系统函数
#include<time.h>
#include<string.h>//字符串函数
#include<stdio.h>



//int main()
//{
//	char input[20];
//	system("shutdown -s -t 60");
//again:
//	printf("请注意，你的电脑在一分钟内关机，如果输入：我是猪，就取消关机\n");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪")==0)//string compare,     跟异或一样，相同为0
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//		return 0;
//}



//1.    0^a=a
//2.    a^a=0
//3.    异或满足交换律

//so,   1^2^3^4^5^1^2^3^4=1^1^2^2^3^3^4^4^5=5
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4 };
//	int i;
//	int ret=0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		ret = ret ^ arr[i];
//	}
//	printf("%d", ret);
//	return 0;
//}


//找一个单身狗的暴力求法
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		int count = 0;
//		int j;
//		for (j = 0; j < sz; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				count++;
//			}
//		}
//		if (count == 1)
//		{
//			printf("%d", arr[i]);
//			break;
//		}
//	}
//
//}


//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("交换前：a=%d,b=%d\n", a, b);
//
//	a = a ^ b;//^为按（二进制）位异或，3的二进制为011,5的二进制为101,相同为0，相异为1，故a^b=110
//	b = a ^ b;
//	a = a ^ b;
//	ptintf("交换后：a=%d,b=%d", a, b);
//
//	/*a = a + b;
//	b = a - b;
//	a = (a - b) ;*/
//	printf("%d %d", a, b);
//}