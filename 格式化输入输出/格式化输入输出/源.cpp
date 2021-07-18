#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num;  //假设为1234
	int i1 = scanf("%i", &num);  //输出的字符数
	int i2 = printf("%d\n", num);  //返回读入的项目数
	printf("%d:%d\n", i1, i2);  //1:5   第五个是回车换行
	//int num;
	//scanf("%*d%d", &num);  //*号是跳过，若输入123 456，则输出为456
	//printf("%d\n", num);
	//printf("%9d\n", 123);  //9表示输出的数占9格，右对齐
	//printf("%-9d\n", 123);  //负号表示左对齐
	//printf("%09d\n", 123);  //0表示填充
	//printf("%-09d\n", 123);
	//printf("%9.2f\n", 123.0); //小数点也算1格，连小数部分占9格
	//printf("%*d\n", 6, 123);  //*号表示后面的6代进来，6也可以换成一个表达式
	//printf("%hhd\n", 12345);  //转化成16进制，取前两位，转化为10进制

	return 0;
}