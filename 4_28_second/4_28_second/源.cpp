#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;

int main()
{
	int day;
	cin >> day;
	int peach = 1;
	for (int i = 1; i <= day-1; i++)
	{
		peach = (peach + 1) * 2;
	}
	cout << peach;
	return 0;
}