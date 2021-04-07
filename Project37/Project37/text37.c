#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include <stdio.h>
#define MAXN 10

struct student {   //学号，姓名，成绩已设置好
	int num;
	char name[20];
	int score;
	char grade;   //grade:0~59=D 60~69=C 70~84=B 85~100=A
};

int set_grade(struct student *p, int n);  //统计不及格人数

int main()
{
	struct student stu[MAXN], *ptr;
	int n, i, count;

	ptr = stu;
	scanf("%d\n", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%s%d", &stu[i].num, stu[i].name, &stu[i].score);
	}
	count = set_grade(ptr, n);
	printf("The count for failed (<60): %d\n", count);
	printf("The grades:\n");
	for (i = 0; i < n; i++)
		printf("%d %s %c\n", stu[i].num, stu[i].name, stu[i].grade);   //按原顺序打印出来
	return 0;
}

/* 你的代码将被嵌在这里 */
int set_grade(struct student *p, int n)  //p是指向结构体数组的指针 n是人数
{
	for (int i = 0; i < n; i++)
	{
		switch (p[i].score)
		{
			case 
		}
	}
}

#include <stdio.h>
int main(void) {
	int a1, a2, hh, mm;
	scanf("%d %d", &a1, &a2);
	hh = a2 / 100 - a1 / 100;
	mm = a2 % 100 - a1 % 100;
	if (mm < 0) {
		mm = mm + 60;
		hh = hh - 1;
	}
	printf("%02d:%02d", hh, mm);/*%d就是普通的输出了

								%2d是将数字按宽度为2，采用右对齐方式输出，若数据位数不到2位，则左边补空格

								%02d，和%2d差不多，只不过左边补0

								%.2d没见过，但从执行效果来看，和%02d一样*/
	return 0;
}


//int main()
//{
//	int choice;
//	switch (choice) {
//	case choice == 1: price = 3.0; break;
//	case choice == 2: price = 2.5; break;
//	case choice == 3: price = 4.0; break;
//	case choice == 4: price = 3.5; break;
//	default: price = 0.0; break;
//	}
//
//
//	/*int x = 2;
//	if (x % 2)
//		printf("trud");*/
//	/*float a = 4;
//	a += a /= a * a;
//	printf("%f", a);*/
//	/*int a; float b;
//	scanf("%3d%f", &a, &b);
//	printf("%d %f", a, b);*/
//	//int a = 0, b = 0;
//	//a = b = a + 5;  //从右往左 a=b=5   从左往右 a=0
//	//printf("%d %d", a, b);
//	//*double f;
//	/*f = (2.0, 1.0, 0.0), (3.0, 4.0, 5.0);
//	printf("%lf", f);*/
//	/*int a = 4, b = 3, c = 2, d = 1, m = 1, n = 3;
//	(m = a > b > c) && (n = c > d);
//	printf("%d", n);*/
//	/*int a = 2, b = 0, c = -1;
//	printf("%d", a < b || b < c && b);*/
//	//printf("%d", !0);
//	/*if ('D' - 'A' == 'd' - 'a')
//		printf("true");*/
//	return 0;
//}


//int min(int);
//int main()
//{
//	int st, ar;
//	scanf("%d %d", &st, &ar);
//	
//	//距离零点的分钟数   1050%100=60,1050/100=10  10*60
//	int st1, ar1;
//	st1 = min(st);
//	ar1 = min(ar);
//	int time = ar1 - st1;
//	//printf("%d\n", time);
//
//	//将相差时间time变成hh:mm   //m等于60时进一
//	int h = time / 60;
//	int m = time % 60;
//	if (m == 60)
//	{
//		m = 0;
//		h += 1;
//	}
//	printf("%02d:%02d", h, m);
//
//	return 0;
//}
//int min(int bef)
//{
//	int min;
//	min = bef % 100;
//	bef /= 100;
//	min += bef * 60;
//}

//int main()
//{
//	double x;
//	scanf("%lf", &x);
//	double ans;
//	if (x >= 0)
//		ans = sqrt(x);
//	else
//		ans = (x + 1)*(x + 1) + 2 * x + 1 / x;
//	printf("f(%.2f) = %.2f", x, ans);
//	return 0;
//}


//int main()
//{
//	char text;
//	scanf("%c", &text);
//	if (text >= '0'&&text <= '9')
//		printf("This is a digit.");
//	else if (text >= 'a'&&text <= 'z')
//		printf("This is a small letter.");
//	else if (text >= 'A'&&text <= 'Z')
//		printf("This is a capital letter.");
//	else
//		printf("Other character.");
//
//	return 0;
//}


//int main()
//{
//	int a, b;
//	char mid;
//	scanf("%d %c %d", &a, &mid, &b);
//	switch (mid)
//	{
//		case '+':
//		{
//			printf("%d",a + b);
//			break;
//		}
//		case '-':
//		{
//			printf("%d", a - b);
//			break;
//		}
//		case '*':
//		{
//			printf("%d", a*b);
//			break;
//		}
//		case '/':
//		{
//			printf("%d", a / b);
//			break;
//		}
//		case '%':
//		{
//			printf("%d", a%b);
//			break;
//		}
//		default:
//		{
//			printf("ERROR");
//			break;
//		}
//	}
//	return  0;
//}


//int main()
//{
//	int arr[3];
//	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
//	for (int i = 0; i < 2; i++)
//	{
//		int tmp = 0;
//		for (int j = i + 1; j < 3; j++)
//		{
//			if (arr[i] > arr[j])
//			{
//				tmp = arr[j];
//				arr[j] = arr[i];
//				arr[i] = tmp;
//			}
//		}
//	}
//	printf("%d->%d->%d", arr[0], arr[1], arr[2]);
//
//	return 0;
//}


//int main()
//{
//	int day;
//	scanf("%d", &day);
//	if (1 <= day % 5 && day % 5 <= 3)
//		printf("Fishing in day %d", day);
//	else
//		printf("Drying in day %d", day);
//	return 0;
//}


//int main()
//{
//	double a, b, ans;
//	scanf("%lf %lf", &a, &b);
//	ans = (double)a / b;
//	if (b == 0)
//		printf("%.0f/%.0f=Error", a, b);
//	else if (b < 0)
//		printf("%.0f/(%.0f)=%.2f", a, b, ans);
//	else
//		printf("%.0f/%.0f=%.2f", a, b, ans);
//	return 0;
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	if (n > 0)
//		printf("sign(%d) = 1", n);
//	else if (n == 0)
//		printf("sign(0) = 0");
//	else
//		printf("sign(%d) = -1", n);
//	return 0;
//}