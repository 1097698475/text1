#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define nmax 100

// ��ӡ���飺
// 1. ����sizeof,strlen������鳤�ȣ���forѭ����ӡ
// 2. �����ո�ֱ��%s
// 3. putcharҪforѭ����һ����Ա��������������飬��������Ϊʲô����
// 4. puts(������������printf(%s)��࣬���������������ո������  (���£�


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
	//����������������Ԫ�ظ����飬��printf,����,   ���������Ԫ�ز���scanf��Ϊ�õ��ģ��������ȶ���ġ�
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
//		//ָ�������ȼۣ���̬�ڴ������꣬�Ͱ�*arr���� arr[n]
//		//����������������Ԫ�ظ����飬��printf,����
//	}
//	return 0;
//}


//int main()
//{
//	int n;
//  scanf("%d",&n)
//	char arr[nmax];
//	scanf("%s", arr);   //�����пո�
//	//����������������Ԫ�ظ����飬��printf,����
//	return 0;
//}


//int main()
//{
//	int n;
//  scanf("%d",&n);
//	char arr[nmax];
//	for (int i = 0; i < n; i++)
//		scanf("%c", arr[i]);
//	//����������������Ԫ�ظ����飬��printf,����
//}


//int main()
//{
//	char ch;
//	while ((ch = getchar()) != '\n')
//	{
//		printf("%c ", ch);
//		//������printfһ��һ����ӡ������Ҫ˳�򣬲�����������Ԫ���������
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
//	char a[] = "I Love �人!";
//	printf("�ַ����ȣ�%d  ,�ڴ�����ռ�ֽ�����%d", strlen(a), sizeof(a));
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