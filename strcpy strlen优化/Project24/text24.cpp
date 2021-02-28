#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

int my_strlen(const char* str)
{
	int count = 0;
	assert(str != '\0');
	while (*str!='\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char arr[] = { "abcdef" };
	int len = my_strlen(arr);
	printf("%d", len);
	return 0;
}

//实现strcpy函数

//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest!=NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	//把src指向的字符串拷贝到dest指向的空间，包含\0字符
//	while (*dest++ = *src++)
//	{	
//		;
//	}
//	//*dest = *src;
//	return ret;
//}
//int main()
//{
//	char arr1[] = "############";
//	char arr2[] = "bit";
//	printf("%s", my_strcpy(arr1, arr2));
//	return 0;
//}



//void my_strcpy(char* dest, char* src)
//{
//	while (*src!='\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = *src;
//}
//int main()
//{
//	char arr1[] = { "#############" };
//	char arr2[] = "bit";
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%p\n", arr);
//	printf("%p\n", &i);
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i;
//	for (i = 0; i <= 12; i++)
//	{
//		printf("hehe\n");
//		arr[i] = 0;
//	}
//	return 0;
//}




