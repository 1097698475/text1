#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAXN 10

void f(long int x, char *p);

int main()
{
	long int x;
	char s[MAXN] = "";

	scanf("%ld", &x);
	f(x, s);
	printf("%s\n", s);

	return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
void f(long int x, char *p)
{
	int i;
	int prebit[100];
	for (i = 0;; i++)
	{
		int bit = x % 16;
		prebit[i] = bit;
		x /= 16;
		if (x == 0)
			break;
	}
	int count = i; //prebit[i]��Ԫ�أ��������λ
}

//#include <stdio.h>
//#define MAXS 20
//
//void f(char *p);
//void ReadString(char *s); /* �ɲ���ʵ�֣���ȥ���� */
//
//int main()
//{
//	char s[MAXS];
//
//	ReadString(s);
//	f(s);
//	printf("%s\n", s);
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//void f(char *p)
//{
//	int i = 0;
//	while (*(p + i) != '\0')
//		i++;
//	int count = i;   //count�ǳ���
//	char temp;
//	for (i = 0; i < count/2; i++)
//	{
//		temp = p[i];
//		p[i] = p[count - 1 - i];
//		p[count - 1 - i] = temp;
//	}
//}

//#include <stdio.h>
//#define MAXS 15
//
//void StringCount(char *s);
//void ReadString(char *s); /* �ɲ���ʵ�֣���ȥ���� */
//
//int main()
//{
//	char s[MAXS];
//
//	ReadString(s);
//	StringCount(s);
//
//	return 0;
//}
//
///* Your function will be put here */
//#include<string.h>
//void StringCount(char *s)
//{
//	int Num = 0, num = 0, space = 0, shu = 0, other = 0;
//	int count = strlen(s);
//	for (int i = 0; i < count; i++)
//	{
//		if (s[i] >= 'a'&&s[i] <= 'z')
//			num++;
//		else if (s[i] >= 'A'&&s[i] <= 'Z')
//			Num++;
//		else if (s[i] >= '0'&&s[i] <= '9')
//			shu++;
//		else if (s[i] == ' ')
//			space++;
//		else
//			other++;
//	}
//	printf("%d %d %d %d %d", Num, num, space, shu, other);
//}

//void delchar(char *str, char c)
//{
//	int i, j, l = strlen(str);
//	for (i = 0; i < l; i++)
//	{
//		while (str[i] == c)		//����Ԫ��
//		{
//			for (j = i; j < l; j++)
//			{		//str[i+1]���Ԫ������
//				str[j] = str[j + 1];
//			}
//			l--;              //�ַ������ȼ�һ
//		}
//	}
//}