#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAXN 20

void delchar(char *str, char c);
void ReadString(char s[]); /* �ɲ���ʵ�֣���ȥ���� */

int main()
{
	char str[MAXN], c;

	scanf("%c\n", &c);
	ReadString(str);

	delchar(str, c);
	printf("%s\n", str);

	return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
// ����char *str�Ǵ�����ַ�����c�Ǵ�ɾ�����ַ���\
����delchar�Ĺ����ǽ��ַ���str�г��ֵ�����c�ַ�ɾ����
//void delchar(char *str, char c)
//{
//	for (int i = 0; i <= MAXN - 1; i++)  // �ӵ�һ����ʼ�ж��Ƿ�Ϊc��ֱ�����һ��
//	{
//		int j = i;
//		if (str[i] == c)  // ����c������һ����䵽��ǰλ��  һֱ�����һ��Ԫ�ص�ǰһ��
//		{
//			for (j; j < MAXN - 1; j++)
//			{
//				str[j] = str[j + 1];
//			}
//		}
//	}
//}

void delchar(char *str, char c) 
{
	int i, l;
	for (i = MAXN - 1; i >= 0; i--)
	{	//�Ӻ���ǰ��������
		if (str[i] == c) 
		{	//�����ǰԪ�ص���ɾ��Ԫ��
			for (l = i; l < MAXN - 1; l++) 
			{	//�ӵ�ǰԪ��λ�����ѭ��
				str[l] = str[l + 1];	//�ú�һ��Ԫ���滻��ǰԪ��
			}
		}
	}
}

//void delchar(char *str, char c)  //��a,happy year->hppy yer
//{
//	char *p = str;
//	int i = 0;
//	while (p[i] != '\0')
//	{
//		int j = i;
//		if (p[i] == c)
//		{
//			while (p[j] != '\0')
//			{
//				p[j] = p[j + 1];
//				j++;
//			}
//		}
//	}
//}





//#include <stdio.h>
//#include <string.h>
//
//#define MAXN 20
//typedef enum { false, true } bool;
//
//bool palindrome(char *s);
//
//int main()
//{
//	char s[MAXN];
//
//	scanf("%s", s);
//	if (palindrome(s) == true)
//		printf("Yes\n");
//	else
//		printf("No\n");
//	printf("%s\n", s);
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//#include<string.h>
////����palindrome�ж������ַ���char *s�Ƿ�Ϊ���ġ������򷵻�true�����򷵻�false
//bool palindrome(char *s)
//{
//	int n = strlen(s);
//	if (n % 2 == 0)
//	{
//		for (int i = 0; i < n / 2; i++)  //������Ϊ6����i<3��012
//		{
//			if (s[i] != s[n - 1 - i])  //0~5,1~4,2~3
//				return false;
//		}
//		return true;
//	}
//	if (n % 2 == 1)
//	{
//		for (int i = 0; i < n / 2; i++)  //������Ϊ5����i<2��01
//		{
//			if (s[i] != s[n - 1 - i])  //0~4,1~3,2
//				return false;
//		}
//		return true;
//	}
//}



//#include<string.h>
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
//void StringCount(char *s) //���� char *s ���û�������ַ���������StringCount����һ���ڰ���
//{
//	int upper = 0, lower = 0, space = 0, num = 0, other = 0;
//	int i = 0;
//	//while (s[i] != '\0')
//	//{
//	//	//��s[i]���ж�
//	//}
//	//����
//	char *p = s;  //֮���p�����鿴��
//	i = 0;
//	while (*p != '\0')
//	{
//		if (*p >= 'A'&&*p <= 'Z')
//			upper++;
//		else if (*p >= 'a'&&*p <= 'z')
//			lower++;
//		else if (*p == ' ')
//			space++;
//		else if (*p >= '0'&&*p <= '9')
//			num++;
//		else
//			other++;
//		p++;
//	}
//
//	/*while (p[i] != '\0')
//	{
//		if (p[i] >= 'A'&&p[i] <= 'Z')
//			upper++;
//		else if (p[i] >= 'a'&&p[i] <= 'z')
//			lower++;
//		else if (p[i] == ' ')
//			space++;
//		else if (p[i] >= '0'&&p[i] <= '9')
//			num++;
//		else
//			other++;
//		i++;
//	}*/
//	printf("%d %d %d %d %d", upper, lower, space, num, other);
//}

//#include<string.h>
//void StringCount(char *s) //���� char *s ���û�������ַ���������StringCount����һ���ڰ���
//{
//	// ��д��ĸ���� Сд��ĸ���� �ո���� ���ָ��� �����ַ�����
//	int upper = 0, lower = 0, space = 0, num = 0, other = 0;
//	int n = strlen(s);
//	for (int i = 0; i < n; i++)
//	{
//		if (s[i] >= 'A'&&s[i] <= 'Z')
//			upper++;
//		else if (s[i] >= 'a'&&s[i] <= 'z')
//			lower++;
//		else if (s[i] == ' ')
//			space++;
//		else if (s[i] >= '0'&&s[i] <= '9')
//			num++;
//		else
//			other++;
//	}
//	printf("%d %d %d %d %d", upper, lower, space, num, other);
//
//}