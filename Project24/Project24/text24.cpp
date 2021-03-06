#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

//int main()
//{
//	char str[] = "abcdef";
//	char* pc = str;
//	printf("%s\n", str);
//	printf("%s\n", *pc);
//
//	return 9;
//}

//void swap(int *a, int *b);
//
//int main()
//{
//	int x = 7, y = 11;
//	printf("%d %d\n", x, y);
//	swap(&x, &y);
//	printf("%d %d\n", x, y);
//
//	return 0;
//}
//void swap(int *a, int *b)
//{
//	int *t = &a;
//	*t = *a, *a = *b, *b = *t;
//}

//求最大公约数
//int main()
//{
//	int a, b, t=1, min;
//	scanf("%d %d", &a, &b);
//	a > b ? min = b : min = a;
//	for (int i = 2; i <= min; i++)
//	{
//		if (a%i == 0)
//			if (b%i == 0)
//				t = i;
//	}
//	printf("%d和%d的最大公约数为%d", a, b, t);
//	return 0;
//
//}

//辗转相除法求最大公约数
//int main()
//{
//	int a, b, t=1, min, max;
//	scanf("%d %d", &a, &b);
//	a < b ? min = a,max=b : min = b,max=a;
//	int origa = a;
//	int origb = b;
//	while (t != 0)
//	{
//		if (max%min == 0)
//			break;
//		t = max % min;
//		max = min;
//		min = t;
//	} 
//	printf("%d和%d的最大公约数为%d", a, b, t);
//	return 0;
//}

//int main()
//{
//	int x = 12345;
//	do
//	{
//		int d = x % 10;
//		printf("%d", d);
//		if (x > 9)
//			printf(" ");
//		x /= 10;
//	} while (x > 0);
//	return 0;
//}



//正序打印一个数的每一位，还未弄懂
//int main()
//{
//	int x = 12345;
//	int cnt = 0;
//	int mask = 1;
//	for (int i = 0; x > 0 ; i++)
//	{
//		cnt++;
//		x /= 10;
//		if(x>9)
//		   mask *= 10;
//		
//	}
//	do
//	{
//		int m = x / mask;
//		printf("%d", m);
//		x %= mask;
//		mask /= 10;
//		if (mask > 9)
//			printf(" ");
//
//	} while (mask > 0);
//	return 0;
//}

//int main()
//{
//	double a, b;
//	/*a = 10.00, b = 20.00;
//	printf("sizeof(a+1.0)=%d", sizeof(a));*/
//
//	char c = 255;
//	int i = 255;
//	printf("c=%d,i=%d", c, i);
//	//为什么c是-1？ 因为255是11111111,char类型只有八个比特位，转换为补码为10000001,代表-1
//	unsigned c1 = 255;
//	printf("c=%d", c);//此时才为255，不算符号
//	return 0;
//}


//int main()
//{//char表达的数看成一个环，-1+1,127+1,-128-1,0-1;
//	char a = 127;
//	char b = 1;
//	char c = -128;
//	printf("127+1=%d\n", a + 1);
//	printf("-128-1=%d", c - b);
//	return 0;
//	
//}

//int main()
//{
//	char a = 012; 
//	int b = 0x12;
//	printf("a=%d,b=%d\n", a, b);//%d表示输出十进制
//	printf("a=%o,b=%x\n", a, b);//%o表示输出八进制，%x表示输出十六进制
//
//
//	char c = -1;
//	int d = -1;
//	printf("c=%u,d=%u\n", c, d);//%u表示输出unsigned int 格式
//
//
//	double e = 1234.56789;
//	printf("%e,%E,%f\n", e, e, e);//%e是科学计数法 1.234567e+03
//
//	printf("%.3f\n,", -0.0049);//输出-0.005，因为小数点3位，要四舍五入
//
//	printf("%.30f\n", -0.0049);//输出-0.0048999999999999999912323145545
//	//不能输出-0.004900000000000000000000000的原因：浮点数是离散的，计算机输出最靠近的那个离散数，double的离散程度比float小
//
//
//	printf("%.3f\n", -0.000049);//输出-0.000，小数点后三位四舍五入也没有数字，所以为0
//
//	//printf("%lf\n",-12.0/0.0);//浮点运算中，除数可以为0，定义了正负无穷大，此事输出的是-inf（负无穷
//	//printf("%lf\n", 12.0/ 0.0);//此时输出的是inf（正无穷
//	//printf("%lf\n", 0.0 / 0.0);//此事输出的是nan（不存在
//	//printf("%d\n", 12 / 0);//对于整型，除数不能为0，此时会编译错误！
//
//
//	float x, y, z;
//	x = 1.345;
//	y = 1.123f;
//	printf("sizeof(x)=%d", sizeof(x));
//	printf("sizeof(y)=%d", sizeof(y));
//	/*while (++a > 0)
//		;
//	printf("int数据类型最大数为%d\n", a );*/
//	return 0;
//}

//int main()
//{
//	char a = 'c';
//	printf("%d\n", a);//输出的是99
//	printf("%c\n", a);//输出的a
//	return 0;
//}

//int main()
//{
//	char c;
//	scanf("%c", &c);//输入1
//	printf("c=%d\n", c);
//	printf("c='%c'\n", c);
//	if (49 == '1')
//		printf("ok\n");
//
//	return 0;
//}

int main()
{
	int i;
	char c;
	scanf("%d %c", &i, &c);//输入12 1或12    1或12a或12     a
	printf("i=%d, c=%d, c='%c'\n", i, c, c);//前面两个的结果都为12 49 1  后面两个的结果都为12 97 a
	return 0;
}