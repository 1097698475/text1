#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

#include <stdio.h>
#define MAXN 20

void CountOff(int n, int m, int out[]);

int main()
{
	int out[MAXN], n, m;
	int i;

	scanf("%d %d", &n, &m);
	CountOff(n, m, out);
	for (i = 0; i < n; i++)
		printf("%d ", out[i]);
	printf("\n");

	return 0;
}

/* ��Ĵ��뽫��Ƕ������ */





//#include <stdio.h>
//#define MAXN 10
//
//int ArrayShift(int a[], int n, int m);
//
//int main()
//{
//	int a[MAXN], n, m;
//	int i;
//
//	scanf("%d %d", &n, &m);
//	for (i = 0; i < n; i++) scanf("%d", &a[i]);
//
//	ArrayShift(a, n, m);
//
//	for (i = 0; i < n; i++) {
//		if (i != 0) printf(" ");
//		printf("%d", a[i]);
//	}
//	printf("\n");
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//#include<malloc.h>
//int ArrayShift(int a[], int n, int m)  //n������Ԫ�ظ�����->m
//{
//	/*int *arr;
//	arr = (int*)malloc(n * sizeof(int));*/
//	int tmp[MAXN];
//	int j = 0;
//	if (m >= n)
//		m = m - 6;
//
//	//���m����ֵ��tmp
//	for (int i = n - m; i <= n - 1 ; i++) 
//	{
//		tmp[j++] = a[i];
//	}
//
//	//ǰ�������mλ
//	for (int i = n - 1 - m; i >= 0; i--)
//	{
//		a[i + m] = a[i];
//	}
//
//	//��ǰ��յ�m����tmp����
//	for (int i = 0; i < m; i++)
//		a[i] = tmp[i];
//	return 0;
//}




//#include <stdio.h>
//#define MAXN 10
//
//int search(int list[], int n, int x);
//
//int main()
//{
//	int i, index, n, x;
//	int a[MAXN];
//
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//	scanf("%d", &x);
//	index = search(a, n, x);
//	if (index != -1)
//		printf("index = %d\n", index);
//	else
//		printf("Not found\n");
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//int search(int list[], int n, int x) // list[]Ϊ�û���������飬nΪ����Ԫ�ظ�����xΪ������Ԫ��,������С���±�
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (x == list[i])
//		{
//			return i;
//		}
//	}
//	return -1;
//}





//#include <stdio.h>
//
//void splitfloat(float x, int *intpart, float *fracpart);
//
//int main()
//{
//	float x, fracpart;
//	int intpart;
//
//	scanf("%f", &x);
//	splitfloat(x, &intpart, &fracpart);
//	printf("The integer part is %d\n", intpart);
//	printf("The fractional part is %g\n", fracpart);
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//void splitfloat(float x, int *intpart, float *fracpart) //intpart���������֣�fracpartС������
//{
//	int part1 = (int)x;
//	*intpart = part1;
//	*fracpart = x - part1;
//}



//typedef struct people
//{
//	char name[11];
//	char birth[9];
//	char phone[18];
//}contact;
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	contact arr[10];
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s %s %s", &arr[i]);
//	}
//	for(int i=0;i<n;i++)
//		printf("%s %s %s\n", arr[i]);
//	return 0;
//}


//int main()
//{
//	int i, k, f = 0;
//	char a[80], str[80];
//	long number;
//	i = 0;
//	while ((str[i] = getchar()) != '#')  //����������#��ֹͣ
//		i++;
//	str[i] = '\0';//���һ��б��0������ַ���
//	k = 0;
//	for (i = 1; str[i] != '\0'; i++) 
//	{
//		if (k == 0 && str[i] == '-')
//		{
//			f = 1;
//		}
//		if (str[i] > '0'&&str[i] < '9' || \
//			str[i] >= 'a'&&str[i] <= 'f' || str[i] >= 'A'&&str[i] <= 'F') 
//		{
//			a[k] = str[i];
//			k++;
//		}
//	}
//	a[i] = '\0';
//	number = 0;
//	for (i = 0; a[i] != '\0'; i++) 
//	{
//		if (a[i] >= '0'&&a[i] <= '9')
//			number = number * 16 + a[i] - '0';
//		else if (a[i] >= 'A'&&a[i] <= 'Z') 
//			number = number * 16 + a[i] - 'A' + 10;
//		else if (a[i] >= 'a'&&a[i] <= 'z')
//			number = number * 16 + a[i] - 'a' + 10;
//	}
//	if (number == 0)
//		printf("0");
//	else 
//	{
//		if (f == 0)
//			printf("%d", number);
//		else
//			printf("-%d", number);
//	}
//}



