#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define nmax 100

// 打印数组：
// 1. 可用sizeof,strlen算出数组长度，再for循环打印
// 2. 含空格也可用%s，但是输入时含空格不能用%s
// 3. putchar要for循环，一般针对变量，而不是数组，下面例子为什么错误？
// 4. puts(数组名），与printf(%s)差不多，但这个可以输出含空格的数组  (如下）


//int main()
//{
//	char arr[nmax] = "hello world";
//	puts(arr);
//	return 0;
//}

//int main()
//{
//	char ch;
//	while ((ch = getchar() != '\n'))
//	{
//		putchar(ch);
//	}
//	return 0;
//}

//int main()
//{
//	char* s = "hello";
//	printf("%c", s[1]);
//	//可以运用数组任意元素搞事情，如printf,倒序,   但是数组的元素不是scanf人为得到的，而是事先定义的。
//	return 0;
//}

//int main()  //可以输入含空格的字符串，注意for循环的判断条件，也可以用do,while
//{
//	char name[30];
//	int ifscan;
//	int count = 0;
//	for (int i = 0; name[i-1] != '\n'; i++)
//	{
//		scanf("%c", &name[i]);
//		count++;
//	}
//	scanf("%d", &ifscan);
//	for (int i = 0; i < count - 1; i++)
//	{
//		printf("%c", name[i]);
//	}
//	printf("\n");
//	printf("%d", ifscan);
//}


//int main()
//{
//	int n;
//	scanf("%d", &n);
//	char *arr = (char*)malloc(n * sizeof(char));
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%c", &arr[i]);
//		//指针和数组等价，动态内存申请完，就把*arr看成 arr[n]
//		//可以运用数组任意元素搞事情，如printf,倒序
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//  scanf("%d",&n)
//	char arr[nmax];
//	scanf("%s", arr);   //不能有空格！
//	//可以运用数组任意元素搞事情，如printf,倒序
//	return 0;
//}


//int main()
//{
//	int n;
//  scanf("%d",&n);
//	char arr[nmax];
//	for (int i = 0; i < n; i++)
//		scanf("%c", arr[i]);
//	//可以运用数组任意元素搞事情，如printf,倒序
//}


//int main()
//{
//	char ch;
//	while ((ch = getchar()) != '\n')
//	{
//		printf("%c ", ch);
//		//可以用printf一个一个打印，但是要顺序，不能运用任意元素来排序等
//	}
//	return 0;
//}