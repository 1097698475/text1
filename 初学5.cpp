#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define nmax 50
int main()
{
	int i, k, m, n, num[nmax], *p;
	printf("please input the total of numbers:");
	scanf("%d", &n);
	p = &num[0];
	for (i = 0; i < n; i++)
		*(p + i) = i + 1;
	i = 0, k = 0, m = 0;
	for (m = 0;m<n-1;)
	{
		if (*(p + i) != 0 )
		{
			k++;
		}
		if (k == 3)//数到三则把序号改为0
		{
			*(p + i) = 0;
			k = 0;
			m++;//排除的人
		}
		i++;
		if (i == n)
			i = 0;

	}
	for(i=0;;i++)
		if (*(p + i) != 0)
		{
			printf("%d is left", *(p + i));
			break;
		}
}


//int main()
//{
//	int a[10];
//	int i;
//	int *p = a;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (i = 0,p=a; p <a+ 10; p++)
//	{
//		printf("%d   ", *p);
//	}
//}


//int main()
//{
//	int a[10];
//	int i;
//	int *p = a;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", p++);
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d", *p);
//		p++;
//	}
//}


//int main()
//{
//	int a[10];
//	int i;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	/*for (i = 0; i < 10; i++)
//		printf("%d ", *(a + i));*/
//	int *p = a;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//
//}


//int main()
//{
//	int a, b;
//	int *p1, *p2, *p3;
//	scanf("%d %d", &a, &b);
//	p1 = &a;
//	p2 = &b;
//	if (a < b)
//	{
//		p3 = p1;
//		p1 = p2;
//		p2 = p3;
//	}
//	printf("%d %d", *p1, *p2);
//}


//int main()
//{
//	int a, b;
//	int *p1, *p2;
//	a = 10;
//	b = 20;
//	p1 = &a;
//	p2 = &b;
//	printf("%d %d\n", a, b);
//	printf("%d %d", p1, p2);
//}


//int main()
//{
//	char city[5][20] = { "广州","武汉","上海","北京","成都" };
//	char t[20];
//	int i, j;
//	for (i = 0; i < 4; i++)
//	{
//		for (j = i + 1; j < 5; j++)
//		{
//			if (strcmp(city[i], city[j]) > 0)
//			{
//				strcpy(t, city[i]);
//				strcpy(city[i], city[j]);
//				strcpy(city[j], t);
//			}
//		}
//	}
//	for (i = 0; i < 5; i++)
//		//puts(city[i]);
//		printf("%s\t", city[i]);
//}


//int main()
//{
//	char name[] = "zheng dongqi", password[] = "123456", user[100], psw[100];
//	for (int i = 0;; i++)
//	{
//		printf("请输入用户名：");
//		gets_s(user);
//		_strlwr(user);
//		printf("请输入密码：");
//		gets_s(psw);
//		if (strcmp(name, user) != 0 || strcmp(password, psw) != 0)
//			printf("用户名或密码输入错误，请重新输入！\n");
//		else
//		     break;
//	}
//	printf("\n欢迎您:%s",name);
//	
//}


//int main()
//{
//	char s1[] = "Hello World";
//	char s2[100];
//	gets_s(s2);
//	printf("%s\n",_strlwr(s1));
//    printf("%s\n",_strupr(s2));
//	strcpy(s1, s2);
//	printf("%s\n", _strlwr(s1));
//}


//int main()
//{
//	printf("d", strcmp("abcd", "ABCD"));
//}


//int main()
//{
//	char s1[100], s2[100];
//	gets_s(s1);
//	gets_s(s2);
//	strcpy(s1, s2);
//	puts(s1);
//
//}


//int main()
//{
//	char s1[100], s2[100];
//	gets_s(s1);
//	printf("%s", strcat(s1, " hello world"));
//}



//int main()
//{
//	char s1[100], s2[20];
//	char s[100];
//	gets_s(s1);
//	gets_s(s2);
//	printf("%s", strcat(s1, s2));
//}


//int main()
//{
//	char s[100];
//	printf("输入一个字符串：\n");
//	gets_s(s);
//	for (int i = 0; i < strlen(s); i++)
//	{
//		if (s[i] >= 'A'&& s[i]<= 'Z');
//		{ 
//			printf("%c", s[i]);
//		}
//	}
//}


//int main()
//{
//	char s[100] = "how are youuuuu";
//	printf("%d", strlen(s));
//
//}



//int main()
//{
//	char name[15];
//	gets_s(name);
//	puts(name);
//}


