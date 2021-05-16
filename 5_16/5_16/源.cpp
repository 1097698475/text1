#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//int main()
//{
//	int count = 0;
//	for (int i = 0, j = 10; i = j = 10; i++, j--)
//		count++;
//	cout << count;
//}

int main()
{
	char cs;
	while ((cs = getchar()) != '\n')
	{
		switch (cs - '3')
		{
		case 0:
		case 1:
			putchar(cs + 4);
		case 2:
			putchar(cs + 4);
			break;
		case 3:
			putchar(cs + 3);
		default:
			putchar(cs + 2);
		}
	}
	return 0;
}

//int main()
//{
//	int m, k = 0, s = 0;
//	for (m = 1; m <= 4; m++)
//	{
//		switch (m % 4)
//		{
//		case 0:
//		case 1:s += m; break;
//		case 2:
//		case 3:s -= m; break;
//		}
//		k += s;
//	}
//	cout << k;
//	return 0;
//}

//void hanoi(int ,char,char,char);
//int main()
//{
//	int n;
//	cout << "please input the number of disks to be move" << endl;
//	cin >> n;
//	//从上到下记成disk 1，2，3......
//	hanoi(n,'A','B','C');
//
//	return 0;
//}
//void hanoi(int n, char a, char b, char c)
//{
//	if (n == 1)
//		cout << "Move disk " << n << ": " << a << "->" << c << endl;
//	else
//	{
//		hanoi(n-1,)
//	}
//}

//int if_rowmax(int arr[5][4],int,int);
//int if_linemin(int arr[5][4],int,int);
//int main()
//{
//	int flag = 0;
//	int arr[5][4];
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (if_rowmax(arr,i,j) && if_linemin(arr,i,j))
//			{
//				cout << "鞍点arr[" << i << "][" << j << "] = " << arr[i][j] << endl;
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 1)
//			break;
//	}
//	if (flag == 0)
//		cout << "没有鞍点" << endl;
//	return 0;
//}
//int if_rowmax(int arr[5][4], int i, int j)
//{
//	int count = 0;
//	for (int x = 0; x < 4; x++)
//	{
//		if (arr[i][j] >= arr[i][x])
//			count++;
//	}
//	if (count == 4)
//		return 1;
//	else
//		return 0;
//}
//int if_linemin(int arr[5][4], int i, int j)
//{
//	int count = 0;
//	for (int x = 0; x < 5; x++)
//	{
//		if (arr[i][j] <= arr[x][j])
//			count++;
//	}
//	if (count == 5)
//		return 1;
//	else
//		return 0;
//}

//int max(int arr[3][4]);
//int main()
//{
//	int arr[3][4];
//	for(int i=0;i<3;i++)
//		for (int j = 0; j < 4; j++)
//			cin >> arr[i][j];
//	cout << "the maximum of array is " << max(arr);
//	return 0;
//}
//int max(int arr[3][4])
//{
//	int max = arr[0][0];
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (max < arr[i][j])
//				max = arr[i][j];
//		}
//	}
//	return max;
//}