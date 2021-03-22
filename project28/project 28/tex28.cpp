#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define nmax 100

// 打印数组：
// 1. 可用sizeof,strlen算出数组长度，再for循环打印
// 2. 不含空格，直接%s
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

int main()
{
	char* s = "hello";
	printf("%c", s[1]);
	//可以运用数组任意元素搞事情，如printf,倒序,   但是数组的元素不是scanf人为得到的，而是事先定义的。
	return 0;;
}

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


//int main()
//{
//	char text;
//	printf("%d\n", 'a');     // 97
//	printf("%c\n", 'a');     // a
//	/*scanf("%d", &text);
//	printf("a : %d\n", text);     
//	printf("a : %c", text);  */
//	scanf("%c", &text);
//	printf("a : %d\n", text);
//	printf("a : %c\n", text);
//
//	return 0;
//}

//int main()
//{
//	char *p1 = 0;
//	do
//	{
//		scanf("%c", p1++); 
//		printf("%s", p1);
//	} while (*p1 != '\n');
//	//printf("%s", p1);
//	return 0;
//}



//int main()
//{
//	printf("%d", strlen("ab"));
//	return 0;
//}


//int main()
//{
//	char a[] = "I Love 武汉!";
//	printf("字符长度：%d  ,内存中所占字节数：%d", strlen(a), sizeof(a));
//	return 0;
//}

//int main()
//{
//	char arr[32];
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (arr[i] == 1)
//			count++;
//	}
//	printf("%d", count);
//		return 0;
//}

//int main()
//{
//	double limit;
//	scanf("%lf", &limit);
//	double sum = 0;
//	double a, text;
//	
//	for(int i = 1;; i++)
//	{
//		if (i % 2 == 1)
//			a = 1;
//		else
//			a = -1;
//		text = 1.0 / (i * 3 - 2);
//		sum += a * text;
//		if (text <= limit)
//			break;
//	}
//	printf("%.6f", sum);
//	return 0;
//}

//int main()
//{
//	double limit;
//	scanf("%lf", &limit);
//	int i;
//	double front;
//	double sum = 0;
//	for (i = 1;; i++)
//	{
//		i % 2 == 1 ? front = 1 : front = -1;
//		if (1.0 / (i * 3 - 2) <= limit)
//			break;
//		sum += front / (i * 3 - 2);
//	}
//	printf("%.6f", sum);
//	return 0;
//}