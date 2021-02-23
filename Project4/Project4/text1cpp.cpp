#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	int n, sum=1;
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++)
	{
		sum = (sum + 1) * 2;
	}
	printf("%d", sum);
}


//int main()
//{
//	double h, n, s=0, hh,S;
//	scanf("%lf %lf", &h, &n);
//	for (int i = 1; i <= n; i++)
//	{
//		s = s + 2 * h;
//		hh = h;
//		h = h / 2;
//	}
//	S = s - 1;
//	printf("%.0f %.0f", S, hh);
//}

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int m;
//	m = (n + 1) / 2;
//	for (int a = 1; a <= m; a++)
//	{
//		for (int b=1; b <= n+1-2*a; b ++)
//		{
//			printf(" "); 
//		}
//		for (int c = 1; c <= 2*a-1; c++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//	for (int d = 1; d < m; d++)
//	{
//		for (int e = 1; e <= 2 * d; e++)
//		{
//			printf(" ");
//		}
//		for (int f = 1; f <= n - 2 * d; f++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//}


//int main()
//{
//	double x1, x2;
//	int min,max;
//	double yue, bei;
//	int i;
//	scanf("%lf %lf", &x1, &x2);
//	min = x1 < x2 ? x1 : x2;
//	max = x1 > x2 ? x1 : x2;
//	for (i = 1; i <= min; i++)
//	{
//		if (min%i == 0 && max%i == 0)
//		{
//			yue = i;
//		}
//
//	}
//	bei = min * max / yue;
//	printf("%.0f %.0f", yue, bei);
//}

//int main()
//{
//	int a, n;
//	for (n = 0;; n++)
//	{
//		a = getchar();
//		if (a == '\n')
//			break;
//	}
//	printf("%d", n);
//
//}


//int main()
//{
//	int a, n;
//	for (n = 1; n <= 10; n++)
//	{
//		a = getchar();
//		printf("%4d", a);
//	}
//
//	/*char a;
//	scanf("%c", &a);
//	printf("%d", a);*/
//
//	/*int c;
//	c = getchar();
//	printf("%d", c);*/
//
//}

//int main()
//{
//	int sum, fen1, fen2, fen5,count=0;
//	scanf("%d", &sum);
//	for (fen5=1 ;fen5<20; fen5++)
//		for(fen2=1;fen2<50;fen2++)
//			for (fen1 = 1; fen1 < 100; fen1++)
//			{
//				if (fen1 * 1 + fen2 * 2 + fen5 * 5 == sum)
//				{
//					int total = fen1 + fen2 + fen5;
//					count++;
//					printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", fen5, fen2, fen1, total);
//				}
//			}
//	printf("count = %d", count);
//	return 0;
//}



//int main()
//{
//	int i;
//	for (i = 1; i <= 20; i++)
//	{
//		if (i % 3 != 0)
//			printf("%d ",i);
//		else
//			continue;
//	}
//}


//int main()
//{
//	int key, n,text;
//	scanf("%d %d", &key, &n);
//	for (int i = 1;; i++)
//	{
//		if (i <= n)
//		{
//		    scanf("%d", &text);
//			if (text > 0)
//			{
//				if (text < key)
//					printf("Too small\n");
//				else if (text > key)
//					printf("Too big\n");
//				else if (text == key)
//				{
//					if (i == 1)
//					{
//						printf("Bingo!");
//						break;
//					}
//					else if (i == 2 || i == 3)
//					{
//						printf("Lucky You!");
//						break;
//					}
//					else if (i > 3 && i <= n)
//					{
//						printf("Good Guess!");
//						break;
//					}
//
//				}
//			}
//		}
//		else 
//		{
//			printf("Game Over");
//			break;
//		}
//		
//	}
//}

//int main()
//{
//	int a, n;
//	int i,b, sum = 0;
//	scanf("%d %d", &a, &n);
//	for (i = 0; i < n; i++)
//	{
//		b = pow(10, i);
//		sum = sum + (n-i)*b * a;
//	}
//	printf("s = %d", sum);
//}


//int main()
//{
//	double a1 = 2, a2 = 1,a3=2,sum=2;
//	int n;
//	scanf("%d", &n);
//	for (int i = 2; i <= n; i++)
//	{
//		a3 = a1;
//		a1 = a1 + a2;
//		a2 = a3;
//		sum = sum + a1 / a2;
//	}
//	printf("%.2f", sum);
//}


//int main()
//{
//	int a1=1, a2=1, a3;
//	int i;
//	printf("%d %d ", a1, a2);
//	for (i = 3; i <= 30; i++)
//	{
//		a3 = a1 + a2;
//		printf("%d ", a3);
//		a1 = a2;
//		a2 = a3;
//		if (i % 6 == 0)
//			printf("\n");
//	}
//}