//int main()
//{
//	char a[5][81], tmp[81];
//	for (int i = 0; i < 5; i++)
//		scanf("%s", &a[i]);
//
//	ð������
//	strcmp ǰ��С�ں��ߣ��򷵻ظ���
//	 ��һ��Ԫ����ʣ���ĸ�Ԫ����������ĸС�����һ���ַ�����λ
//	 �ڶ���Ԫ����ʣ������Ԫ�����򣬵����������ĸ����������򣬣�����������ˣ�
//	for (int j = 0; j < 4; j++) //�������j��Ԫ�ؿ�ʼ
//	{
//		for (int i = j + 1; i < 5; i++)  //j=2ʱ��ʾ�������ַ�����ʼ����Ҫ����ʣ������
//		{
//			if (strcmp(a[i],a[j]) < 0)
//			{
//				strcpy(tmp, a[j]);
//				strcpy(a[j], a[i]);
//				strcpy(a[i], tmp);
//			}
//		}
//	}
//	printf("After sorted:\n");
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%s\n", a[i]);
//	}
//	return 0;
//}

//#include<math.h>
//
//int main()
//{
//	double x1, y1, x2, y2;  //(x1,y1) (x2,y2)
//	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
//	double x3 = x1 + x2;
//	double y3 = y1 + y2;
//	
//	//���-0.0��ԭ��-0.03ȡһλС��Ϊ-0.0
//	if (fabs(x3) < 0.05)
//		x3 = 0.0;
//	if (fabs(y3) < 0.05)
//		y3 = 0.0;
//	printf("(%.1f, %.1f)", x3, y3);
//	return 0;
//}



//#include <stdio.h>
//#include <string.h>

//#define MAXS 10
//
//void Shift(char s[]);
//
//void GetString(char s[]); /* ʵ��ϸ���ڴ˲��� */
//
//int main()
//{
//	char s[MAXS];
//
//	GetString(s);
//	Shift(s);
//	printf("%s\n", s);
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//void Shift(char s[])//�������ַ�����ǰ3���ַ��Ƶ����
//{
//	char a[3] = { 0,0,0 };
//
//	//����s[]��ǰ���a[]
//	for (int i = 0; i < 3; i++)
//		a[i] = s[i];
//
//	//s[4]�Ƶ�s[1],5��2  ����s[]����
//	int last;
//	for (int i = 3; i < MAXS; i++)  //ֱ��MAXS 
//	{
//		s[i - 3] = s[i];
//		last = i;
//	}
//
//	//��ǰ��λ���ָ�ֵ��s[i],iΪ��һ�μӵ���ֵ
//	for (int i = last; i < last + 3; i++)
//	{
//		int m = 0;
//		s[last] = a[m];
//		m++;
//	}
//}




//#include <stdio.h>
//
//void sum_diff(float op1, float op2, float *psum, float *pdiff);
//
//int main()
//{
//	float a, b, sum, diff;
//
//	scanf("%f %f", &a, &b);
//	sum_diff(a, b, &sum, &diff);
//	printf("The sum is %.2f\nThe diff is %.2f\n", sum, diff);
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//void sum_diff(float op1, float op2, float *psum, float *pdiff)
//{
//	//sum��op1��op2�ĺͣ�diff�ǲ�
//	//��ָ������Ϊ �������㵽�ĺͲ�ܷ��ص�main(�����ڣ�����Ϊ�������
//	*psum = op1 + op2;
//	*pdiff = op1 - op2;
//
//}





//#include <stdio.h>
//
//int reverse(int number);
//
//int main()
//{
//	int n;
//
//	scanf("%d", &n);
//	printf("%d\n", reverse(n));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//int reverse(int number) //-12340����-4321
//{
//	//������������
//	//ѭ����10,�浽���飬���˳���ӡ�����������
//	int num = number;
//	int flag = 0; // ����Ϊ0������Ϊ1
//	if (num >= 0)
//		flag = 1;
//	int bit[10];
//	int i = 0, nbit = 0;
//	do
//	{
//		bit[i] = num % 10;  //���ĩβ��0��Ҳ�������飬����ӡ��ʱ���ж�bit[0]�Ƿ�Ϊ0
//		num /= 10;
//		i++;
//		nbit++;
//	} while (num > 0);
//	for (i = 0; i < nbit; i++)
//	{
//		int flag0 = 1; //�ж�ĩβ�����Ƿ�Ϊ0����0��flag0=0, 
//		if (i == 0&&bit[i]==0)
//			flag0 = 0;
//
//		if (i == 0 && flag == 0)
//			printf("-");
//	}
//}



