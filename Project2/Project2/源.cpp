#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	double n;
//	n = 100 / 9;
//	printf("%.0f%", n);
//}
int main()
{
	double v, vm;
	double n;
	scanf("%lf %lf", &v, &vm);
	if (v < 1.1*vm)
	{
		printf("OK");
	}
	else if (v >= 1.1*vm&&v < 1.5*vm)
	{
		n = ((v-vm) / vm )*100;
		printf("Exceed %.0f%. Ticket 200",n);
	}
	else
	{
		n = ((v - vm) / vm) * 100;
		printf("Exceed %.0f%. License Revoked",n);
	}
}
//int main()
//{
//	int year, Y, n;
//	scanf("%d", &n);
//	if (n <= 2000 || n>2100)
//	{
//		printf("Invalid year!");
//	}
//	else if(n>=2004)
//	{ 
//		for (year = 2004; year <=n; year++)
//		{
//			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//			{
//				Y = year;
//				printf("%d\n", Y);
//			}
//		}
//	}
//	else
//	{
//		printf("None");
//	}
//	return 0;
//	
//}
//int main()
//{
//	int a, b;
//	printf("a= ");
//	scanf("%d", &a);
//	printf("b= ");
//	scanf("%d", &b);
//
//}


//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//int main()
//{
//	int a, b, c, d;
//	char q;
//	srand(time(0));
//	a = rand() % 100;
//	b = rand() % 100;
//	c = a + b;
//	printf("please compute:%d+%d= ", a, b);
//	scanf("%d", &d);
//	if (c == d)
//	{
//		printf("congratulation!");
//	}
//	else
//	{
//		printf("you are wrong,your answer is:%d\n", d);
//		printf("do you want the right answer?(y/n)");
//		scanf("%c%c",&q, &q);
//		if (q == 'y' || q == 'y')
//			printf("the right answer is:%d\n", c);
//
//	}
//	return 0;
//}

//int main()
//{
//	
//	double a,b;
//	scanf("%lf", &a);
//	b = a / 9;
//	printf("%lf", b);
//}

//int main()
//{
//	int a1, a2;
//	//int i;
//	double i,c;
//	scanf("%d %d", &a1, &a2);
//	if(0<a1&&a1<a2&&a2<=100)
//
//	{
//		printf("fahr celsius\n");
//		for (i = a1; i <= a2; i += 2)
//		{
//			c = 5 * (i - 32) / 9;
//			printf("%.0f   %.1f\n", i, c);
//		}
//	}
//	else
//	{
//		printf("Invalid.");
//	}
//
//}

//int main()
//{
//	int n,s;
//	scanf("%d", &n);
//	if (n > 0)
//	{
//		s = 1;
//	}
//	else if (n < 0)
//	{
//		s = -1;
//	}
//	else
//	{
//		s = 0;
//	}
//	printf("sign(%d) = %d", n, s);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	int s = 0;
//	scanf("%d", &s);
//	for (n = 1; n <= s; n++)
//	{
//		for (i = 1, ret = 1; i <= n; i++)
//		{
//			ret = ret * i;
//		}
//		sum = sum + ret;
//	}
//	printf("sum = %d", sum);
//	return 0;
//}


//#include<math.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	double i, sum=0;
//	for (i = 1; i <= n; i++)
//	{
//		sum = sum + sqrt(i);
//	}
//	printf("sum = %.2f", sum);
//
//}

//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n,a;
//	double s=1, i;
//	scanf("%d", &n);
//	for (i = 2; i <=n; i++)
//	{
//		a = pow(-1,(i-1));
//		s = s + a * i / (2 * i - 1);
//	}
//	printf("%.3f", s);
//	return 0;
//}

//int main()
//{
//	int m, n;
//	double i1,i2;
//	double s1=0.000000, s2=0.000000, sum;
//	scanf("%d %d", &m, &n);
//	for (i1 = m; i1 <= n; i1++)
//	{
//		s1 =s1+ i1 * i1;
//		//s2 = s2 + 1 / i1;
//	}
//	for (i2 = m; i2 <= n; i2++)
//	{
//		s2 = s2 + 1 / i2;
//	}
//	sum = s1 + s2;
//	printf("sum = %lf", sum);
//}