//int main()
//{
//	double i, sum=0, t=1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum = sum + t * 1 / i;
//		t = -t;
//	}
//	printf("%lf", sum);
//}

//int main()
//{
//	int x, y, z;
//	printf("x = ");
//	scanf("%d", &x);
//	//z = x < 2 ? 1 : (x >= 10 ? 3 : 2);
//	//z = x < 2 ? 1 : (x >= 2 && x < 10 ? 2 : 3);
//	//z = 1 * (x < 2) + 2 * (2 <= x && x < 10) + 3 * (x >= 10);
//	switch (z)
//	{
//	case 1:
//		y = 100;
//		printf("%d", y);
//		break;
//	case 2:
//		y = 200;
//		printf("%d", y);
//		break;
//	case 3:
//		y = 300;
//		printf("%d", y);
//		break;
//
//	}
//}

//int main()
//{
//	double a1, a2, a3;
//	char fu;
//	printf("输入一个式子（如3*5）：");
//	scanf("%lf%c%lf", &a1, &fu, &a2);
//	switch (fu)
//	{
//	case '+':
//	{
//		a3 = a1 + a2;
//		printf("%.2f+%.2f=%.2f", a1, a2, a3);
//		break;
//	}
//	case '-':
//	{
//		a3 = a1 - a2;
//		printf("%.2f-%.2f=%.2f", a1, a2, a3);
//		break;
//	}
//	case '*':
//	 
//		a3 = a1 * a2;
//		printf("%.2f * %.2f=%.2f", a1, a2, a3);
//		break;
//	 
//	case '/':
//	 
//		a3 = a1 / a2;
//		printf("%.2f/%.2f=", a1, a2, a3);
//		break;
//	 
//	}
//}
//
//

//int main()
//{
//	int year, month, days;
//	printf("year = ");
//	scanf("%d", &year);
//	printf("month = ");
//	scanf("%d", &month);
//	switch (month)
//	{
//	case 1:
//	case 3:
//	case 5:
//	case 7:
//	case 8:
//	case 10:
//	case 12:
//	 {
//		days = 31;
//		break;
//	 }
//	case 4:
//	case 6:
//	case 9:
//	case 11:
//			days = 30;
//			break;
//	case 2:
//			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//			{
//				days = 29;
//			}
//			else
//			{
//				days = 28;
//			}
//			break;
//	}
//	printf("days = %d", days);
//
//}


//#define EPS 0.00001
//int main()
//{
//	double x, last=1, sum=1;
//	scanf("%lf", &x);
//	for (int i = 1;; i++)
//	{
//		last = last * x / i;
//		sum = sum + last;
//		if (last < EPS)
//		{
//			break;
//		}
//	}
//	printf("%.4f", sum);
//}



//#define EPS 0.00001
//
//int main() {
//	double x, res = 1;
//	double sum = 1;
//	scanf("%lf", &x);
//	for (int i = 1;; i++) {
//		res = res * (x / i);	// 每一项
//		sum += res;
//		if (res < EPS) {
//			break;
//		}
//	}
//	printf("%.4f", sum);
//	return 0;
//}

//int main()
//{
//	int num,sum=0,i;
//	for (i = 1;; i++)
//	{
//		scanf("%d", &num);
//		if (num>0&&num % 2 == 1)
//		{
//			sum = sum + num;
//		}
//		if (num <= 0)
//		{
//			break;
//		}
//	}
//	printf("sum = %d", sum);
//
//}

//int main()
//{
//	int n, num,min,i;
//	scanf("%d", &n);
//	scanf("%d", &num);
//	min = num;
//	for (i = 1; i <= n - 1; i++)
//	{
//		scanf("%d", &num);
//		if (num < min)
//		{
//			min = num;
//		}
//		
//	}
//	printf("min=%d", min);
//
//}