//#include <stdio.h>
//#include <math.h>
//
//int prime(int p);
//void Goldbach(int n);
//
//
//
//int main()
//{
//	int m, n, i, cnt;
//
//	scanf("%d %d", &m, &n);
//	if (prime(m) != 0) printf("%d is a prime number\n", m);
//	if (m < 6) m = 6;
//	if (m % 2) m++;
//	cnt = 0;
//	for (i = m; i <= n; i += 2) {
//		Goldbach(i);
//		cnt++;
//		if (cnt % 5) printf(", ");
//		else printf("\n");
//	}
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//int prime(int p)
//{
//	if (p == 1)
//		return 0;
//	if (p == 2)
//		return 1;
//	else
//	{
//		int count = 0;
//		for (int i = 1; i <= p/2+1; i++)
//		{
//			if (p%i == 0)
//				count++;
//		}
//		if (count == 1)
//			return 1;
//		else 
//			return 0;
//	}
//}
//void Goldbach(int n)  //nΪ�ڸ������ż��
//{
//	//2��ʼ����n-2�Ƿ�Ϊ����
//	//for(i=3��++2��ֱ��i<=n/2+1)���ж�i�Ƿ����������ǡ�>�ж�n-i�Ƿ�����
//	//�����ǣ���return break;
//	if (prime(n - 2) == 1)
//	{
//		printf("%d=2+%d", n, n - 2);
//		return;
//	}
//	for (int i = 3; i <= n / 2 + 1; i += 2)
//	{
//		if (prime(i) == 1)
//		{
//			if (prime(n - i) == 1)
//			{
//				printf("%d=%d+%d", n, i, n - i);
//				return;
//			}
//		}
//	}
//}





//#include <stdio.h>
//
//int fib(int n);
//void PrintFN(int m, int n);
//
//int main()
//{
//	int m, n, t;
//
//	scanf("%d %d %d", &m, &n, &t);
//	printf("fib(%d) = %d\n", t, fib(t));
//	PrintFN(m, n);
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//int arr[100] = { 1,1 };
//int fib(int x)
//{
//	if (x == 1)
//		return 1;
//	else if (x == 2)
//		return 1;
//	else
//	{
//		for (int i = 2; i < x; i++)
//		{
//			arr[i] = arr[i - 1] + arr[i - 2];
//		}
//		return arr[x - 1];
//	}
//}
//void PrintFN(int m, int n)
//{
//	//�ȼ��㵽n����������������������
//	//for(i��m��n){while(arr[i]<m) ���Ԫ�ش��ڵĻ���¼i,continue,��һ�α��������i��ʼ
//	int i = 1;
//	while (arr[i] <= n)
//	{
//		//printf("%d ", arr[i]);
//		i++;
//		arr[i] = arr[i - 1] + arr[i - 2];
//	}
//	int begin = 0;
//	i = 0;
//	while (arr[i] <= m)
//	{
//		begin = i;//begin���������ţ���Ҫ��ʾ�ڼ�������������Ҫ+1
//		i++;
//	}
//	//printf("fib(%d) = %d\n", begin+1, fib(begin+1));
//	//printf("%d\n", begin+1);
//	int flag = 1;
//	int count = 1;
//	int flag1 = 1;
//	for (int text = m; text <= n; text++)//��m��ʼ���ж�m�Ƿ���������->�и�ѭ��
//	{
//		int a = begin;//��begin���ֲ���
//		if (text == 1)
//		{
//			printf("1 1");
//			flag = 0;
//			flag1 = 0;
//		}
//		if (text > 1)
//		{
//			do  //�ж�text�Ƿ�����������arr[begin]��ʼ�жϣ�һ��ʼһ��С��
//			{
//				if (arr[a] == text)
//				{
//					if (flag1 == 0)
//						printf(" ");
//					flag1 = 1;
//					if (count == 1)
//						printf("%d", text);
//					else
//						printf(" %d", text);
//					flag = 0;
//					count++;
//					break;
//				}
//				a++;
//			} while (arr[a] <= text);
//		}
//	}
//	if (flag)
//		printf("No Fibonacci number");
//}