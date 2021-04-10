#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define nmax 100
#define nvalues 5

int main()
{
	char arr[nmax];
	char key;
	scanf("%c", &key);
	for (int i = 0;; i++)
	{
		scanf("%c", &arr[i]);
		if (arr[i] = '\n')
			break;
	}
	printf("ss");
}


//int digitsum(int n)
//{
//	if (n > 9)
//	{
//		return digitsum(n / 10) + n % 10;//前面确定次数，后面的n是怎么算？
//	}
//	else
//		return n;
//}
//
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);
//	int ret = digitsum(num);
//	printf("ret = %d\n", ret);
//	return 0;
//}

//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//void reverse_string(char arr[])
//{
//	int left = 0;
//	int right = my_strlen(arr) - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s", arr);
//	return 0;
//}


//void printtable(int n)
//{
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i ; j++)
//		{
//			printf("%d*%d=%-3d", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printtable(n);
//	return 0;
//}

//int fun(int n)
//{
//	if (n == 5)
//		return 2;
//	else
//		return 2 * fun(n + 1);
//}
//int main()
//{
//	int n = 2;
//	int m = fun(n);
//	printf("%d", m);
//}


//int count_bit_one(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//		}
//		n = n / 2;
//	}
//	return count;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int count = count_bit_one(a);
//	printf("count=%d\n", count);
//	return 0;
//}


//int main()
//{
//	int i = -1;
//	if (i > sizeof(i))
//	{
//		printf(">\n");
//		printf("%d", i);
//	}
//	else
//		printf("<\n");
//}


//void init(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left<right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = arr[tmp];
//		left++;
//		right--;
//	}
//}
//void print(int arr[], int sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//init(arr, sz);
//	print(arr, sz);
//	reverse(arr, sz);
//	print(arr, sz);
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* arr[3] = { &a,&b,&c };
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d ", *(arr[i]));
//	}
//}


//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int* * ppa = &pa;   //int**的int*表示ppa指向的类型为int*
//	//int** *pppa = &ppa;
//	printf("%d\n", **ppa);
//}


//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}


//int main()
//{
//	int arr[10];
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0]+1);
//
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);//&数组名 不是数组的首元素地址
//
//}


//int main()
//{
//	float values[nvalues];
//	float* vp;
//	for (vp = &values[nvalues-1]; vp > &values[0];vp--)
//	{
//		*vp = 0;
//	}
//}


//int main()
//{
//	float values[nvalues];
//	float* vp;
//	for (vp = &values[nvalues]; vp > &values[0];)
//	{
//		*--vp = 0;
//		printf("%d\n", *vp);
//	}
//}


//int my_strlen(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - start;
//}
//int main()
//{
//	//strlen 求字符串长度
//	//递归-模拟实现了strlen-计数器的方法1，递归的方法2
//
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = 1;
//	}
//	return 0;
//}

//int main()//可用书上一个函数,看书
//{
//	char key, arr[nmax];
//	int i, index=-2;
//	scanf("%c", &key);
//	for (i = 0; i < strlen(arr); i++)
//	{
//		scanf("%c", &arr[i]);
//	}
//	for (i = 0; i < strlen(arr); i++)
//	{
//		if (arr[i] == key)
//		{
//			index = i;
//		}
//	}
//	if (index == -2)
//	{
//		printf("Not Found");
//	}
//	else
//		printf("index = %d", index);
//	return 0;
//}

//int main()
//{
//	int year, month, day;
//	int monthday, addday=0;
//	scanf("%d/%d/%d", &year, &month, &day);
//	for (int i = 1; i < month; i++)
//	{
//		switch (i)
//		{
//		case 1:
//		case 3:
//		case 5:
//		case 7:
//		case 8:
//		case 10:
//		case 12:
//			monthday = 31;
//			addday = addday + monthday;
//			break;
//		case 4:
//		case 6:
//		case 9:
//		case 11:
//			monthday = 30;
//			addday = addday + monthday;
//			break;
//		case 2:
//			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//			{
//				monthday = 29;
//				addday = addday + monthday;
//			}
//			else
//			{
//				monthday = 28;
//				addday = addday + monthday;
//			}
//			break;
//		}
//	}
//	addday = addday + day;
//	printf("%d", addday);
//	return 0;
//}

//
//int main()
//{
//	int n;
//	int arr[nmax];
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < n - 1; i++)//操作几次
//	{
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			int tmp;
//			tmp = arr[j];
//			arr[j] = arr[j + 1];
//			arr[j + 1] = tmp;
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		printf("%d", arr[i]);
//		if (i < n - 1)
//			printf(" ");
//	}
//}


//int main()
//{
//	int n;
//	int i, j;
//	int arr[nmax][nmax];
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for (i = n - 1, j = 0; j < n; j++)
//	{
//		arr[i][j] = 0;
//	}
//	for (j = n - 1, i = 0; i < n - 1; i++)
//	{
//		arr[i][j] = 0;
//	}
//	for (i = 0,j = n-1; i < n - 1 , j>=0 ; i++ , j--)
//	{
//		arr[i][j] = 0;
//	}
//	int add=0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			add = add + arr[i][j];
//		}
//	}
//	printf("%d", add);
//	return 0;
//}

//int main()
//{
//	int m, n;
//	int i, j;
//	int arr1[nmax][nmax];
//	int arr2[nmax][nmax];
//	scanf("%d %d", &m, &n);
//	for(i=0;i<n;i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &arr1[i][j]);
//		}
//	}
//	//int* p;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			arr2[i][j] = arr1[i][(j + m-1) % n];
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