//int main()
//{
//	int num1;
//	double cost;
//	scanf("%d", &num1);
//	if (num1 >= 0 && num1 <= 50)
//	{
//		cost = num1 * 0.53;
//		printf("cost = %.2f", cost);
//	}
//	else if (num1 > 50)
//	{
//		cost = 26.5 + (num1 - 50)*0.58;
//		printf("cost = %.2f", cost);
//	}
//	else
//	{
//		printf("Invalid Value!");
//
//	}
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, c, d;
//	double Sum,Average;
//	scanf("%d %d %d %d", &a, &b, &c, &d);
//	Sum = a + b + c + d;
//	Average = Sum / 4;
//	printf("Sum = %.0f; Average = %.1f", Sum, Average);
//	return 0;
//}

//#include<stdio.h>
//double fact(int a)
//{
//	double sum = 1;
//	int i;
//	for (i = 1; i <= a; i++)
//	{
//		sum = sum * i;
//
//	}
//	return sum;
//}
//int main()
//{
//	int m,n;
//	double f;
//	scanf("%d %d", &m, &n);
//	f = fact(n) / (fact(m)*fact(n - m));
//	printf("result = %lf", f);
//	return 0;
//
//
//}

//#include<math.h>
//int main()
//{
//	int n,a,i;
//	scanf("%d", &n);
//	for (i = 0; i <= n; i++)
//	{
//		a = pow(3, i);
//		printf("pow(3,%d) = %d\n", i, a);
//	}
//}

//#include<math.h>
//int main()
//{
//	int n,a;
//	double S=0,i,sum;
//	scanf("%d", &n);
//	for (i = 1; i <= 3*n-2; i+=3)
//	{
//		a = pow(-1, i + 1);
//		S = S + a * (1 / i);
//	}
//	printf("sum = %.3f", S);
//	return 0;
//
//}


//int main()
//{
//	int x,n;
//	scanf("%d", &x);
//	n = x / 10;
//	switch (n)
//	{
//	case 10:
//	case 9:
//		printf("A");
//		break;
//	case 8:
//		printf("B");
//		break;
//	case 7:
//		printf("C");
//		break;
//	case 6:
//		printf("D");
//		break;
//	default:
//		printf("E");
//		break;
//	}
//
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int x, y, z,t;
//	scanf("%d %d %d", &x, &y, &z);
//	if (x > y)
//		t = x, x = y, y = t;
//	if (x > z)
//		t = x, x = z, z = t;
//	if (y > z)
//		t = y, y = z, z = t;
//	printf("%d->%d->%d", x, y, z);
//	return 0;
//
//}


//int main()
//{
//	int y;
//	double x;
//	printf("x=");
//	scanf("%lf", &x);
//	if (x >= 0)
//	{
//		y = 1;
//
//	}
//	else
//	{
//		y = -1;
//	}
//	
//	printf("y=%d\n", y);
//	return 0;
//}




//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k=12;
//	int i;
//	int sz = sizeof(arr) / sizeof(arr[1]);
//	for (i = 0; i < sz; i++)
//	{
//		if (k == arr[i])
//		{
//			printf("catch it! the number is %d\n", i);
//			break;
//
//		}
//		
//	}
//	if (i == sz)
//		printf("miss");


//int main()//n阶乘，前n阶乘的和
//{
//	int i=0;
//	int n=0;
//	int ret = 1;
//	int sum = 0;
//	int s=0;
//	scanf("%d", &s);
//	for (n = 1; n <= s; n++)
//	{
//		for (i = 1,ret=1; i <= n; i++)
//		{
//			ret = ret * i;
//		}
//	sum = sum + ret;
//	}
//	printf("sum=%d", sum);
//	return 0;
//}


//int main()
//{
//	int i;
//	int n;
//	int ret = 1;
//	scanf("%d", &n);
//	for(i=1;i<=n;i++)
//	{
//		ret = ret * i;
//	}
//	printf("ret=%d", ret);
//	return 0;
//}
//int main()
//{
//	int x, y;
//	for (x = 0, y = 0; x < 2 && y < 5; ++x )
//	{
//		printf("hahaha\n");
//
//	}
//}


