#define _CRT_SECURE_NO_WARNINGS

//#include<iostream>
//#include<iomanip>
//#include<string.h>
//using namespace std;
//
//int main()
//{
//
//	return 0;
//}

//int main()
//{
//	int a[10], b[10];
//	int ateam = 0, bteam = 0;
//	for (int i = 1; i <= 10; i++)
//	{
//		cout << "�����" << i << "�α����ĵ÷֣�" << endl;
//		cout << "A�ӣ�";
//		cin >> a[i];
//		cout << "B�ӣ�";
//		cin >> b[i];
//		if (a[i] > b[i])
//			ateam++;
//		else if (a[i] < b[i])
//			bteam++;
//		else
//			;
//	}
//	if (ateam > bteam)
//		cout << "A�ӻ�ʤ,�ȷ�Ϊ" << ateam << ':' << bteam;
//	else if (ateam == bteam)
//		cout << "ƽ��,�ȷ�Ϊ" << ateam << ':' << bteam;
//	else
//		cout << "B�ӻ�ʤ,�ȷ�Ϊ" << ateam << ':' << bteam;
//	return 0;
//}

//int f(int, int);
//int main()
//{
//	int a, b, h;
//	cin >> a >> b;
//	h = f(a, b);
//	cout << a << "��" << b << "�����Լ��Ϊ" << h << endl;
//	return 0;
//}
//int f(int a, int b)
//{
//	int r;
//	r = a % b;
//	while (r != 0)
//	{
//		a = b;
//		b = r;
//		r = a % b;
//	}
//	return b;
//}

//struct stu
//{
//	char name[5];  //8
//	int age; //4
//	char sex;  //4
//};
//int main()
//{
//	cout << sizeof(stu);
//	return 0;
//}

//int main()
//{
//	char c[3][80], temp[80];
//	int i,j;
//	for (i = 0; i < 3; i++)
//	{
//		gets_s(c[i]);
//	}
//	for (i = 0; i < 2; i++)
//	{
//		for (j = i; j < 3; j++)
//		{
//			if (strcmp(c[i], c[j]) > 0)
//			{
//				strcpy(temp, c[i]);
//				strcpy(c[i], c[j]);
//				strcpy(c[j], temp);
//			}
//		}
//	}
//	for (i = 0; i < 3; i++)
//	{
//		puts(c[i]);
//	}
//	return 0;
//}