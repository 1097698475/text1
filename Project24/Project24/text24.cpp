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

//�����Լ��
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
//	printf("%d��%d�����Լ��Ϊ%d", a, b, t);
//	return 0;
//
//}

//շת����������Լ��
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
//	printf("%d��%d�����Լ��Ϊ%d", a, b, t);
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



//�����ӡһ������ÿһλ����δŪ��
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
//	//Ϊʲôc��-1�� ��Ϊ255��11111111,char����ֻ�а˸�����λ��ת��Ϊ����Ϊ10000001,����-1
//	unsigned c1 = 255;
//	printf("c=%d", c);//��ʱ��Ϊ255���������
//	return 0;
//}


//int main()
//{//char����������һ������-1+1,127+1,-128-1,0-1;
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
//	printf("a=%d,b=%d\n", a, b);//%d��ʾ���ʮ����
//	printf("a=%o,b=%x\n", a, b);//%o��ʾ����˽��ƣ�%x��ʾ���ʮ������
//
//
//	char c = -1;
//	int d = -1;
//	printf("c=%u,d=%u\n", c, d);//%u��ʾ���unsigned int ��ʽ
//
//
//	double e = 1234.56789;
//	printf("%e,%E,%f\n", e, e, e);//%e�ǿ�ѧ������ 1.234567e+03
//
//	printf("%.3f\n,", -0.0049);//���-0.005����ΪС����3λ��Ҫ��������
//
//	printf("%.30f\n", -0.0049);//���-0.0048999999999999999912323145545
//	//�������-0.004900000000000000000000000��ԭ�򣺸���������ɢ�ģ���������������Ǹ���ɢ����double����ɢ�̶ȱ�floatС
//
//
//	printf("%.3f\n", -0.000049);//���-0.000��С�������λ��������Ҳû�����֣�����Ϊ0
//
//	//printf("%lf\n",-12.0/0.0);//���������У���������Ϊ0����������������󣬴����������-inf��������
//	//printf("%lf\n", 12.0/ 0.0);//��ʱ�������inf��������
//	//printf("%lf\n", 0.0 / 0.0);//�����������nan��������
//	//printf("%d\n", 12 / 0);//�������ͣ���������Ϊ0����ʱ��������
//
//
//	float x, y, z;
//	x = 1.345;
//	y = 1.123f;
//	printf("sizeof(x)=%d", sizeof(x));
//	printf("sizeof(y)=%d", sizeof(y));
//	/*while (++a > 0)
//		;
//	printf("int�������������Ϊ%d\n", a );*/
//	return 0;
//}

//int main()
//{
//	char a = 'c';
//	printf("%d\n", a);//�������99
//	printf("%c\n", a);//�����a
//	return 0;
//}

//int main()
//{
//	char c;
//	scanf("%c", &c);//����1
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
	scanf("%d %c", &i, &c);//����12 1��12    1��12a��12     a
	printf("i=%d, c=%d, c='%c'\n", i, c, c);//ǰ�������Ľ����Ϊ12 49 1  ���������Ľ����Ϊ12 97 a
	return 0;
}