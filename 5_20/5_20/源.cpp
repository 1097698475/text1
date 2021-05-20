#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

#include<stdio.h>
int main()
{
	int n, arr[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d",&arr[i]);

	int count[1000];
	for (int i = 0; i < n; i++)
		count[i] = 1;  //先初始化每个次数为1
	for (int i = 0; i < n && count[i] != 0; i++)
	{
		int number = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j] && count[j] == 1)
			{
				number ++;
				count[j] = 0;
			}
		}
		count[i] = number;
	}
	int max_number = count[0], max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (max_number < count[i])
		{
			max_number = count[i];
			max = arr[i];
		}
	}
	printf("%d %d", max, max_number);
}

//int fac(int);
//int main()
//{
//	int n;
//	cout << "please input n(n>=0):" << endl;
//	cin >> n;
//	int result = fac(n);
//	cout << "the n! result is " << result;
//	return 0;
//}
//int fac(int n)
//{
//	long fact;
//	if (n == 0 || n == 1)
//		return 1;
//	else
//	{
//		fact = n * fac(n - 1);
//	}
//	return fact;
//}