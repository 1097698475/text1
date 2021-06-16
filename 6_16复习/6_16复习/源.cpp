#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{

	return 0;
}

//int main()
//{
//	char str[5][100];
//	int i, j = 0;
//	for (i = 0; i < 5; i++)
//	{
//		scanf("%s", &str[i][j]);
//	}
//	int arrange_index[5];
//	int temp;
//	for (i = 0; i < 4; i++)
//	{
//		for (j = i; j < 5; j++)
//		{
//			if (str[i] > str[j])
//			{
//				temp = j;
//				arrange_index[i] = j;
//				arrange_index[j] = i;
//			}
//		}
//	}
//	return 0;
//}

//int main()
//{
//	char twomode[17];
//	gets_s(twomode);
//	int i, count = strlen(twomode), j;
//	int  item , bit = 0;
//	int result = 0;
//	for (i = count - 1; i >= 0; i--)
//	{
//		bit++;  //第1位  10^0
//		item = 1;  //10的幂要初始化为1
//		for (j = 1; j < bit; j++)
//		{
//			item *= 2;
//		}
//		result += (twomode[i]-'0') * item;
//	}
//	printf("%d", result);
//	return 0;
//}

//int main()
//{
//	char str[30];
//	char ch = getchar();
//	int n = 0, i = 0;
//	while (ch != '#')
//	{
//		n++;
//		str[i++] = ch;
//		ch = getchar();
//	}
//	getchar();
//	for (i = 0; i < n; i++)
//	{
//		if (str[i] >= 'a'&&str[i] <= 'z')
//		{
//			str[i] -= 32;
//		}
//		else if (str[i] >= 'A'&&str[i] <= 'Z')
//		{
//			str[i] += 32;
//		}
//		printf("%c", str[i]);
//	}
//	return 0;
//}

//int main()
//{
//	char str[80];
//	gets_s(str);
//	int count = strlen(str);
//	int i;
//	int n = 0;
//	for (i = 0; i < count; i++)
//	{
//		if (str[i] >= 'A'&&str[i] <= 'Z')
//		{
//			if (str[i] != 'A'&&str[i] != 'E'&&str[i] != 'I'&&str[i] != 'O'&&str[i] != 'U')
//				n++;
//		}
//	}
//	printf("%d", n);
//	return 0;
//}