//int main()
//{
//	char s1[15];
//	char s2[2][15];
//	int i;
//	gets_s(s1);
//	for (i = 0; i < 2; i++)
//	{
//		gets_s(s2[i]);
//	}
//	puts(s1);
//	for (i = 0; i < 2; i++)
//		puts(s2[i]);
//}


//int main()
//{
//	char name[15];
//	for (int i = 0; i < 15; i++)
//	{
//		name[i] = getchar();
//		putchar(name[i]);
//	}
//}


//int main()
//{
//	char name[20];
//	scanf("%s", name);
//	printf("%s", name);
//}



//int main()
//{
//	int name[10];
//	for (int i = 0; i < 10; i++)
//	{
//		name[i] = getchar();
//		putchar(name[i]);
//	}
//}


//int main()
//{
//	char str6[3][13] = { "how are you","good moring","good bye" };
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 13; j++)
//			printf("%c", str6[i][j]);
//		printf("\n");
//	}
//
//}
//int main()
//{
//	char str1[6] = "hello";
//	for(int i=0;i<6;i++)
//	   printf("%c", str1[i]);
//}


//#define M 50
//#define N 6
//#define B 2
//int main()
//{
//	int score[B][M][N];
//	int sum[B][M];
//	int m, n, b;
//	int i, j;
//	for (b = 0; b < 2; b++)
//	{
//		printf("%d班\n", b + 1);
//		printf("学生人数 ：");
//		scanf("%d", &m);
//		printf("课程数量 ：");
//		scanf("%d", &n);
//		for (i = 0; i < m; i++)
//			for (j = 0; j < n; j++)
//				scanf("%d", &score[b][m][n]);
//		putchar('\n');
//		printf("学号\t语文\t数学\t英语\t总分");
//		for (i = 0; i < m; i++)
//		{
//			printf("%d\t", i + 1);
//			sum[b][i] = 0;
//			for (j = 0; j < n; j++)
//			{
//				printf("%d\t", score[b][i][j]);
//				sum[b][i] = sum[b][i] + score[b][i][j];
//			}
//			printf("%d\n", sum[b][i]);
//		}
//		printf("\n");
//	}
//}


//#define M 50
//#define N 10
//int main()
//{
//	int score[M][N];
//	int m, n;
//	int sum[M];
//	int i, j;
//	printf("学生人数 ：");
//	scanf("%d", &m);
//	printf("课程数量 ：");
//	scanf("%d", &n);
//	for (i = 0; i < m; i++)
//		for (j = 0; j < n; j++)
//			scanf("%d",&score[i][j]);
//	//putchar('\n');
//	printf("\n");
//	printf("学号\t语文\t数学\t英语\t总分\n");
//	for (i = 0; i < m; i++)
//	{
//		printf("%d\t", i + 1);
//		sum[i] = 0;
//		for (j = 0; j < n; j++)
//		{
//			printf("%3d\t", score[i][j]);
//			sum[i] = score[i][j] + sum[i];
//		}
//		
//		printf("%d\n", sum[i]);
//	}
//}


//int main()
//{
//	int a[3][4] = { 1,2,3,4,9,8,7,6,-10,10,-5,2 };
//	int i, j, hang, lie,max;
//	hang = 0, lie = 0, max = a[0][0];
//	for(i = 0; i < 3;i++)
//		for (j = 0; j < 4; j++)
//		{
//			if (a[i][j] > max)
//			{
//				max = a[i][j];
//				hang = i;
//				lie = j;
//			}
//		}
//	printf("max = %d,row = %d,colum = %d", max, hang, lie);
//}


//int main()
//{
//	int a[][4] = { 0,1,0,0,1,0,0,0,2,6,4 };
//	int i;
//	for(i=0;i<12;i++)
//	{
//		printf("%4d", a[0][i]);
//		if (i % 4 == 3)
//		{
//			printf("\n");
//		}
//	}
//}


//int main()
//{
//	int a[3][4];
//	int hang, lie;
//	hang = sizeof(a) / sizeof(a[0]);
//	lie = sizeof(a[0]) / sizeof(int);
//	printf("%d %d", hang, lie);
//}


//int main()
//{
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int i;
//	for (i = 0; i < 12; i++)
//		printf("%4d", a[0][i]);
//
//}


//int main()
//{
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int i, j;
//	for (i = 0; i < 3; i++)
//		for (j = 0; j < 4; j++)
//			printf("%4d", a[0][4 * i + j]);
//}


