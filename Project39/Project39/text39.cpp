#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include <stdio.h>
#define MAXS 15

void StringCount(char *s);
void ReadString(char *s); /* 由裁判实现，略去不表 */

int main()
{
	char s[MAXS];

	ReadString(s);
	StringCount(s);

	return 0;
}

/* Your function will be put here */
#include<string.h>
void StringCount(char *s) //其中 char *s 是用户传入的字符串。函数StringCount须在一行内按照
{
	int upper = 0, lower = 0, space = 0, num = 0, other = 0;
	int i = 0;
	//while (s[i] != '\0')
	//{
	//	//对s[i]作判断
	//}
	//或者
	char *p = s;  //之后把p当数组看待
	i = 0;
	while (*p != '\0')
	{
		if (*p >= 'A'&&*p <= 'Z')
			upper++;
		else if (*p >= 'a'&&*p <= 'z')
			lower++;
		else if (*p == ' ')
			space++;
		else if (*p >= '0'&&*p <= '9')
			num++;
		else
			other++;
		p++;
	}

	/*while (p[i] != '\0')
	{
		if (p[i] >= 'A'&&p[i] <= 'Z')
			upper++;
		else if (p[i] >= 'a'&&p[i] <= 'z')
			lower++;
		else if (p[i] == ' ')
			space++;
		else if (p[i] >= '0'&&p[i] <= '9')
			num++;
		else
			other++;
		i++;
	}*/
	printf("%d %d %d %d %d", upper, lower, space, num, other);
}


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



//int MIN(int, int);
//int main()
//{
//	int x, y;
//	scanf("%d %d", &x, &y);
//	int min = MIN(x, y);
//	printf("%d", min);
//	return 0;
//}
//int MIN(int a, int b)
//{
//	if (a < b)
//		return a;
//	else
//		return b;
//}


//#include <stdio.h>
//
//struct complex {
//	int real;
//	int imag;
//};
//
//struct complex multiply(struct complex x, struct complex y);
//
//int main()
//{
//	struct complex product, x, y;
//
//	scanf("%d%d%d%d", &x.real, &x.imag, &y.real, &y.imag);
//	product = multiply(x, y);
//	printf("(%d+%di) * (%d+%di) = %d + %di\n",
//		x.real, x.imag, y.real, y.imag, product.real, product.imag);
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//struct complex multiply(struct complex x, struct complex y)
//{
//	//返回乘后的结构体
//	struct complex result;
//	result.real = x.real*y.real - x.imag*y.imag;
//	result.imag = x.imag*y.real + x.real*y.imag;
//	return result;
//}


//struct stu
//{
//	char name[20];
//	int score;
//};
//int main()  //总结：指针指向单个结构体可用->,指向结构体数组时p2代表数组，不能用->
//{
//	struct stu text1, text2[10], *p1 = NULL, *p2 = NULL;
//	p1 = &text1;
//	p2 = text2;   //数组名为地址
//	
//	//输入text1 结构体：有两种方法，推荐第一种
//	scanf("%s", &p1->name);
//	scanf("%d", &(*p1).score);
//	//  不行：scanf("%d", &p1.score);
//
//	//输出text1  结构体：两种方法 推荐第一种
//	printf("%d\n", p1->score);
//	printf("%s\n", (*p1).name);
//
//	//输入text2 结构体
//	scanf("%d", &p2[0].score);  //p2不是指针（地址）吗，为什么还要加&
//	scanf("%s", p2[0].name);
//	//  不行：scanf("%d", &p2[0]->score);
//	//  不行：scanf("%s", &(*p2[0]).name);
//
//	//输出text2 结构体
//	printf("%d\n", p2[0].score);
//	//  不行：printf("%s\n", p2[0]->name);  //由上面可知p2不是指针，是数组，那为什么也不能这样输出？
//	return 0;
//}


//#include <stdio.h>
//#define MAXN 10
//
//struct student {   //学号，姓名，成绩已设置好
//	int num;
//	char name[20];
//	int score;
//	char grade;   //grade:0~59=D 60~69=C 70~84=B 85~100=A
//};
//
//int set_grade(struct student *p, int n);  //统计不及格人数
//
//int main()
//{
//	struct student stu[MAXN], *ptr;
//	int n, i, count;
//
//	ptr = stu;
//	scanf("%d\n", &n);
//	for (i = 0; i < n; i++) {
//		scanf("%d%s%d", &stu[i].num, stu[i].name, &stu[i].score);
//	}
//	count = set_grade(ptr, n);
//	printf("The count for failed (<60): %d\n", count);
//	printf("The grades:\n");
//	for (i = 0; i < n; i++)
//		printf("%d %s %c\n", stu[i].num, stu[i].name, stu[i].grade);   //按原顺序打印出来
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//int set_grade(struct student *p, int n)  //p是指向结构体数组的指针 n是人数
//{
//	int count = 0;  //不及格人数
//	for (int i = 0; i < n; i++)
//	{
//		if (p[i].score <= 59)
//		{
//			count++;
//			p[i].grade = 'D';
//		}
//		if (p[i].score >= 60 && p[i].score <= 69)
//			p[i].grade = 'C';
//		if (p[i].score >= 70 && p[i].score <= 84)
//			p[i].grade = 'B';
//		if (p[i].score >= 85 && p[i].score <= 100)
//			p[i].grade = 'A';
//	}
//	return count;
//}
