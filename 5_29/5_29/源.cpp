#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//理解字符在计算机为数字！！！如ch=100-ch，计算的时候将ch化成数字，然后ch在计算机就变成了新的数字,输出%d为数字，%c为字符
int main()
{
	int i;
	char c;
	scanf("%d %c", &i, &c);//输入12 1或12    1或12a或12     a
	printf("i=%d, c=%d, c='%c'\n", i, c, c);//前面两个的结果都为12 49 1  后面两个的结果都为12 97 a
	return 0;
}

//弄懂！！