#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAXN 20

void delchar(char *str, char c);
void ReadString(char s[]); /* 由裁判实现，略去不表 */

int main()
{
	char str[MAXN], c;

	scanf("%c\n", &c);
	ReadString(str);

	delchar(str, c);
	printf("%s\n", str);

	return 0;
}

/* 你的代码将被嵌在这里 */
// 其中char *str是传入的字符串，c是待删除的字符。\
函数delchar的功能是将字符串str中出现的所有c字符删除。
//void delchar(char *str, char c)
//{
//	for (int i = 0; i <= MAXN - 1; i++)  // 从第一个开始判断是否为c，直到最后一个
//	{
//		int j = i;
//		if (str[i] == c)  // 若是c，则下一个填充到当前位置  一直到最后一个元素的前一个
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
	{	//从后向前遍历数组
		if (str[i] == c) 
		{	//如果当前元素等于删除元素
			for (l = i; l < MAXN - 1; l++) 
			{	//从当前元素位置向后循环
				str[l] = str[l + 1];	//用后一个元素替换当前元素
			}
		}
	}
}

//void delchar(char *str, char c)  //如a,happy year->hppy yer
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
///* 你的代码将被嵌在这里 */
//#include<string.h>
////函数palindrome判断输入字符串char *s是否为回文。若是则返回true，否则返回false
//bool palindrome(char *s)
//{
//	int n = strlen(s);
//	if (n % 2 == 0)
//	{
//		for (int i = 0; i < n / 2; i++)  //若长度为6，则i<3：012
//		{
//			if (s[i] != s[n - 1 - i])  //0~5,1~4,2~3
//				return false;
//		}
//		return true;
//	}
//	if (n % 2 == 1)
//	{
//		for (int i = 0; i < n / 2; i++)  //若长度为5，则i<2：01
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
//void ReadString(char *s); /* 由裁判实现，略去不表 */
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
//void StringCount(char *s) //其中 char *s 是用户传入的字符串。函数StringCount须在一行内按照
//{
//	int upper = 0, lower = 0, space = 0, num = 0, other = 0;
//	int i = 0;
//	//while (s[i] != '\0')
//	//{
//	//	//对s[i]作判断
//	//}
//	//或者
//	char *p = s;  //之后把p当数组看待
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
//void StringCount(char *s) //其中 char *s 是用户传入的字符串。函数StringCount须在一行内按照
//{
//	// 大写字母个数 小写字母个数 空格个数 数字个数 其它字符个数
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