//int main()
//{
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int i, j;
//	for (i = 0; i < 3; i++)
//		for (j = 0; j < 4; j++)
//			printf("%4d", a[i][j]);
//
//}


//int main()
//{
//	int score[10], i, num[5] = { 0,0,0,0,0 };
//	for (i = 0; i < 10; i++)
//		scanf("%d", &score[i]);
//	//putchar('\n');
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		switch (score[i] / 10)
//		{
//		case 0:
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//			num[0]++;
//			break;
//		case 6:
//			num[1]++;
//			break;
//		case 7:
//			num[2]++;
//			break;
//		case 8:
//			num[3]++;
//			break;
//		case 9:
//		case 10:
//			num[4]++;
//			break;
//		}
//	}
//	printf("各分数段的人数为：\n");
//	printf("0-60\t60-69\t70-79\t80-89\t90-100\n");
//	for (i = 0; i < 5; i++)
//		printf("%d\t", num[i]);
//	return 0;
//}


//int main()
//{
//	int i, j, del=0,x=5;
//	int a[10] = { 1,2,3,4,5,5,7,8,9,10 };
//	for (i = 0; i < 10; i++)
//		printf("%d ", a[i]);
//	putchar('\n');
//	for (i = 0; i < 10-del; i++)
//	{
//		if (a[i] == 5)
//		{
//			for (i; i < 10; i++)
//				a[i] = a[i + 1];
//			del++;
//			i--;
//		}
//	}
//	for (i = 0; i < 10 - del; i++)
//		printf("%d ", a[i]);
//}


//int main()
//{
//	int i, score[11],x,j;
//	for (i = 0; i < 10; i++)
//		scanf("%d", &score[i]);
//	printf("\n");
//	printf("待插入数据 ： ");
//	scanf("%d", &x);
//	for (i = 0; i < 10; i++)
//	{
//		if (x < score[i])
//		{
//			for (j=10;j>=i;j--)
//				score[j + 1] = score[j];
//			score[i] = x;
//			break;
//		}
//	}
//	for (i = 0; i < 11; i++)
//		printf("%4d", score[i]);
//}


//int main()
//{
//	int score[10],i,t;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &score[i]);
//	}
//	for (i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 30-i-1; j++)
//		{
//			if (score[i] > score[i + 1])
//			{
//				t = score[i + 1];
//				score[i + 1] = score[i];
//				score[i] = t;
//			}
//		}
//	}
//	for (i = 0; i < 10; i++)
//		printf("%4d", score[i]);
//}


//int main()
//{
//	int score[20];
//	int i,a,num=0;
//	for (i = 0; i < 20; i++)
//	{
//		scanf("%d", &score[i]);
//	}
//	printf("请输入想查找的分数 ： ");
//		scanf("%d\n", &a);
//	
//		for (i = 0; i < 20; i++)
//		{
//			if (score[i] == a)
//			{
//				num++;
//				printf("score[%d] = %d", i, a);
//			}
//		}
//		printf("有%d个同学分数为%d", num, a);
//}


//int main()
//{
//	int a[10];
//	int min, max;
//	scanf("%d", &a[0]);
//	min = max = a[0];
//	for (int i = 1; i <= 10; i++)
//	{
//		scanf("%4d", &a[1]);
//		if (a[i] < a[0])
//		{
//			a[0] = a[i];
//		}
//		max = max > a[i] ? max : a[i - 1];
//
//	}
//}



//int main()
//{
//	int a[20];
//	int max, min;
//	scanf("%d", &a[0]);
//	min = a[0];
//	max = a[0];
//	for (int i = 1; i < 20; i++)
//	{
//		scanf("%d", &a[i]);
//		min = min < a[i] ? min : a[i];
//		max = max > a[i] ? max : a[i - 1];
//
//	}
//	printf("%d %d", min, max);
//}


//int main()
//{
//	int a[20] = { 1,1 };
//	for (int i = 2; i < 20; i++)
//		a[i] = a[i - 1] + a[i - 2];
//	for (int i = 0; i < 20; i++)
//	{
//		if (i % 5 == 0)
//			printf("\n");
//		printf("%8d", a[i]);
//		
//	}
//}


//int main()
//{
//	int a[20], i;
//	a[0] = 1, a[1] = 1;
//	printf("%d %d ", a[0], a[1]);
//	for (i = 2; i <= 19; i++)
//	{
//		a[i] = a[i - 1] + a[i - 2];
//		printf("%d ", a[i]);
//
//	}
//}
