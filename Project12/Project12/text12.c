#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);//数组名就是首元素地址
	printf("%d\n", *arr);//首元素地址再首元素
	int sz = sizeof(arr) / sizeof(arr[0]);
	//两个例外，数组名不一定是首元素地址（上
	//2.&数组名，数组名代表整个数组，&数组名，取出的是整个数组的地址（下
	printf("%p\n", &arr);//虽然打印出来是一样的，但是意义不一样，参考下面
	printf("%p\n", arr+1);
	printf("%p\n", &arr[0]+1);
	printf("%p\n", &arr + 1);//加了1，2，3，4，5，6，共24个字节
}


//void bubble_sort(int arr[],int a)
//{
//	int i, j;
//	int tmp;
//	int count = 0;
//	int flag;
//	int sz = a;//sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz-1; i++)//确定冒泡的趟数，9个元素则需要8趟
//	{
//		flag = 1;//假设这一趟已经排好序了
//		for (j = 0; j < sz-1-i; j++)//确定每一趟冒泡交换顺序的次数
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				count++;
//				flag = 0;
//			}
//		}
//		if (flag == 1)//排好序了就不再循环了，count大大减少
//			break;
//	}
//	printf("%d\n", count);
//}
//
//
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,9,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//
//	bubble_sort(arr,sz);//对arr进行排序，排成升序,对arr进行传参，实际传过去的是arr的首元素的地址,函数从首元素的地址往后传
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	int arr[3][4] = { {1,2,3},{4,5} };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("&arr[%d][%d] = %p\n", i,j,&arr[i][j]);//可知二维数组的储存不是3*4，而是连续的一行，与一维数组相同
//		}
//		//printf("\n");//等价于putchar('\n')
//	}
//}


//int main()
//{
//	int arr[3][4] = { {1,2,3},{4,5} };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");//等价于putchar('\n')
//	}
//}


//int main()
//{
//	int arr1[3][4] = { 1,2,3,4,5 };
//	int arr2[3][4] = { {1,2,3},{4,5} };
//	//arr[][] = { 1,2,3,4,5 };错误；
//	//arr[][] = { {1,2,3,4},{5} };也错误
//	int arr3[][4] = { 1,2,3,4,5,6,7,8 };//正确，不能缺少列标
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("&arr[%d] = %p\n", i, &arr[i]);
//	}//地址为%p,地址是16进制，10为a,11为b....
//}


//数组大小可以通过sizeof(arr)/sizeof(arr[0])计算

//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,0 };
//	///int arr2[] = "1234567890"是错误的
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	//int len = strlen(arr1);是错误的，因为strlen只针对字符
//	printf("%d", sz);//整型一个为4字节大小，字符一个为1字节大小
//}


//strlen是求字符串长度的，只能针对字符串求长度
//sizeof计算变量，数组，类型的大小，单位是字节，\0也算一个字节
//int main()
//{
//	char arr1[] = "abc";//放了a b c \0
//	char arr2[] = { 'a','b','c' };//放了a b c
//	printf("%d\n", sizeof(arr1));//4
//	printf("%d\n", sizeof(arr2));//3
//	printf("%d\n", strlen(arr1));//3
//	printf("%d\n", strlen(arr2));//为一个随机数，因为后面不知道什么时候遇到\0
//}

//int main()
//{
//	//char arr1[5] = { 'a','b' };//345元素初始化，为0
//	//putchar('\n');
//	//char arr2[5] = "ab";//第三个元素为\0，45为初始化为0
//	//printf("%s", arr1);
//	//printf("%s", arr2);
//	char arr3[5] = { 'a',98 };//char默认里面为字符，而98没加双引号，为ascll码
//	printf("%s", arr3);
//	putchar('\n');
//	char arr4[] = "abcdef";
//	printf("%d\n", sizeof(arr4));//sizeof计算arr4所占空间大小，7个元素-char=7*1
//	printf("%d\n", strlen(arr4));//strlen求字符串的长度'\0'之前的字符个数
//}


//void test(int n)
//{
//	if(n<10000)
//	{
//		test(n + 1);
//	}
//}
//int main()
//{
//	test(1);
//	return 0;
//}

//int fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	int ret;
//	int n;
//	scanf("%d", &n);
//	ret = fib(n);
//	printf("%d", ret);
//}


//int count = 0;
//int fib(int n)
//{
//	
//	if (n == 3)
//	{
//		count++;
//	}
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = fib(n);
//	printf("ret = %d\n", ret);
//	printf("count = %d", count);
//	return 0;
//}



//int fac1(int n)
//{
//	int ret = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//	}
//	return ret;
//}
//
//
//int fac2(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * fac2(n - 1);
//}
//
//
//int main()
//{
//	int n, ret;
//	scanf("%d", &n);
//	ret = fac2(n);
//	printf("%d", ret);
//	return 0;
//}


//int my_strlen(char* str)
//
//{
//	int count = 0;
//	while(*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "bit";
//	//printf("%d", strlen(arr));
//	int len = my_strlen(arr);//传过去的不是数组，而是首元素的地址
//	printf("%d", len);
//	return 0;
//}

//void print(int n)
//{
//	if (n > 9)
//		print(n / 10);
//	printf("%d ", n % 10);
//}
//
//
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d",&num);
//	print(num);
//	return 0;
//}


/*nt main()
{
	printf("hehe\n");
	main();
	return 0;

}*/

//int main()
//{
//	printf("%d", printf("%d",43/*printf("%d", 43)*/));
//}

//void add(int* p)
//{
//	(*p)++;
//}
//
//int main()
//{
//	int num = 0;
//	add(&num);
//	printf("num = %d\n", num);
//	add(&num);
//	printf("num = %d\n", num);
//	add(&num);
//	printf("num = %d\n", num);
//	return 0;
//}

//int binary_search(int arr[], int k,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while(left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//			right = mid - 1;
//		else
//			return mid;
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k;
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//		printf("找不到指定数字\n");
//	else
//		printf("找到了，指定数字下标为%d\n", ret);
//	return 0;
//
//}

//int is_leap_year(int n)
//{
//	if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//
//int main()
//{
//	int year;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (is_leap_year(year) == 1)
//			printf("%d  ", year);
//
//	}
//	return 0;
//}

//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j < n; j++)
//	{
//		if (n%j == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int i;
//	for (i = 100; i <= 200; i++)
//		if (is_prime(i) == 1)
//			printf("%d  ",i);
//}

//int is_prime(int n)
//{
//	int b = 0;
//	for (int a = 2,int b=0; a < n; a++)
//	{
//		if (n%a == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//			printf("%d  ", i);
//	}
//	return 0;
//}

//void swap(int* pa, int* pb)
//{
//	int tmp=0;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("a=%d b=%d\n", a, b);
//	swap(&a, &b);
//	printf("a=%d b=%d", a, b);
//	return 0;
//}


////int main()
////{
////	int a = 10;
//	int* pa = &a;
//	*pa = 20;
//	printf("%d", a);
//}

//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	printf("%d", *pa);
//}