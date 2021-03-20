#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define nmax 81

int main()
{
	char arr[nmax];
	int n;
	scanf("%d", &n);
	scanf("%s", arr);
	for (int i = 0; i < n; i++)
		printf("%c ", arr[i]);
	/*int sz = sizeof(arr) / sizeof(arr[0]);*/
	printf("%d", sz);
	return 0;
}

//int main()
//{
//	double r3 = cos(30*pai / 180);
//	printf("%.2f\n", r3);
//	double x;
//	scanf("%lf", &x);
//	double r1 = cos(x * pai / 180);
//	printf("%.2f\n", r1);
//
//}

//int main()
//{
//	double x;
//	scanf("%lf", &x);
//	double r1 = sin(pai / 3 + 1);
//	//printf("%.2f\n", r1);
//	double r2 = (sin(pai / 6) + 1);
//	//printf("%.2f\n", r2);
//
//	double r3 = cos(x * pai / 180);
//	//printf("%.2f\n", r3);
//
//	double r4 = r1 * r2 / r3;
//	//printf("%.2f\n", r4);
//
//	double r5 = sqrt(r4);
//	printf("%.2f\n", r5);
//
//	return 0;
//}

//int main()
//{
//	printf("****\n");
//	printf("***\n");
//	printf("**\n");
//	printf("*\n");
//
//	return 0;
//}


//int main()
//{
//	int A, B;
//	scanf("%d %d", &A, &B);
//	printf("%d", A*B);
//	return 0;
//}


//int main()
//{
//	unsigned int x;
//	scanf("%d", &x);
//	int add = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		int wei = x % 10;
//		add += wei;
//		x /= 10;
//	}
//	printf("%d", add);
//	return 0;
//}


//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//
//	printf("%d + %d = %d\n",a,b, a + b);
//	printf("%d - %d = %d\n",a,b, a - b);
//	printf("%d * %d = %d\n",a,b, a * b);
//	printf("%d / %d = %d", a,b,a / b);
//
//}

//int main()
//{
//	double x;
//	scanf("%lf", &x);
//	double result1 = sin(pai / 3 + 1)*((sin(pai / 6)) + 1) / cos(x*pai / 180);
//	double result2 = sqrt(result1);
//	printf("%.2f", result2);
//	return 0;
//}

//int main()
//{
//	int hight;
//	double weight;
//	scanf("%d", &hight);
//	printf("%.1f", (hight - 100)*0.9 * 2);
//	return 0;
//}

//void my_scanf(int *,int);
//void print(int *, int);
//int main()
//{
//	int arr1[nmax], n1;
//	int arr2[nmax], n2;
//	int i, j;
//	scanf("%d", &n1);
//	my_scanf(arr1,n1);
//	//print(arr1, n1);
//	scanf("%d", &n2);
//	my_scanf(arr2, n2);
//	//print(arr2, n2);
//
//
//	return 0;
//}
//void my_scanf(int *p,int n)
//{
//	for (int i = 0; i < n; i++)
//		scanf("%d", p++);
//}
//
//
//void print(int *p,int n)
//{
//	for (int i = 0; i < n; i++)
//		printf("%d ", *p++);
//}


//int main()
//{
//	char c = '\060';
//	printf("%d", sizeof(c));
//	/*int c = M + M;
//	printf("%d", c);
//	printf("M =3567\n");
//	printf("M = M\n");*/
//
//	/*char a = '/678';
//	char b = '\"';
//	char c = ' ';
//	char d = '\4';*/
//
//	/*printf("%d\n", nmax);
//	printf("%c\n", a);
//	printf("%c\n", b);
//	printf("%c\n", c);
//	printf("%c\n", d);*/
//
//}

//struct date
//{
//	int year;
//	int month;
//	int day;
//};
//struct student
//{
//	int d; 
//	struct date d1;
//}stu1;
//struct student
//{
//	char name[10];
//	int age;
//	
//	struct date birthday;
//};
//int main()
//{
//	struct student stu1,stu2;
//	stu1.birthday.day;
//	struct date day1;
//	day1 = { 2000,01,01 };
//	//struct date day2 = { .year = 2001,.month = 02,.day = 03 };
//	printf("birthday is %d-%d-%d\n", day1.year, day1.month, day1.day);
//	printf("birthday is %i-%i-%i\n", day1.year, day1.month, day1.day);
//	stu1 = { {"xiaoming"},20 };
//	printf("student name is: %s , student age is %d\n", stu1.name, stu1.age);
//	stu2 = stu1;
//	printf("student name is: %s , student age is %d\n", stu2.name, stu2.age);
//
//
//}

//int main()
//{
//	char a = 65;
//	char b = '65';
//	//char c = A;
//	char d = 'A';
//	char e = 'AB';
//	//char f = /65;
//	char g = '/65';
//	printf("a = %d , a = %c\n", a, a);
//	printf("b = %d , b = %c\n", b, b);
//	printf("d = %d , d = %c\n", d, d);
//	printf("e = %d , e = %c\n", e, e);
//	printf("g = %d , e = %c\n", e, e);
//
//}

//int main()
//{
//	int m, n;
//	int i, j;
//	int arr1[nmax][nmax];
//	int arr2[nmax][nmax];
//	scanf("%d %d", &m, &n);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &arr1[i][j]);
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			arr2[i][(j + m) % n] = arr1[i][j];
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%d ", arr2[i][j]);
//		}
//		printf("\n");
//	}
//}

//struct time
//{
//
//};
//int main()
//{
//	char ch[100];
//	ch = gets();
//
//	return 0;
//}


//int main()
//{
//	int n;
//	int *a = 0;
//	scanf("%d", &n);
//	a = (int *)malloc(n * sizeof(int));
//	int i, sum = 0;
//	double max, min;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//		sum += a[i];
//		if (i == 0)
//		{
//			max = a[0];
//			min = a[0];
//		}
//		else
//		{
//			a[i] > max ? max = a[i] : max;
//			a[i] < min ? min = a[i] : min;
//		}
//	}
//
//	printf("average = %.2f\n", (double)sum / n);
//	printf("max = %.2f\n", max);
//	printf("min = %.2f\n", min);
//	return 0;
//}