//int main()
//{
//	int a, b, d;
//	scanf("%d", &a);
//	scanf("%d", &b);
//	printf("aaaa");
//}
//int main()
//{
//	int M, N, i, chushu, l = 0, sum = 0, num = 0;
//	scanf("%d %d", &M, &N);
//	for (i = M; i <= N; i++)
//	{
//		for (chushu = 1; chushu <= i; chushu++)
//		{
//			if (i%chushu != 0) 
//                 l++;
//		}
//		if (l == i - 2)
//		{
//			sum = sum + i; num++;
//		}
//		l = 0;
//	}
//	printf("%d %d", num, sum);
//	return 0;
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		scanf("%d", &text);
//
//	}
//}
//int main()
//{
//	int N;
//	int a, b ;
//	double cheng1, cheng2=1;
//	scanf("%d", &N);
//	for (a = 1; a <= N; a++)
//	{
//		
//		for (b = 1,cheng1=1; b <= a; b++)
//		{
//			cheng1 = cheng1 * b;
//		}
//		cheng2 = 1 / cheng1 + cheng2;
//	}
//	printf("%.8lf", cheng2);
//}
//int main()
//{
//	int key, n;
//	int text,i;
//	int a, b, c;
//	scanf("%d %d", &key, &n);
//	for (i = 1; i <= n; i++)
//	{
//		scanf("%d", &text);
//		if (text == key)
//		{
//			a = a + 1;
//		}
//		else if (text < key)
//		{
//			b = b + 1;
//		}
//		else
//		{
//			c = c + 1;
//		}
//
//	}
//}
//

//
//
//
//
//int main()
//{
//	int number, n;
//	scanf("%d %d", &number, &n);
//	int i;
//	int cnt = 0;
//	int inp;
//	for (i = 1; i < 100; i++)
//	{
//		scanf("%d", &inp);
//		cnt++;
//		if (inp < 0) {
//			printf("Game Over");
//			break;
//		}
//		if (inp == number) {
//			if (cnt == 1) {
//				printf("Bingo!"); break;
//			}
//			else if (cnt == 2 || cnt == 3) {
//				printf("Lucky You!"); break;
//			}
//			else if (cnt > 3 && cnt <= n) {
//				printf("Good Guess!"); break;
//			}
//			else if (cnt > n) {
//				printf("Game Over"); break;
//			}
//		}
//		else if (inp > number) {
//			printf("Too big\n");
//		}
//		else if (inp < number) {
//			printf("Too small\n");
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	int key, n,i,text;
//	scanf("%d %d", &key, &n);
//	if (n > 3)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d", &text);
//			if (text < key)
//			{
//				
//			}
//			else if (text > key)
//			{
//
//			}
//			else(text = key)
//			{
//
//			}
//		}
//	}
//}
//int main()
//{
//	double eps, i, fu, a=1;
//	double sum = 0;
//	scanf("%lf", &eps);
//	for (i = 1; a >= eps; i += 3);
//	{
//		a = 1 / i;
//		fu = pow(-1, (i+5)/3);
//		sum = sum + fu *a;
//		printf("shoudao");
//	}
//	printf("sum = %lf", sum);
//}
//int main()
//{
//	int n,i,score,s;
//	int countA=0, countB=0, countC=0, countD=0, countE=0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		scanf("%d", &score);
//		s = score / 10;
//		switch (s)
//		{
//		case(10):
//		case(9):
//			countA = countA + 1;
//			break;
//		case(8):
//			countB = countB + 1;
//			break;
//		case(7):
//			countC = countC + 1;
//			break;
//		case(6):
//			countD = countD + 1;
//			break;
//		default:
//			countE = countE + 1;
//			break;
//		}
//	}
//	printf("%d %d %d %d %d", countA, countB, countC, countD, countE);
//}

//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	printf("ss");
//}

//int main()
//{
//	double min, max;
//	double low, fahr, celsius;
//	scanf("%lf %lf", &min, &max);
//	if (min > max || max > 100)
//	{
//		printf("Invalid.");
//	}
//	else
//	{
//		printf("fahr celsius\n");
//		for (low = min; low <= max; low += 2)
//		{
//			fahr = low;
//			celsius = 5 * (fahr - 32) / 9;
//			printf("%.0f   %.1f\n", fahr, celsius);
//		}
//	}
//
//}

//int main()
//{
//	int i, n, count = 0;
//	double average = 0, sum = 0, score;
//	scanf("%d", &n);
//	if (n > 0)
//	{
//		for (i = 0; i < n; i++)
//		{
//			scanf("%lf", &score);
//			if (score >= 60)
//			{
//				count++;
//			}
//			sum += score;
//		}
//		average = sum / n;
//		printf("average = %.1f\ncount = %d\n", average, count);
//	}
//	else
//	{
//		printf("average = 0.0\ncount = 0\n");//要考虑人数不大于0的情况
//	}
//
//}

//int main()
//{
//	int n, i, count = 0;
//	double sum = 0, average, score;
//	scanf("%d", &n);
//	if (n > 0)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			scanf("%d ", &score);
//			sum = sum + score;
//			if (score >= 60)
//			{
//				count = count + 1;
//			}
//
//		}
//		average = sum / n;
//		printf("average = &.1f/n", average);
//		printf("count = &d", count);
//	}
//	return 0;
//}