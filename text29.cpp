#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define nmax 100

// ��ӡ���飺
// 1. ����sizeof,strlen������鳤�ȣ���forѭ����ӡ
// 2. ���ո�Ҳ����%s����������ʱ���ո�����%s
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

//int main()
//{
//	char* s = "hello";
//	printf("%c", s[1]);
//	//����������������Ԫ�ظ����飬��printf,����,   ���������Ԫ�ز���scanf��Ϊ�õ��ģ��������ȶ���ġ�
//	return 0;
//}

//int main()  //�������뺬�ո���ַ�����ע��forѭ�����ж�������Ҳ������do,while
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