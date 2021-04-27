#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

//setw(n)函数
//当后面紧跟着的输出字段长度小于 n 的时候，在该字段前面用空格补齐，当输出字段长度大于 n 时，全部整体输出。
//int main()
//{
//
//	return 0;
//}

int main()
{
	int b[4][3];
	int a[3][4] = { {1,2,3,4},{1,2,3,4},{1,2,3,4} };
	cout << "before converting" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			b[j][i] = a[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout.width(3);
			cout << b[i][j];
		}
		cout << endl;
	}
	return 0;
}

//int main()
//{
//	int fib[20];
//	fib[0] = 1;
//	fib[1] = 1;
//	for (int i = 2; i < 20; i++)
//	{
//		fib[i] = fib[i - 1] + fib[i - 2];
//	}
//	for (int i = 0; i < 20; i++)
//	{
//		cout << setw(6) << fib[i];
//	}
//	return 0;
//}

//int main()
//{
//	int i;
//	for (i = 100; i <= 200; i++)
//	{
//		if (i % 3 != 0)
//			continue;
//		cout << i << " ";
//	}
//	return 0;
//}

//int main()
//{
//	int count = 0;
//	for (int i = 1; i <= 600; i++)
//	{
//		int number = i;
//		while(number % 3 == 0)
//		{
//			count++;
//			number /= 3;
//		}
//	}
//	cout << "最高能被9的" << count / 2 << "次方整除";
//	return 0;
//}

//int main()
//{
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			cout << i << "*" << j << "=" << i * j << '\t';
//		}
//		cout << endl;
//	}
//	return 0;
//}

//int main()
//{
//	int number, digit;
//	cout << "请输入一个非负整数: ";
//	cin >> number;
//	cout << number << "的逆序数为: ";
//	do
//	{
//		digit = number % 10;
//		number /= 10;
//		cout << digit;
//	} while (number > 0);
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	int sele, zhang, li, wang, nosele, other;
//	sele = zhang = li = wang = nosele = other = 0;
//	cin >> sele;
//	while (sele != -1)
//	{
//		switch (sele)
//		{
//		case 1:
//			zhang++;
//			break;
//		case 2:
//			li++;
//			break;
//		case 3:
//			wang++;
//			break;
//		case 4:
//			nosele++;
//			break;
//		case 0:
//			other++;
//			break;
//		default:
//			cout << "input error!" << endl;
//			break;
//		}
//		cin >> sele;
//	}
//	cout << "Zhang sele number is " << zhang << endl;
//	cout << "Li sele number is " << li<< endl;
//	cout << "Wang sele number is " << wang << endl;
//	return 0;
//}

//int main()
//{
//	int test;
//	cin >> test;
//	int bit1 = test % 10;
//	test /= 10;
//	int bit2 = test % 10;
//	int bit3 = test /= 10;
//	cout << bit1 << bit2 << bit3;
//	return 0;
//}

//int main()
//{
//	cout << "sizeof int is " << sizeof(int) << ", sizeof float is " << sizeof(float) << ", sizeof double is "
//		<< sizeof(double);
//	return 0;
//}

//int main()
//{
//	int a, b, c, max;
//	cin >> a >> b >> c;
//	if (a > b)
//		max = a;
//	else
//		max = b;
//	if (c > max)
//		max = c;
//	cout << "the max is " << max;
//	return 0;
//}

//int main()
//{
//	float a, b, c;
//	cout << "please input three numbers a,b, and c: ";
//	cin >> a >> b >> c;
//	float x1 = (-b + sqrt(b*b - 4 * a*b)) / (2 * a);
//	float x2 = (-b - sqrt(b*b - 4 * a*b)) / (2 * a);
//	cout << "x1 = " << x1 << endl;
//	cout << "x2 = " << x2 << endl;
//	return 0;
//}

//int main()
//{
//	int a, b, c;
//	cout << "please input three numbers a , b and c" << endl;
//	cin >> a >> b >> c;
//	cout << "a = " << a << '\t' << "b = " << b << '\t' << "c = " << c << endl;
//	cout << "the sum of a , b and c is " << a + b + c << endl;
//	return 0;
//}

//int main()
//{
//	int x = 1;
//	float y = 2.2;
//	double z = 3.3;
//	cout << "x = " << x << ",y = " << y << ",z = " << z;
//	return 0;
//}

//int main()
//{
//	short int a;
//	cout << sizeof(int) << " " << sizeof(a) << "\n " << sizeof(double);
//	return 0;
//}