//#include<stdio.h>
//int main()//只输入数字
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)//EOF是end of file
//	{
//		if (ch<'0' || ch>'9')
//			continue;
//		putchar(ch);
//	}
//}

//int main()
//{
//    int a, b;
//	double c;
//	scanf("%d %d", &a, &b);
//	printf("fahr celsius");
//	if (a <= b <= 100)
//	{
//		while (a < b)
//			c = 5 * (a - 32) / 9;
//		printf("%d %.1f", a, c);
//		a += 2;
//
//	}
//	else
//		printf("invaild");
//
//}

//#include<stdio.h>
//#include <math.h>
//int main()
//{
//	double x, result,a,b,c;
//	scanf("%lf", &x);
//	if (x >= 0)
//		result = pow(x, 0.5);
//	else
//	{
//		a = (x + 1)*(x + 1);
//		b = 2 * x;
//		c = 1 / x;
//		result = a + b + c;
//	}
//	printf("f(%.2f)=%.2f", x, result);
//
//}

//int main()
//{
//	float  x, result;
//	scanf("%f", &x);
//	if (x == 0)
//	{
//		result = 0;
//	}
//	else
//	{
//		result = 1 / x;
//	}
//	printf("f(%.1f)=%.1f", x, result);
//	return 0;
//		
//}

//int main()
//{
//	int i = 0;
//	while (i <= 10)
//	{
//		i++;
//		if (i == 5)
//			continue;
//		printf("%d\n", i);
//
//		/*if (i == 5)
//			continue;
//		printf("%d\n", i);
//		i++;*/
//	}
//}

//int main()
//{
//	int i = 0;
//	while (i <= 10)
//	{
//        printf("%d\n", i);
//		i = i + 1;
//		if (i == 5)
//			break;
//	}
//
//}


//int main()
//{
//	int n = 1;
//	int m = 1;
//	switch (n)
//	{
//	case 1:
//		n = n + 1;
//		m = m + 1;
//	case 2:
//		n++;
//		m++;
//	case 3:
//	
//			switch (n)
//			{
//			case 2:
//				n = n + 2;
//				m = m + 2;
//			case 3:
//				n++;
//				m++;
//				break;
//			}
//	case5:
//		printf("n=%d,m=%d\n", n, m);
//		break;
//	case4:
//		m++;
//		break;
//	
//	}
//	printf("n=%d,m=%d", n, m);
//}

//int main()
//{
//	int day;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case1:
//	case2:
//		printf("work\n");
//		break;
//	case3:
//	case4:
//		printf("relax\n");
//		break;
//	}
//		
//}

//int main()
//{
//	int day;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("work");
//		break;
//	case 6:
//	case 7:
//		printf("sunsun");
//		break;
//	default:
//		printf("fault");
//		break;
//
//	}
//}


//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	if (1 == day)
//		printf("星期一");
//	else if (2 == day)
//		printf("星期二");
//	else
//		printf("其他");
//}




//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		printf("%d\n", i);
//i += 2;
	//	if (i % 2 == 1)
	//		printf("%d ", i);
	//	i = i + 1;
	//	i++;
	//	i += 1;

//int main()
//{
//	short num;
//	scanf("%d", &num);
//	if (4 == num)
//		printf("hhrhrhr");
//	else
//		printf("sbsbsbsb");
//	return 0;
//}


//{
//	int a = 0;
//	int b = 1;
//	if (a == 1)
//	{
//		if (b == 1)
//			printf("jrjr");
//		else
//			printf("erer");
//	}
//	else
//		printf("ssss");
//	return 0;
//
//}
//{
//	int age = 20;
//	if (age < 18)
//	{
//		printf("未成年");
//		printf("shangdaxue");
//	}
//
//	else {
//		if (age >= 18 && age < 20)
//			printf("freeman");
//		else
//			printf("standard");
//
//	}
//		
//			return 0;
//}


//int main()
//{
//	printf("hello world");
//	return 0;
//}