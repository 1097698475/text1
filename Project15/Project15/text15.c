#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdlib.h>//ϵͳ����
#include<time.h>
#include<string.h>//�ַ�������
#include<stdio.h>



//int main()
//{
//	char input[20];
//	system("shutdown -s -t 60");
//again:
//	printf("��ע�⣬��ĵ�����һ�����ڹػ���������룺��������ȡ���ػ�\n");
//	scanf("%s", input);
//	if (strcmp(input, "������")==0)//string compare,     �����һ������ͬΪ0
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
//3.    ������㽻����

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


//��һ�������ı�����
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
//	printf("����ǰ��a=%d,b=%d\n", a, b);
//
//	a = a ^ b;//^Ϊ���������ƣ�λ���3�Ķ�����Ϊ011,5�Ķ�����Ϊ101,��ͬΪ0������Ϊ1����a^b=110
//	b = a ^ b;
//	a = a ^ b;
//	ptintf("������a=%d,b=%d", a, b);
//
//	/*a = a + b;
//	b = a - b;
//	a = (a - b) ;*/
//	printf("%d %d", a, b);
//}