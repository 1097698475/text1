#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

#include <stdio.h>

void dectobin(int n);

int main()
{
	int n;

	scanf("%d", &n);
	dectobin(n);

	return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
void dectobin(int n)// ��������nת��Ϊ�����ƺ����
{

}


//#include <stdio.h>
//
//int f(int n);
//
//int main()
//{
//	int n;
//
//	scanf("%d", &n);
//	printf("%d\n", f(n));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//int f(int n)  //��һ쳲�������Ϊ1
//{
//	int x;
//	int sum = 1;
//	if (n == 1)
//		return sum;
//	if (n == 2)
//		return sum;
//	if (n >= 3)
//	{
//		return  f(n - 1) + f(n - 2);
//	}
//}





//#include <stdio.h>
//
//int Ack(int m, int n);
//
//int main()
//{
//	int m, n;
//
//	scanf("%d %d", &m, &n);
//	printf("%d\n", Ack(m, n));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//int Ack(int m, int n)
//{
//	if (m == 0)
//		return n + 1;
//	if (n == 0 && m > 0)
//	{
//		Ack(m - 1, 1);
//	}
//	if (n > 0 && m > 0)
//	{
//		Ack(m - 1, Ack(m, n - 1));
//	}
//
//}



//#include <stdio.h>
//
//double fn(double x, int n);
//
//int main()
//{
//	double x;
//	int n;
//
//	scanf("%lf %d", &x, &n);
//	printf("%.2f\n", fn(x, n));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
////double fn(double x, int n)  //x�ǵ�����n�Ǽӵ���ָ����x-x^2+x^3-x^4
////{
////	
////}
//double fn(double x, int n)
//{
//	//�ȼ���ÿһ�����������ţ�����ѭ������flag��+-�����õݹ������
//	double sum, flag = 1;  //sum����ÿһλ
//	if (n == 1)
//		return x;
//	if (n % 2 == 0)  //ż��Ϊ��
//		flag = -1;
//	sum = x;
//	for (int i = 1; i < n; i++)
//	{
//		sum *= x;  //��������
//	}
//	return flag * sum + fn(x, n-1);
//}


//double fn(double x, int n)
//{
//	double sum = 1, flage = 1, i;
//	if (n == 1)
//		return x;
//	if ((n - 1) % 2 == 0)
//		flage = 1;
//	else flage = -1;
//	for (i = 1; i <= n; i++)
//	{
//		sum *= x;
//	}
//	return flage * sum + fn(x, n - 1);
//}






//#include <stdio.h>
//
//double calc_pow(double x, int n);
//
//int main()
//{
//	double x;
//	int n;
//
//	scanf("%lf %d", &x, &n);
//	printf("%.0f\n", calc_pow(x, n));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */  //����x��n���ݣ�n>=1
//double calc_pow(double x, int n) //����calc_powӦ����x��n���ݵ�ֵ�������õݹ�ʵ��
//{
//	//x=2,n=3,�����2��3����
//	double pow = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		pow *= x;
//	}
//	return pow;
//}





//#include <stdio.h>
//
//double fact(int n);
//double factsum(int n);
//
//int main()
//{
//	int n;
//
//	scanf("%d", &n);
//	printf("fact(%d) = %.0f\n", n, fact(n));
//	printf("sum = %.0f\n", factsum(n));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//double fact(int n)  //n!
//{
//	int result;
//	if (n > 0)
//		result = n * fact(n - 1);
//	else
//		result = 1;
//	return result;
//}//have been tested
//
//double factsum(int n)
//{
//	//ѭ����fact
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int fac = fact(i);
//		sum += fac;
//	}
//	return sum;
//}


//int main()
//{
//	int x;
//	scanf("%d",&x);
//	int y;
//	if (x >= 0)
//		if (x > 0) y = 1;
//		else y = 0;
//	else y = -1;
//	printf("%d", y);
//
//	/*int y = 0;
//	if (x >= 0);
//	if (x > 0) y = 1;
//	else y = -1;
//	printf("%d", y);*/
//}


//#include <stdio.h>
//
//double fact(int n);
//double factsum(int n);
//
//int main()
//{
//	int n;
//
//	scanf("%d", &n);
//	printf("fact(%d) = %.0f\n", n, fact(n));
//	printf("sum = %.0f\n", factsum(n));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//double fact(int n)  //n!
//{
//	int result = 1;
//	if (n > 0)
//		result = n * fact(n - 1);
//	else
//		result = 1;
//	return result;
//}
//double factsum(int n)
//{
//	int result = fact(n);
//	int sum = 0;
//	if (n > 0)
//		sum = result + fact(n - 1);
//	else
//		result = 1;
//	return result;
//}





//#include <stdio.h>
//#include <math.h>
//
//int search(int n);
//
//int main()
//{
//	int number;
//
//	scanf("%d", &number);
//	printf("count=%d\n", search(number));
//
//	return 0;
//}
//
//
///* ��Ĵ��뽫��Ƕ������ */
////ͳ�Ƹ��������ڵ���λ��������λ������ͬ����ȫƽ��������144��676���ĸ���
//int search(int n)  //101~n,������������������ĸ���
//{
//	//����11^2��31^2����
//	int perfect[21];  //101~999��21����ȫƽ����
//	int object[21];   //101~999������������ȫƽ����
//	int ojcount = 0;  //���������ĸ���
//
//	for (int i = 0; i <= 20; i++)  //21��ѭ��
//	{
//		perfect[i] = pow(11 + i, 2);  //����ȫƽ��������perfect����
//		int a = perfect[i];   //���ı��������ȫƽ����
//		int bit[3] = { 0 };  //��ÿһλ��������bit�У�
//
//		//��i��Ԫ�ص�ÿһλ���ֶ�����bit����
//		for (int j = 0; j < 3; j++)
//		{
//			bit[j] = a % 10;
//			a /= 10;
//		}
//		if (bit[0] == bit[1] || bit[1] == bit[2] || bit[0] == bit[2])
//		{
//			object[ojcount] = perfect[i];  //��������������ȫƽ�����浽object
//			ojcount++;
//		}
//	}
//	
//	//i = 101~n��object����Ԫ�رȽϣ�i����object��count+1
//	int count = 0;
//	for (int i = 101; i <= n; i++)
//	{
//		for (int j = 0; j < ojcount; j++)
//		{
//			if (i == object[j])
//				count++;
//		}
//	}
//	return count;
//}


//#include <stdio.h>

//int sum(int n);
//
//int main()
//{
//	int n;
//
//	scanf("%d", &n);
//	printf("%d\n", sum(n));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//int sum(int n)//�ú������ڴ����������n����1+2+3+��+n�ĺ�,��n�����������򷵻�0
//{
//	int result = 0;
//	if (n > 0)
//		result = n + sum(n - 1); //�ݹ��1��ֱ��n����1��
//	else
//		result = 0; //Ҫ�����������������0��
//	return result;
//}





//int main()
//{
//	int x = 4;
//	int y;
//	if (x < 0)
//		y = -1;
//	else if (x = 0)
//		y = 0;
//	else
//		y = 1;
//	printf("%d", x);
//	return 0;
//}