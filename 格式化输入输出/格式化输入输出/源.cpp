#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num;  //����Ϊ1234
	int i1 = scanf("%i", &num);  //������ַ���
	int i2 = printf("%d\n", num);  //���ض������Ŀ��
	printf("%d:%d\n", i1, i2);  //1:5   ������ǻس�����
	//int num;
	//scanf("%*d%d", &num);  //*����������������123 456�������Ϊ456
	//printf("%d\n", num);
	//printf("%9d\n", 123);  //9��ʾ�������ռ9���Ҷ���
	//printf("%-9d\n", 123);  //���ű�ʾ�����
	//printf("%09d\n", 123);  //0��ʾ���
	//printf("%-09d\n", 123);
	//printf("%9.2f\n", 123.0); //С����Ҳ��1����С������ռ9��
	//printf("%*d\n", 6, 123);  //*�ű�ʾ�����6��������6Ҳ���Ի���һ�����ʽ
	//printf("%hhd\n", 12345);  //ת����16���ƣ�ȡǰ��λ��ת��Ϊ10����

	return 0;
}