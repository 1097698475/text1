#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main() //�������
//{   //�����ж��������Ƿ�Ϊż����������\2һֱ����ȫΪż��
//    //
//
//	return 0;
//}


//int main() //շת�����
//{// �����������ȡ�������̣�����������������С�����������������Ϊ0�����ϴε�����Ϊ���Լ��
//	int m, n;
//	scanf("%d %d", &m, &n);
//	int max, min;
//	if (m < n)
//		max = n, min = m;
//	else
//		max = m, min = n;
//	while (1)
//	{
//		int yu = max % min;
//		if (yu != 0)
//		{
//			max = min;
//			min = yu;
//		}
//		else
//			break; //�������=0����minΪ���Լ��
//	}
//	printf("%d %d", min,m*n/min);
//	return 0;
//}

//int main()
//{
//	int n;
//	int i;
//	for (i = 1;; i++)
//	{
//		scanf("%d", &n);
//		if (n == 250)
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//	return 0;
//}


//
//int main()
//{
//	int letter = 0, digit = 0, blank = 0, other = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		char c = getchar();
//		if ((c >= 'a'&&c <= 'z') || (c >= 'A'&& c <= 'Z'))
//			letter++;
//		else if (c == ' '||c=='\n')
//			blank++;
//		else if (c >= '0'&&c <= '9')
//			digit++;
//		else
//			other++;
//	}
//	printf("letter = %d, blank = %d, digit = %d, other = %d", letter, blank, digit, other);
//	return 0;
//}