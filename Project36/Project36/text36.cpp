#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include <stdio.h>
#define MAXN 20

void strmcpy(char *t, int m, char *s);
void ReadString(char s[]); /* 由裁判实现，略去不表 */

int main()
{
	char t[MAXN], s[MAXN];
	int m;

	scanf("%d\n", &m);
	ReadString(t);
	strmcpy(t, m, s);
	printf("%s\n", s);

	return 0;
}

/* 你的代码将被嵌在这里 */
void strmcpy(char *t, int m, char *s)  //将*t的第m个字符开始复制给*s  一开始输入了*t,若m超过*t长度则为空
{
	/*if (t[m] != '\0')
	{
		for (int i = m - 1, int j = 0; t[i] != '\0'; i++, j++)
		{
			s[j] = t[i];
		}
	}*/
	/*else
		s = { 0 };*/
}


//typedef struct list
//{
//	char name[11];  //不超过10
//	int birth;
//	char phone[18];  //不超过17
//}list;
//int main()
//{
//	int n;
//	
//	scanf("%d", &n);
//	list *p;
//	p = (list*)malloc(sizeof(list)*n);
//
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s", p[i].name);
//		scanf("%d", &p[i].birth);
//		scanf("%s", p[i].phone);
//	}
//
//	list tmp;
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (p[j].birth < p[i].birth)  //出生早的放前面
//			{
//				tmp = p[i];
//				p[i] = p[j];
//				p[j] = tmp;
//			}
//		}
//	}
//	
//	for (int i = 0; i < n; i++)
//	{
//		printf("%s %d %s\n", p[i].name, p[i].birth, p[i].phone);
//	}
//	return 0;
//}
